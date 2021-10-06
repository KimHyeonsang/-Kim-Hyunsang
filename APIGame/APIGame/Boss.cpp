#include "Boss.h"
#include"Object.h"

Boss::Boss()
{

}

Boss::~Boss()
{

}

void Boss::Initialize()
{
	Hart = 100;

	Speed = 6.0f;

	DrawKey = "NomalEnemy";

	ImageList = Object::GetImageList();

	EnemyObject->SetScale(58, 58);
}

int Boss::Update(Transform& _rTransInfo)
{
	return 0;
}

void Boss::Render(HDC _hdc)
{
}

void Boss::Release()
{
}


