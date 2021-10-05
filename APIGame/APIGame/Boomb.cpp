#include "Boomb.h"

Boomb::Boomb()
{

}

Boomb::~Boomb()
{

}

void Boomb::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(0.0f, 1.0f);
	TransInfo.Scale = Vector3(30.0f, 30.0f);

	strKey = "Boomb";

	Speed = 3;
}

int Boomb::Update()
{
	TransInfo.Position.x += TransInfo.Direction.x * Speed;
	TransInfo.Position.y -= TransInfo.Direction.y * Speed;

	// ** �����Ÿ��Ǹ� ������  ��ü y - ĳ���� ��ġ + ĳ���ͱ���*2
	if (TransInfo.Position.y <= (WindowsHeight - (TransInfo.Position.y + (84 * 2))))
		return 1;

    return 0;
}

void Boomb::Render(HDC _hdc)
{
	Ellipse(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Position.x + (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y + (TransInfo.Scale.y / 2)));
}

void Boomb::Release()
{
}


