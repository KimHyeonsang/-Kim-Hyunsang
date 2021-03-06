#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "Player.h"
#include "EnemyHole.h"
#include "HammerEffect.h"
#include "ObjectFactory.h"
#include "CollisionManager.h"
#include "Stage_Back.h"

#include"EnemyBoss.h"
#include"Enemy.h"

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


	m_pEffect = new HammerEffect;
	m_pEffect->Initialize();

	TileHeightCnt = 4;
	TileWidthCnt = 4;
	/*
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
	*/
	
	
	Vector3 Center = Vector3(WindowsWidth / 2.0f, WindowsHeight / 2.0f);

	// ** 적 생성
	for (int y = 0; y < TileHeightCnt; ++y)
	{
		for (int x = 0; x < TileWidthCnt; ++x)
		{
			Object* pObj = new EnemyHole;
			pObj->Initialize();

			pObj->SetPosition(
				Center.x - ((TileWidthCnt / 2) * pObj->GetScale().x) + pObj->GetScale().x * x
				, Center.y - ((TileHeightCnt / 2) * pObj->GetScale().y) + pObj->GetScale().y * y);

			EnemyList->push_back(pObj);

			// 두더지
			EnemyList->push_back(CreateEnemy<EnemyBoss>(Center.x - ((TileWidthCnt / 2) * pObj->GetScale().x) + pObj->GetScale().x * x
				, Center.y - ((TileHeightCnt / 2) * pObj->GetScale().y) + pObj->GetScale().y * y));
		}
	}

	ImageList = Object::GetImageList();
}

void Stage::Update()
{
	m_pPlayer->Update();

	if (m_pEffect->GetActive())
		m_pEffect->Update();

	if (((Player*)m_pPlayer)->GetSwing())
	{
		m_pEffect->SetActive(true);
		m_pEffect->Initialize();
	}

	/*
	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); )
	{
		int Result = (*iter)->Update();

		if (CollisionManager::EllipseCollision(
			m_pPlayer->GetColliderTransform(),
			(*iter)->GetColliderTransform()))
		{
			if (((Player*)m_pPlayer)->GetSwing())
				Result = 1;
		}

		if (Result == 1)
			iter = EnemyList->erase(iter);
		else
			++iter;
	}
	*/

	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); ++iter)
		(*iter)->Update();



	// ** 총알 리스트의 progress
	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); )
	{
		// ** 총알이 화면 밖을 넘어가게 되면 reutrn 1 을 반환 하고, 
		// ** iResult == 1이면 총알은 삭제됨.
		int iResult = (*iter)->Update();

		// ** Enemy 리스트의 progress
		for (vector<Object*>::iterator iter2 = EnemyList->begin();
			iter2 != EnemyList->end(); )
		{
			// ** 충돌 처리
			if (CollisionManager::EllipseCollision((*iter), (*iter2)))
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
			iter = BulletList->erase(iter);
		else
			++iter;
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


	if (m_pEffect->GetActive())
		m_pEffect->Render(ImageList["Buffer"]->GetMemDC());


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

template<typename T>
Object* Stage::CreateEnemy(int _x, int _y)
{
	Bridge* pBridge = new T;

	Object* pEnemy = ObjectFactory<Enemy>::CreateObject(_x,_y, pBridge);

	return pEnemy;
}