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

Stage01::Stage01()
{

}

Stage01::~Stage01()
{
	Release();
}

void Stage01::Initalize()
{
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

	ImageList = Object::GetImageList();
	
	Vector3 Center = Vector3(WindowsWidth / 2.0f, WindowsHeight / 2.0f);

	for (CurrentNumber = 0; CurrentNumber < ENEMYMAX; ++CurrentNumber)
	{
//		if (CurrentNumber < ENEMYMAX - 40)
			EnemyList->push_back(CreateEnemy<BaseEnemy>());
//		else
//			EnemyList->push_back(CreateEnemy<Bomber>());
	}

	//현재 적수
	CurrentNumber = 0;
	// 필드 최대수
	FieldNumber = 10;

	Time = GetTickCount64();
}

void Stage01::Update()
{
	m_pPlayer->Update();

	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end();)
	{
		int iResult = (*iter)->Update();

		if ((*iter)->GetBulletID() == BULLETID::ENEMY)
		{
			if (CollisionManager::RectCollision(m_pPlayer, (*iter)))
			{
				iResult = 1;
				// 캐릭터 목숨 소모
				((Player*)m_pPlayer)->LoseHart();
			}
		}
		// ** 총알을 삭제하는 구간.
		if (iResult == 1)
			iter = BulletList->erase(iter);
		else
			++iter;
	}
	// 총알 update
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
					// ** 몬스터 삭제
					iter2 = EnemyList->erase(iter2);

					// ** 삭제할 오브젝트로 지정한뒤
					iResult = 1;

					// ** 현재 반복문을 탈출.
					// ** 이유 : 총알 1개에 오브젝 1개를 삭제하기 위함. 
					break;

					//** break 가 안되면 총알이 생성된 시점에에서 충돌체가 여러개일때 모두 충돌후 삭제됨.
				}
				else
					++iter2;
			}
		}		

		// ** 총알을 삭제하는 구간.
		if (iResult == 1)
			iter = BulletList->erase(iter);
		else
			++iter;
	}

	// 폭탄 
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
				// ** 몬스터 삭제
				iter2 = EnemyList->erase(iter2);

				// ** 삭제할 오브젝트로 지정한뒤
				iResult = 1;

				// ** 현재 반복문을 탈출.
				// ** 이유 : 총알 1개에 오브젝 1개를 삭제하기 위함. 
				break;

				//** break 가 안되면 총알이 생성된 시점에에서 충돌체가 여러개일때 모두 충돌후 삭제됨.
			}
			else
				++iter2;
		}

		// ** 총알을 삭제하는 구간.
		if (iResult == 1)
			iter = BoombList->erase(iter);
		else
			++iter;
	}

	// 적 	
	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end();)
	{
		int iResult = (*iter)->Update();

		// 캐릭터와 충돌할 경우
		if (CollisionManager::RectCollision(m_pPlayer, (*iter)))
		{
			iResult = 1;
			// 캐릭터 목숨 소모
			((Player*)m_pPlayer)->LoseHart();
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

	// 캐릭터
	m_pPlayer->Render(ImageList["Buffer"]->GetMemDC());

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
		float(rand() % (WindowsWidth - 120) + 60),0,pBridge);

	return pEnemy;
}
