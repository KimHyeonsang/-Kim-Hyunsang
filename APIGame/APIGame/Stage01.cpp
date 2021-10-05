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

	for (int i = 0; i < 70; ++i)
	{
		//if()
		EnemyList->push_back(CreateEnemy<BaseEnemy>());
	}
}

void Stage01::Update()
{
	m_pPlayer->Update();


	// 총알 update
	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end();)
	{
		int iResult = (*iter)->Update();

		// ** 총알을 삭제하는 구간.
		if (iResult == 1)
			iter = BulletList->erase(iter);
		else
			++iter;
	}

	// 폭탄 update
	for (vector<Object*>::iterator iter = BoombList->begin();
		iter != BoombList->end();)
	{
		int iResult = (*iter)->Update();

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

	
			++iter;
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
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

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
}


template<typename T>
inline Object* Stage01::CreateEnemy()
{
	Bridge* pBridge = new T;

	Object* pEnemy = ObjectFactory<Enemy>::CreateObject(
		float(rand() % (WindowsWidth - 120) + 60),0,pBridge);

	return pEnemy;
}
