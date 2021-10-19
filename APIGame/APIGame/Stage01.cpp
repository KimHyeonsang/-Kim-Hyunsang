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
	// ** �÷��̾ ������Ʈ�Ŵ������� �޾ƿ´�.
	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();

	// ** �Ѿ��� ������Ʈ �Ŵ������� �޾ƿ´�.
	BulletList = ObjectManager::GetInstance()->GetBulletList();

	// ** ��ź�� ������Ʈ �Ŵ������� �޾ƿ´�.
	BoombList = ObjectManager::GetInstance()->GetBoombtList();

	// ** ������ ������Ʈ �޴������� �޾ƿ´�.
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

	//���� ����
	CurrentNumber = 0;
	// �ʵ� �ִ��
	FieldNumber = 10;

	Time = GetTickCount64();
	InvincibilityTime = GetTickCount64();
}

void Stage01::Update()
{
	m_pPlayer->Update();

	m_pBoombUi->Update();
	// ** ����Ʈ
	if (m_pEffect->GetActive())
		m_pEffect->Update();

	// �Ѿ� �� ��
	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end();)
	{
		int iResult = (*iter)->Update();

		if ((*iter)->GetBulletID() == BULLETID::PLAYER)
		{
			// ** Enemy ����Ʈ�� progress
			for (vector<Object*>::iterator iter2 = EnemyList->begin();
				iter2 != EnemyList->end(); )
			{
				// ** �浹 ó��
				if (CollisionManager::RectCollision((*iter), (*iter2)))
				{
					// GetID���� ���� �ϰ��
					if ((*iter2)->GetEnemyID() == ENEMYID::BOSS)
					{
						if ((*iter2)->GetHart() <= 0)
						{
							// ** ���� ����
							iter2 = EnemyList->erase(iter2);
						}
						else
						{
							// ** ü�°���
							(*iter2)->HartHit((*iter)->GetDamage());
							iResult = 1;
						}
					}
					else
					{
						// ** ���� ����
						iter2 = EnemyList->erase(iter2);
			
						// ** ������ ������Ʈ�� �����ѵ�
						iResult = 1;
						
					}					
					// ** ���� �ݺ����� Ż��.
					break;
					//** break �� �ȵǸ� �Ѿ��� ������ ���������� �浹ü�� �������϶� ��� �浹�� ������.
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
		//		// ĳ���� ��� �Ҹ�
				if (InvincibilityTime + 1000 < GetTickCount64())
				{
					//		((Player*)m_pPlayer)->LoseHart();
					InvincibilityTime = GetTickCount64();
				}
			}
		}

		// ** �Ѿ��� �����ϴ� ����.
		if (iResult == 1)
			iter = BulletList->erase(iter);
		else
			++iter;
	}

	// ��ź �� �� (�Ѿ�)
	for (vector<Object*>::iterator iter = BoombList->begin();
		iter != BoombList->end();)
	{
		int iResult = (*iter)->Update();

		// ** Enemy ����Ʈ�� progress
		for (vector<Object*>::iterator iter2 = EnemyList->begin();
			iter2 != EnemyList->end(); )
		{
			// ** �浹 ó��
			if (CollisionManager::RectCollision((*iter), (*iter2)))
			{
				if ((*iter2)->GetEnemyID() == ENEMYID::BOSS)
				{
					if ((*iter2)->GetHart() <= 0)
					{
						// ** ���� ����
						iter2 = EnemyList->erase(iter2);
					}
					else
					{						
						iResult = 1;
					}
				}
				else
				{
					// ** ���� ����
					iter2 = EnemyList->erase(iter2);
					// ** ������ ������Ʈ�� �����ѵ�
					iResult = 1;
				}
				// ** ���� �ݺ����� Ż��.
				break;
			}
			else
				++iter2;
		}

		// ** ��ź�� �����ϴ� ����.
		if (iResult == 1)
		{
			// ��ź�� ������ ���⼭ �ѹ��� �ݺ� ���� �Ѿ� �ݺ�		
			m_pEffect->Initialize();
			m_pEffect->SetActive(true);
			m_pEffect->SetPosition(((Boomb*)(*iter))->GetPosition());

			//�浹 �����ȿ� �ִ� ���� ��� �Ѿ� ����
			for (vector<Object*>::iterator iter2 = EnemyList->begin();
				iter2 != EnemyList->end(); )
			{
				// ** �浹 ó��
				if (CollisionManager::Collision(m_pEffect, (*iter2)))
				{
					if ((*iter2)->GetEnemyID() == ENEMYID::BOSS)
					{
						if ((*iter2)->GetHart() <= 0)
						{
							// ** ���� ����
							iter2 = EnemyList->erase(iter2);
						}
						else
						{
							// ** ü�°���
							(*iter2)->HartHit((*iter)->GetDamage());
						}
					}
					else
					{
						// ** ���� ����
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
					// ** �Ѿ� ����
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

	// �� �� ĳ����
	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end();)
	{
		int iResult = (*iter)->Update();

		// ������ ���
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
		// �Ϲ����ϰ��
		else
		{
			if (CollisionManager::RectCollision(m_pPlayer, (*iter)))
			{
				iResult = 1;
				// ĳ���� ��� �Ҹ�
				if (InvincibilityTime + 1000 < GetTickCount64())
				{
					((Player*)m_pPlayer)->LoseHart();
					InvincibilityTime = GetTickCount64();
				}
			}
		}	
		

		// ���� ����
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
	

	// ** �÷��̾� ����� ���� ��� Menuȭ������ �̵�
	if (m_pPlayer->GetHart() <= 0)
	{
		// �÷��̾� �ʱ�ȭ
		m_pPlayer->Initialize();
		// �޴��� �̵�
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);

	}
}

void Stage01::Render(HDC _hdc)
{
	// ** ���
	LogoBack->Render(ImageList["Buffer"]->GetMemDC());

	// ** �Ѿ�
	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

	// ** ��ź
	for (vector<Object*>::iterator iter = BoombList->begin();
		iter != BoombList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

	// ** ��
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
	// ����Ʈ
	if (m_pEffect->GetActive())
		m_pEffect->Render(ImageList["Buffer"]->GetMemDC());

	// ĳ����
	m_pPlayer->Render(ImageList["Buffer"]->GetMemDC());
	
	// ** ü�� ui
	m_pHart->Render(ImageList["Buffer"]->GetMemDC());

	// ** ��ź ���� ui
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
