#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectFactory.h"
#include "CollisionManager.h"
#include "Stage_Back.h"


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

	// ** 오브젝트 매니저에서 총알 리스트를 받아옴. (포인터로...)
	BulletList = ObjectManager::GetInstance()->GetBulletList();

	// ** 오브젝트 매니저에서 몬스터 리스트를 받아옴. (포인터로...)
	EnemyList = ObjectManager::GetInstance()->GetEnemyList();
	
	State_Back = new Stage_Back;
	State_Back->Initialize();


	// ** 적 생성
	for (int i = 0; i < 8; ++i)
	{
		Object* pObj = new Enemy;
		pObj->Initialize();

		Vector3 RandomPos = Vector3(
			float(rand() % (WindowsWidth - 120) + 60),
			float(rand() % (WindowsHeight - 120) + 60));

		pObj->SetPosition(RandomPos.x, RandomPos.y);
		pObj->SetColliderPosition(RandomPos.x, RandomPos.y);

		EnemyList->push_back(pObj);
	}

	ImageList = Object::GetImageList();
}

void Stage::Update()
{
	m_pPlayer->Update();
	
	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); )
	{
		int Result = (*iter)->Update();

		if (Result == 1)
			iter = EnemyList->erase(iter);
		else
			++iter;
	}

	// ** Enemy 리스트의 progress
	for (vector<Object*>::iterator iter2 = EnemyList->begin();
		iter2 != EnemyList->end(); )
	{
		if (((Player*)m_pPlayer)->GetFrame() == 1)
		{					
			// ** 충돌 처리
			if (CollisionManager::RectCollision(m_pPlayer->GetCollider(), (*iter2)->GetCollider()))
			{
				// ** 몬스터 삭제
				iter2 = EnemyList->erase(iter2);
				break;
			}
			else
				++iter2;
		}
		else
			++iter2;
	}
}

void Stage::Render(HDC _hdc)
{
	State_Back->Render(ImageList["Buffer"]->GetMemDC());

	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

	m_pPlayer->Render(ImageList["Buffer"]->GetMemDC());

	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0, 
		SRCCOPY);
}

void Stage::Release()
{

}
