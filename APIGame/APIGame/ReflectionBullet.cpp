#include "ReflectionBullet.h"
#include"Object.h"

ReflectionBullet::ReflectionBullet()
{

}

ReflectionBullet::~ReflectionBullet()
{

}

void ReflectionBullet::Initialize()
{
	random_device rd;

	srand(rd());

	Speed = 5.0f;

	DrawKey = "ReflectionBullet";

	Damage = 1;

	// 0~ 3.0����
	Angle = ((float)(rand() % 300 + 1) / 100);
	// ƨ�� Ƚ��
	Count = 0;

	Id = BULLETID::PLAYER;

	ImageList = Object::GetImageList();
} 

int ReflectionBullet::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.x += cosf(Angle) * Speed;
	_rTransInfo.Position.y += -sinf(Angle) * Speed;

	if (_rTransInfo.Position.x - (_rTransInfo.Scale.x / 2) <= 0)
	{
		Angle = PI - Angle;
		Count++;
		
	}
	if (_rTransInfo.Position.x + (_rTransInfo.Scale.x / 2) >= WindowsWidth)
	{
		Angle = PI - Angle;
		Count++;
	}

	//���� �ݻ簢�� �̿��� ������ �浹 ����
	if (_rTransInfo.Position.y - (_rTransInfo.Scale.y / 2) < 0)
	{
		Angle = 2 * PI - Angle;
		Count++;
	}
	if (_rTransInfo.Position.y + (_rTransInfo.Scale.y / 2) > WindowsHeight)
	{
		Angle = 2 * PI - Angle;
		Count++;
	}

    return 0;
}

void ReflectionBullet::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** ���� ��� ��ġ
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

void ReflectionBullet::Release()
{

}


