#include "BaseEnemy.h"
#include"Object.h"
#include"ObjectManager.h"
#include"EnemyNomalBullet.h"
#include"Bullet.h"
#include"ObjectFactory.h"

BaseEnemy::BaseEnemy()
{

}

BaseEnemy::~BaseEnemy()
{

}

void BaseEnemy::Initialize()
{
	Speed = 6.0f;

	DrawKey = "NomalEnemy";

	bButton = false;

	ImageList = Object::GetImageList();

	EnemyObject->SetScale(58, 58);

	BulletList = ObjectManager::GetInstance()->GetBulletList();

	Time = GetTickCount64();

	RandomShoot = float(rand() % 1000 + 500);
}

int BaseEnemy::Update(Transform& _rTransInfo)
{
	if (bButton)
	{
		if (_rTransInfo.Position.x < 0)
			bButton = false;

		_rTransInfo.Position.x -= _rTransInfo.Direction.x * Speed;
	}
	else
	{
		if (_rTransInfo.Position.x > WindowsWidth)
			bButton = true;

		_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	}

	if(_rTransInfo.Position.y <= 100 )
		_rTransInfo.Position.y += _rTransInfo.Direction.y * 1;

	
	// ** 객체마다 공격 랜덤 주기
	if (Time + RandomShoot < GetTickCount64())
	{
		BulletList->push_back(CreateBullet<EnemyNomalBullet>());
		Time = GetTickCount64();
	}
	return 0;
}

void BaseEnemy::Render(HDC _hdc)
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

	/*
	Ellipse(_hdc,
		int(EnemyObject->GetPosition().x - (EnemyObject->GetScale().x / 2)),
		int(EnemyObject->GetPosition().y - (EnemyObject->GetScale().y / 2)),
		int(EnemyObject->GetPosition().x + (EnemyObject->GetScale().x / 2)),
		int(EnemyObject->GetPosition().y + (EnemyObject->GetScale().y / 2)));
	*/
}

void BaseEnemy::Release()
{
}


template<typename T>
inline Object* BaseEnemy::CreateBullet()
{
	Bridge* pBridge = new T;

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(EnemyObject->GetPosition(), pBridge);

	return pBullet;
}