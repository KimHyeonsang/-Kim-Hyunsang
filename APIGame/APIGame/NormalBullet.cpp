#include "NormalBullet.h"
#include"Object.h"

NormalBullet::NormalBullet()
{

}

NormalBullet::~NormalBullet()
{

}
void NormalBullet::Initialize()
{
	Speed = 5.0f;

 	DrawKey = "PlayerBullet";

	Damage = 1;

	Id = BULLETID::PLAYER;

	ImageList = Object::GetImageList();
}

int NormalBullet::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	_rTransInfo.Position.y -= _rTransInfo.Direction.y * Speed;

	if (_rTransInfo.Position.y < 0)
		return 1;

	return 0;
}

void NormalBullet::Render(HDC _hdc)
{	
	
 	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(BulletObject->GetPosition().x),
		int(BulletObject->GetPosition().y ),
		int(BulletObject->GetScale().x),
		int(BulletObject->GetScale().y),
		ImageList[DrawKey]->GetMemDC(),
		0, 0,
		int(BulletObject->GetScale().x),
		int(BulletObject->GetScale().y),
		RGB(255, 0, 255));
}


void NormalBullet::Release()
{
}


