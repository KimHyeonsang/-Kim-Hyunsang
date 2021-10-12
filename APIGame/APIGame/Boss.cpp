#include "Boss.h"
#include"Object.h"
#include"ObjectManager.h"
#include"EnemyNomalBullet.h"
#include"Bullet.h"
#include"ObjectFactory.h"

Boss::Boss()
{

}

Boss::~Boss()
{
	Release();
}

void Boss::Initialize()
{
	Hart = 100;
	
	Speed = 6.0f;
	
	DrawKey = "Boss";

	ID = ENEMYID::BOSS;

	ImageList = Object::GetImageList();

	EnemyObject->SetScale(200, 100);
	EnemyObject->SetColliderScale(200, 100);

	Pattem1 = GetTickCount64();
	Pattem2 = GetTickCount64();

	BulletList = ObjectManager::GetInstance()->GetBulletList();
}

int Boss::Update(Transform& _rTransInfo)
{

//	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;

	// y축 이동
	if (_rTransInfo.Position.y <= 100)
		_rTransInfo.Position.y += _rTransInfo.Direction.y * 1;

	// 4초마다 공격
	if (Pattem1 + 3000 < GetTickCount64())
	{
		// 중앙
		BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x, _rTransInfo.Position.y + 110, DIRECTION::MID));

		// 오른쪽
		BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x + 50, _rTransInfo.Position.y + 120, DIRECTION::MID));

		// 왼쪽
		BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x - 50 , _rTransInfo.Position.y + 120, DIRECTION::MID));
		Pattem1 = GetTickCount64();
	}

	if (EnemyObject->GetHart() < (Hart * 0.7f))
	{

		if (Pattem2 + 3500 < GetTickCount64())
		{
			// 중앙
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x, _rTransInfo.Position.y + 110, DIRECTION::MID));
			// 왼쪽 대각선
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x, _rTransInfo.Position.y + 110, DIRECTION::LEFT));
			// 오른쪽 대각선
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x, _rTransInfo.Position.y + 110, DIRECTION::RIGHT));


			// 오른쪽
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x + 50, _rTransInfo.Position.y + 120, DIRECTION::MID));
			// 왼쪽 대각선
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x + 50, _rTransInfo.Position.y + 110, DIRECTION::LEFT));
			// 오른쪽 대각선
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x + 50, _rTransInfo.Position.y + 110, DIRECTION::RIGHT));


			// 왼쪽
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x - 50, _rTransInfo.Position.y + 120, DIRECTION::MID));
			// 왼쪽 대각선
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x - 50, _rTransInfo.Position.y + 110, DIRECTION::LEFT));
			// 오른쪽 대각선
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x - 50, _rTransInfo.Position.y + 110, DIRECTION::RIGHT));

			Pattem2 = GetTickCount64();
		}
		
	}

	return 0;
}

void Boss::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(EnemyObject->GetPosition().x - (EnemyObject->GetScale().x / 2)),
		int(EnemyObject->GetPosition().y + (EnemyObject->GetScale().y / 2)),
		int(EnemyObject->GetScale().x),
		int(EnemyObject->GetScale().y),
		ImageList[DrawKey]->GetMemDC(),
		0, 0,
		int(EnemyObject->GetScale().x),
		int(EnemyObject->GetScale().y),
		RGB(255, 0, 255));
}

void Boss::Release()
{
}


template<typename T>
inline Object* Boss::CreateBullet(float _x, float _y, DIRECTION _Dir)
{
	Bridge* pBridge = new T;

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(_x, _y, pBridge);

	switch (_Dir)
	{
	case DIRECTION::LEFT:
		pBullet->SetDirection(-1.0f, 1.0f);
		break;
	case DIRECTION::MID:
		pBullet->SetDirection(0.0f, 1.0f);
		break;
	case DIRECTION::RIGHT:
		pBullet->SetDirection(1.0f, 1.0f);
		break;
	default:
		break;
	}
	
	return pBullet;
}