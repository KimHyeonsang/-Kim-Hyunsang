#include "Stage01.h"
#include"SceneManager.h"
#include"ObjectManager.h"
#include"ObjectFactory.h"
#include"Player.h"
#include"Logo_Back.h"
#include"Enemy.h"
#include"Boss.h"
#include"BaseEnemy.h"

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

	for (int i = 0; i < 70; ++i)
	{
		//if()
		EnemyList->push_back(CreateEnemy<BaseEnemy>());
	}
}

void Stage01::Update()
{
	m_pPlayer->Update();


	// �Ѿ� update
	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end();)
	{
		int iResult = (*iter)->Update();

		// ** �Ѿ��� �����ϴ� ����.
		if (iResult == 1)
			iter = BulletList->erase(iter);
		else
			++iter;
	}

	// ��ź update
	for (vector<Object*>::iterator iter = BoombList->begin();
		iter != BoombList->end();)
	{
		int iResult = (*iter)->Update();

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

	
			++iter;
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
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

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
}


template<typename T>
inline Object* Stage01::CreateEnemy()
{
	Bridge* pBridge = new T;

	Object* pEnemy = ObjectFactory<Enemy>::CreateObject(
		float(rand() % (WindowsWidth - 120) + 60),0,pBridge);

	return pEnemy;
}
