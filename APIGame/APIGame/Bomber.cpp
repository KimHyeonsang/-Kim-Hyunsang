#include "Bomber.h"
#include"Object.h"
#include"ObjectManager.h"

Bomber::Bomber()
{

}

Bomber::~Bomber()
{
    Release();
}

void Bomber::Initialize()
{
    Speed = 7.0f;

    DrawKey = "BomberEnemy";

	ImageList = Object::GetImageList();

	EnemyObject->SetScale(58, 58);

	Target = ObjectManager::GetInstance()->GetPlayer();

	
}

int Bomber::Update(Transform& _rTransInfo)
{
	
	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;	
	_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;


    return 0;
}

void Bomber::Render(HDC _hdc)
{

}

void Bomber::Release()
{

}


