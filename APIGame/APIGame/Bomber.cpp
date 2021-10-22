#include "Bomber.h"
#include"Object.h"
#include"ObjectManager.h"
#include"MathManager.h"

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

	ID = ENEMYID::BOOMB;

	Hart = 1;

	m_iScore = 100;

	ImageList = Object::GetImageList();

	EnemyObject->SetScale(58, 58);
	EnemyObject->SetColliderScale(58, 58);
	EnemyObject->SetColliderPosition(EnemyObject->GetPosition().x, EnemyObject->GetPosition().y);

	Target = ObjectManager::GetInstance()->GetPlayer();

	Target->GetPosition();
}

int Bomber::Update(Transform& _rTransInfo)
{
	_rTransInfo.Direction = MathManager::GetDirection(_rTransInfo.Position, Target->GetPosition());

	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;	
	_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;

	

    return 0;
}

void Bomber::Render(HDC _hdc)
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

void Bomber::Release()
{

}


