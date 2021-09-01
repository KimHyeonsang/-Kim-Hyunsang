#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectFactory.h"
#include"CollisionManager.h"

Stage::Stage() : m_pPlayer(nullptr)
{

}

Stage::~Stage()
{
	Release();
}

void Stage::Initialize()
{
	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();

	for (int i = 0; i < 8; ++i)
	{
		Object* pObj = new Enemy;
		pObj->Initialize();

		pObj->SetPosition(
			rand() % (WindowsWidth - 120) + 60,
			rand() % (WindowsHeight - 120) + 60);

		EnemyList.push_back(pObj);
	}




//	EnableList = ObjectManager::GetInstance()->GetEnableList();
//	DisableList = ObjectManager::GetInstance()->GetDisableList();

//	SetTime =ULONGLONG(rand() % 5000 + 3000);
//	Time = GetTickCount64();
}
//disable로 들어가야한다
void Stage::Update()
{
	m_pPlayer->Update();

	// 적들과 캐릭터 충돌
	for (vector<Object*>::iterator iter = EnemyList.begin();
		iter != EnemyList.end();)
	{
		if (CollisionManager::EllipseCollision(m_pPlayer, (*iter)))
		{
			iter = EnemyList.erase(iter);
		}
		else
			++iter;		
	}


	/*
	for (list<Object*>::iterator iter = EnableList->begin();
		iter != EnableList->end(); )
	{
		int Result = (*iter)->Update();

		if (Result == 1)
		{
			
			//DisableList에 저장				
 			ObjectManager::GetInstance()->RecallObject((*iter));
			iter = EnableList->erase(iter);

			//처음에 disableList가 없으면

			//EnableList를 disableList에 넣고 지우기
		}
		else
				++iter;
	}

	if (Time + SetTime < GetTickCount64())
	{
		for (int i = 0; i < 6; ++i)
		{
			Vector3 vPos = Vector3(float(WindowsWidth - 100), float(i * 110 + 50));
			ObjectManager::GetInstance()->FindObject("Enemy", vPos);
		}
		SetTime = rand() % 5000 + 3000;
		Time = GetTickCount64();
	}
	*/
}

void Stage::Render(HDC _hdc)
{
	m_pPlayer->Render(_hdc);

	for (int i = 0; i < EnemyList.size(); ++i)
	{
		EnemyList[i]->Render(_hdc);
	}
/*
	for (list<Object*>::iterator iter = EnableList->begin();
		iter != EnableList->end(); ++iter)
	{
		(*iter)->Render(_hdc);
	}
*/
}

void Stage::Release()
{

}
