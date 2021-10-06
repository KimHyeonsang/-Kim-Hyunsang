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

	ImageList = Object::GetImageList();
	
	Vector3 Center = Vector3(WindowsWidth / 2.0f, WindowsHeight / 2.0f);

	for (CurrentNumber = 0; CurrentNumber < ENEMYMAX; ++CurrentNumber)
	{
//		if (CurrentNumber < ENEMYMAX - 40)
			EnemyList->push_back(CreateEnemy<BaseEnemy>());
//		else
//			EnemyList->push_back(CreateEnemy<Bomber>());
	}

	//���� ����
	CurrentNumber = 0;
	// �ʵ� �ִ��
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
				// ĳ���� ��� �Ҹ�
				((Player*)m_pPlayer)->LoseHart();
			}
		}
		// ** �Ѿ��� �����ϴ� ����.
		if (iResult == 1)
			iter = BulletList->erase(iter);
		else
			++iter;
	}
	// �Ѿ� update
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
					// ** ���� ����
					iter2 = EnemyList->erase(iter2);

					// ** ������ ������Ʈ�� �����ѵ�
					iResult = 1;

					// ** ���� �ݺ����� Ż��.
					// ** ���� : �Ѿ� 1���� ������ 1���� �����ϱ� ����. 
					break;

					//** break �� �ȵǸ� �Ѿ��� ������ ���������� �浹ü�� �������϶� ��� �浹�� ������.
				}
				else
					++iter2;
			}
		}		

		// ** �Ѿ��� �����ϴ� ����.
		if (iResult == 1)
			iter = BulletList->erase(iter);
		else
			++iter;
	}

	// ��ź 
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
				// ** ���� ����
				iter2 = EnemyList->erase(iter2);

				// ** ������ ������Ʈ�� �����ѵ�
				iResult = 1;

				// ** ���� �ݺ����� Ż��.
				// ** ���� : �Ѿ� 1���� ������ 1���� �����ϱ� ����. 
				break;

				//** break �� �ȵǸ� �Ѿ��� ������ ���������� �浹ü�� �������϶� ��� �浹�� ������.
			}
			else
				++iter2;
		}

		// ** �Ѿ��� �����ϴ� ����.
		if (iResult == 1)
			iter = BoombList->erase(iter);
		else
			++iter;
	}

	// �� 	
	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end();)
	{
		int iResult = (*iter)->Update();

		// ĳ���Ϳ� �浹�� ���
		if (CollisionManager::RectCollision(m_pPlayer, (*iter)))
		{
			iResult = 1;
			// ĳ���� ��� �Ҹ�
			((Player*)m_pPlayer)->LoseHart();
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

	// ĳ����
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
