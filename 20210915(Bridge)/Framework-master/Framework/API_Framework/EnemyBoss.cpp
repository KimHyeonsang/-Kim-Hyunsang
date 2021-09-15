#include "EnemyBoss.h"
#include"Object.h"

EnemyBoss::EnemyBoss()
{

}

EnemyBoss::~EnemyBoss()
{

}

void EnemyBoss::Initialize()
{
	Hart = 3;
	DrawKey = "Mole";

	Offset = Vector3(149.0f, 0.0f);
}

int EnemyBoss::Update(Transform& _rTransInfo)
{
	
	if (!(Offset.y >= 94))
		Offset.y += 2.5f;

	return 0;
}

void EnemyBoss::Render(HDC _hdc)
{
	/*
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y + (RealObject->GetScale().x / 2) - Offset.y - 50),
		int(RealObject->GetScale().x),
		int(Offset.y),
		ImageList[DrawKey]->GetMemDC(),
		0, 0,
		int(RealObject->GetScale().x),
		int(Offset.y),
		RGB(255, 0, 255));
	*/
	Ellipse(_hdc,
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
		int(RealObject->GetPosition().x + (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y + (RealObject->GetScale().y / 2)));
}

void EnemyBoss::Release()
{
}


