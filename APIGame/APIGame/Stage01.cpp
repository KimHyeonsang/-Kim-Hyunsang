#include "Stage01.h"
#include"SceneManager.h"
#include"ObjectManager.h"
#include"ObjectFactory.h"
#include"CollisionManager.h"

#include"Player.h"
#include"Logo_Back.h"
#include"Enemy.h"
#include"Boss.h"
#include"BaseEnemy.h"
#include"Bomber.h"
#include"EnemyBridge.h"
#include"BulletBridge.h"
#include"Boomb.h"
#include"BoomEffect.h"
#include"Hart_Ui.h"
#include"BoombUI.h"

Stage01::Stage01()
{

}

Stage01::~Stage01()
{
	Release();
}

void Stage01::Initalize()
{
	srand(time(NULL));
	// ** 플레이어를 오브젝트매니저에서 받아온다.
	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();

	// ** 총알을 오브젝트 매니저에서 받아온다.
	BulletList = ObjectManager::GetInstance()->GetBulletList();

	// ** 폭탄을 오브젝트 매니저에서 받아온다.
	BoombList = ObjectManager::GetInstance()->GetBoombtList();

	// ** 적군을 오브젝트 메니저에서 받아온다.
	EnemyList = ObjectManager::GetInstance()->GetEnemytList();

	LogoBack = new Logo_Back;
	LogoBack->Initialize();

	m_pHart = new Hart_Ui;
	m_pHart->Initialize();

	m_pBoombUi = new BoombUI;
	m_pBoombUi->Initialize();

	ImageList = Object::GetImageList();
	
	Vector3 Center = Vector3(WindowsWidth / 2.0f, WindowsHeight / 2.0f);

	m_pEffect = new BoomEffect;
	m_pEffect->Initialize();
//	for (CurrentNumber = 0; CurrentNumber < ENEMYMAX; ++CurrentNumber)
//	{
//		if (CurrentNumber < ENEMYMAX - 40)
//			EnemyList->push_back(CreateEnemy<BaseEnemy>());
//		else if(ENEMYMAX - 40 <= CurrentNumber && CurrentNumber < ENEMYMAX - 1)
//			EnemyList->push_back(CreateEnemy<Bomber>());
//		else
			EnemyList->push_back(CreateEnemy<Boss>());
//	}

	//현재 적수
	CurrentNumber = 0;
	// 필드 최대수
	FieldNumber = 10;

	Time = GetTickCount64();
	InvincibilityTime = GetTickCount64();
}

