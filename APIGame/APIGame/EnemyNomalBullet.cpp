#include "EnemyNomalBullet.h"
#include"Object.h"
#include"ObjectManager.h"

EnemyNomalBullet::EnemyNomalBullet()
{

}

EnemyNomalBullet::~EnemyNomalBullet()
{
    Release();
}

void EnemyNomalBullet::Initialize()
{
	Speed = 5.0f;

	Damage = 1;

	DrawKey = "EnemyBullet";

	Id = BULLETID::ENEMY;

	ImageList = Object::GetImageList();	
}

int EnemyNomalBullet::Update(Transform& _rTransInfo)
{
	

	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;

	if (_rTransInfo.Position.y >= WindowsHeight || _rTransInfo.Position.y <= 0
		|| _rTransInfo.Position.x >= WindowsWidth || _rTransInfo.Position.x <= 0)
		return 1;

    return 0;
}

void EnemyNomalBullet::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(BulletObject->GetPosition().x),
		int(BulletObject->GetPosition().y),
		int(BulletObject->GetScale().x),
		int(BulletObject->GetScale().y),
		ImageList[DrawKey]->GetMemDC(),
		0, 0,
		int(BulletObject->GetScale().x),
		int(BulletObject->GetScale().y),
		RGB(255, 0, 255));

	
}

void EnemyNomalBullet::Release()
{
}


