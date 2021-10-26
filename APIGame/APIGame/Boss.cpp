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

	m_iScore = 1000;

	ImageList = Object::GetImageList();

	EnemyObject->SetScale(200, 100);
	EnemyObject->SetColliderScale(200, 100);

	Pattem1 = GetTickCount64();
	Pattem2 = GetTickCount64();
	Pattem3 = GetTickCount64();
	MoveTime = GetTickCount64();

	bButton = false;

	BulletList = ObjectManager::GetInstance()->GetBulletList();
}

int Boss::Update(Transform& _rTransInfo)
{
	Move(_rTransInfo);

    // y축 이동
//	if (_rTransInfo.Position.y <= 100)
//		_rTransInfo.Position.y += _rTransInfo.Direction.y * 1;

	// 기본 2초마다 공격
	if (Pattem1 + 2000 < GetTickCount64())
	{
		// 중앙
		BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x + (_rTransInfo.Scale.x / 2) - 8, _rTransInfo.Position.y + 110, DIRECTION::BOTTOM1));

		// 오른쪽
		BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x + _rTransInfo.Scale.x  - 55, _rTransInfo.Position.y + 110, DIRECTION::BOTTOM1));

		// 왼쪽
		BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x + 48 , _rTransInfo.Position.y + 110, DIRECTION::BOTTOM1));
		Pattem1 = GetTickCount64();
	}

	// ** 체력이 70퍼 미만일 때 발동
	if (EnemyObject->GetHart() < (Hart * 0.7f))
	{

		// ** 3초
		if (Pattem2 + 3000 < GetTickCount64())
		{
			// 중앙
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x, _rTransInfo.Position.y + 110, DIRECTION::BOTTOM1));
			// 왼쪽 대각선
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x, _rTransInfo.Position.y + 110, DIRECTION::LEFTBOTTOM1));
			// 오른쪽 대각선
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x, _rTransInfo.Position.y + 110, DIRECTION::RIGHTBOTTOM1));


			// 오른쪽
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x + 50, _rTransInfo.Position.y + 120, DIRECTION::BOTTOM1));
			// 왼쪽 대각선
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x + 50, _rTransInfo.Position.y + 110, DIRECTION::LEFTBOTTOM1));
			// 오른쪽 대각선
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x + 50, _rTransInfo.Position.y + 110, DIRECTION::RIGHTBOTTOM1));


			// 왼쪽
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x - 50, _rTransInfo.Position.y + 120, DIRECTION::BOTTOM1));
			// 왼쪽 대각선
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x - 50, _rTransInfo.Position.y + 110, DIRECTION::LEFTBOTTOM1));
			// 오른쪽 대각선
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x - 50, _rTransInfo.Position.y + 110, DIRECTION::RIGHTBOTTOM1));

			Pattem2 = GetTickCount64();
		}		
	}

	// ** 체력이 40퍼 미만일 때 발동
	if (EnemyObject->GetHart() < (Hart * 0.4f))
	{
		// ** 7초마다 공격
		if (Pattem3 + 7000 < GetTickCount64())
		{
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x, _rTransInfo.Position.y + 110, DIRECTION::BOTTOM2));
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x, _rTransInfo.Position.y + 110, DIRECTION::BOTTOM3));
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x, _rTransInfo.Position.y + 110, DIRECTION::BOTTOM1));
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x, _rTransInfo.Position.y + 110, DIRECTION::LEFTBOTTOM3));
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x, _rTransInfo.Position.y + 110, DIRECTION::RIGHTBOTTOM3));
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x, _rTransInfo.Position.y + 110, DIRECTION::LEFTBOTTOM1));
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x, _rTransInfo.Position.y + 110, DIRECTION::LEFTBOTTOM2));
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x, _rTransInfo.Position.y + 110, DIRECTION::RIGHTBOTTOM1));
			BulletList->push_back(CreateBullet<EnemyNomalBullet>(_rTransInfo.Position.x, _rTransInfo.Position.y + 110, DIRECTION::RIGHTBOTTOM2));

			Pattem3 = GetTickCount64();
		}
	}

	return 0;
}

void Boss::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(EnemyObject->GetPosition().x),
		int(EnemyObject->GetPosition().y),
		int(EnemyObject->GetScale().x),
		int(EnemyObject->GetScale().y),
		ImageList[DrawKey]->GetMemDC(),
		0, 0,
		int(EnemyObject->GetScale().x),
		int(EnemyObject->GetScale().y),
		RGB(255, 0, 255));
}

void Boss::Move(Transform& _rTransInfo)
{
	if (EnemyObject->GetHart() > (Hart * 0.7f))
	{
		if (bButton)
		{
			if (_rTransInfo.Position.x < 0)
			{
				bButton = false;
				_rTransInfo.Direction = Vector3(1.0f, 0.5f);
			}

			_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
		}
		else
		{
			if (_rTransInfo.Position.x + (_rTransInfo.Scale.x) > WindowsWidth)
			{
				bButton = true;
				_rTransInfo.Direction = Vector3(-1.0f, -0.5f);
			}

			_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
		}
	}
	// ** 체력이 70퍼 미만일 때 발동
	else if (EnemyObject->GetHart() < (Hart * 0.7f))
	{
		// 일정 피 이하일 떄 순간이동?
		
		if (MoveTime + 1000 < GetTickCount64())
		{
			_rTransInfo.Position.x = (rand() % (WindowsWidth - 200));
			MoveTime = GetTickCount64();
		}
	//	if (bButton)
	//	{
	//		if (_rTransInfo.Position.x < 0)
	//		{
	//			_rTransInfo.Direction = Vector3(1.0f, 0.5f);
	//			bButton = false;
	//		}
	//		_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	//		_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;
	//	}
	//	else
	//	{
	//		if (_rTransInfo.Position.x + _rTransInfo.Scale.x > WindowsWidth)
	//		{
	//			_rTransInfo.Direction = Vector3(-1.0f, -0.5f);
	//			bButton = true;
	//		}
	//	
	//		_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	//		_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;
	//	}
	}
}


template<typename T>
inline Object* Boss::CreateBullet(float _x, float _y, DIRECTION _Dir)
{
	Bridge* pBridge = new T;

	Vector3 Pos;
	Pos.x = EnemyObject->GetPosition().x + (EnemyObject->GetScale().x / 2) - 8;
	Pos.y = EnemyObject->GetPosition().y;

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(_x, _y, pBridge);

	switch (_Dir)
	{
	case DIRECTION::BOTTOM2:
		pBullet->SetDirection(0.25f, 1.0f);
		break;
	case DIRECTION::BOTTOM1:
		pBullet->SetDirection(0.0f, 1.0f);
		break;
	case DIRECTION::BOTTOM3:
		pBullet->SetDirection(-0.25f, 1.0f);
		break;
	case DIRECTION::LEFTBOTTOM3:
		pBullet->SetDirection(-0.75f, 1.0f);
		break;
	case DIRECTION::RIGHTBOTTOM3:
		pBullet->SetDirection(0.75f, 1.0f);
		break;
	case DIRECTION::LEFTBOTTOM2:
		pBullet->SetDirection(-0.5f, 1.0f);
		break;
	case DIRECTION::LEFTBOTTOM1:
		pBullet->SetDirection(-1.0f, 1.0f);
		break;
	case DIRECTION::RIGHTBOTTOM2:
		pBullet->SetDirection(0.5f, 1.0f);
		break;
	case DIRECTION::RIGHTBOTTOM1:
		pBullet->SetDirection(1.0f, 1.0f);
		break;
	}

	return pBullet;
}

void Boss::Release()
{
}