void Stage01::Update()
{
	m_pPlayer->Update();

	m_pBoombUi->Update();
	// ** 이펙트
	if (m_pEffect->GetActive())
		m_pEffect->Update();

	// 총알 과 적
	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end();)
	{
		int iResult = (*iter)->Update();

		if ((*iter)->GetBulletID() == BULLETID::PLAYER)
		{
			// ** Enemy 리스트의 progress
			for (vector<Object*>::iterator iter2 = EnemyList->begin();
				iter2 != EnemyList->end(); )
			{
				// ** 충돌 처리
				if (CollisionManager::RectCollision((*iter), (*iter2)))
				{
					// GetID값이 보스 일경우
					if ((*iter2)->GetEnemyID() == ENEMYID::BOSS)
					{
						if ((*iter2)->GetHart() <= 0)
						{
							// ** 몬스터 삭제
							iter2 = EnemyList->erase(iter2);
						}
						else
						{
							// ** 체력감소
							(*iter2)->HartHit((*iter)->GetDamage());
							iResult = 1;
						}
					}
					else
					{
						// ** 몬스터 삭제
						iter2 = EnemyList->erase(iter2);
			
						// ** 삭제할 오브젝트로 지정한뒤
						iResult = 1;
						
					}					
					// ** 현재 반복문을 탈출.
					break;
					//** break 가 안되면 총알이 생성된 시점에에서 충돌체가 여러개일때 모두 충돌후 삭제됨.
				}
				else
					++iter2;
			}
		}	
		else if ((*iter)->GetBulletID() == BULLETID::ENEMY)
		{
			if (CollisionManager::RectCollision(m_pPlayer, (*iter)))
			{
				iResult = 1;
		//		// 캐릭터 목숨 소모
				if (InvincibilityTime + 1000 < GetTickCount64())
				{
					//		((Player*)m_pPlayer)->LoseHart();
					InvincibilityTime = GetTickCount64();
				}
			}
		}

		// ** 총알을 삭제하는 구간.
		if (iResult == 1)
			iter = BulletList->erase(iter);
		else
			++iter;
	}

	// 폭탄 과 적 (총알)
	for (vector<Object*>::iterator iter = BoombList->begin();
		iter != BoombList->end();)
	{
		int iResult = (*iter)->Update();

		// ** Enemy 리스트의 progress
		for (vector<Object*>::iterator iter2 = EnemyList->begin();
			iter2 != EnemyList->end(); )
		{
			// ** 충돌 처리
			if (CollisionManager::RectCollision((*iter), (*iter2)))
			{
				if ((*iter2)->GetEnemyID() == ENEMYID::BOSS)
				{
					if ((*iter2)->GetHart() <= 0)
					{
						// ** 몬스터 삭제
						iter2 = EnemyList->erase(iter2);
					}
					else
					{						
						iResult = 1;
					}
				}
				else
				{
					// ** 몬스터 삭제
					iter2 = EnemyList->erase(iter2);
					// ** 삭제할 오브젝트로 지정한뒤
					iResult = 1;
				}
				// ** 현재 반복문을 탈출.
				break;
			}
			else
				++iter2;
		}

		// ** 폭탄을 삭제하는 구간.
		if (iResult == 1)
		{
			// 폭탄이 터지면 여기서 한번더 반복 적과 총알 반복		
			m_pEffect->Initialize();
			m_pEffect->SetActive(true);
			m_pEffect->SetPosition(((Boomb*)(*iter))->GetPosition());

			//충돌 범위안에 있는 적과 모든 총알 지움
			for (vector<Object*>::iterator iter2 = EnemyList->begin();
				iter2 != EnemyList->end(); )
			{
				// ** 충돌 처리
				if (CollisionManager::Collision(m_pEffect, (*iter2)))
				{
					if ((*iter2)->GetEnemyID() == ENEMYID::BOSS)
					{
						if ((*iter2)->GetHart() <= 0)
						{
							// ** 몬스터 삭제
							iter2 = EnemyList->erase(iter2);
						}
						else
						{
							// ** 체력감소
							(*iter2)->HartHit((*iter)->GetDamage());
						}
					}
					else
					{
						// ** 몬스터 삭제
						iter2 = EnemyList->erase(iter2);
					}
					break;
				}
				else
					++iter2;
			}

			for (vector<Object*>::iterator iter3 = BulletList->begin();
				iter3 != BulletList->end();)
			{
				if (CollisionManager::Collision(m_pEffect, (*iter3)))
				{
					// ** 총알 삭제
					iter3 = BulletList->erase(iter3);				

				}
				else
					++iter3;
			}
			iter = BoombList->erase(iter);
		}
		else
			++iter;
	}

	// 적 과 캐릭터
	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end();)
	{
		int iResult = (*iter)->Update();

		// 보스일 경우
		if ((*iter)->GetEnemyID() == ENEMYID::BOSS)
		{
			if (CollisionManager::RectCollision(m_pPlayer, (*iter)))
			{
				if (InvincibilityTime + 1000 < GetTickCount64())
				{
					((Player*)m_pPlayer)->LoseHart();
					InvincibilityTime = GetTickCount64();
					break;
				}
			}
		}
		// 일반적일경우
		else
		{
			if (CollisionManager::RectCollision(m_pPlayer, (*iter)))
			{
				iResult = 1;
				// 캐릭터 목숨 소모
				if (InvincibilityTime + 1000 < GetTickCount64())
				{
					((Player*)m_pPlayer)->LoseHart();
					InvincibilityTime = GetTickCount64();
				}
			}
		}	
		

		// 적군 삭제
		if (iResult == 1)
		{
			--CurrentNumber;
			iter = EnemyList->erase(iter);
		}
		else
		{
			++CurrentNumber;
			++iter;

			if (CurrentNumber >= FieldNumber)
			{
				CurrentNumber = 0;
				break;
			}
		}
	}
	

	// ** 플레이어 목숨이 없을 경우 Menu화면으로 이동
	if (m_pPlayer->GetHart() <= 0)
	{
		// 플레이어 초기화
		m_pPlayer->Initialize();
		// 메뉴로 이동
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);

	}
}

void Stage01::Render(HDC _hdc)
{
	// ** 배경
	LogoBack->Render(ImageList["Buffer"]->GetMemDC());

	// ** 총알
	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

	// ** 폭탄
	for (vector<Object*>::iterator iter = BoombList->begin();
		iter != BoombList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

	// ** 적
	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); ++iter)
	{
		++CurrentNumber;
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

		if (CurrentNumber >= FieldNumber)
		{
			CurrentNumber = 0;
			break;
		}
	}
	// 이펙트
	if (m_pEffect->GetActive())
		m_pEffect->Render(ImageList["Buffer"]->GetMemDC());

	// 캐릭터
	m_pPlayer->Render(ImageList["Buffer"]->GetMemDC());
	
	// ** 체력 ui
	m_pHart->Render(ImageList["Buffer"]->GetMemDC());

	// ** 폭탄 갯수 ui
	m_pBoombUi->Render(ImageList["Buffer"]->GetMemDC());

	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Stage01::Release()
{	
	EnemyList->clear();
	EnemyList = nullptr;

	BulletList->clear();
	BulletList = nullptr;
}


template<typename T>
inline Object* Stage01::CreateEnemy()
{
	Bridge* pBridge = new T;	

	Object* pEnemy = ObjectFactory<Enemy>::CreateObject(
		float(rand() % (WindowsWidth - 120) + 120),100,pBridge);

	return pEnemy;
}
