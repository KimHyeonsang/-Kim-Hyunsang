#include "Enemy.h"
#include"EnemyBoss.h"

Enemy::Enemy() : BridgeObject(NULL)
{

}

Enemy::~Enemy()
{

}

void Enemy::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(149.0f, 124.0f);

	Collider.Position = Vector3(0.0f, 0.0f);
	Collider.Scale = Vector3(100.0f, 100.0f);

//	Offset = Vector3(149.0f, 0.0f);

	Active = false;
	strKey = "Mole";
	
	BridgeObject = NULL;

	Speed = 1.5f;
}

int Enemy::Update()
{
	if (BridgeObject)
		BridgeObject->Update(TransInfo);

	return 0;
}

void Enemy::Render(HDC _hdc)
{
	if (BridgeObject)
		BridgeObject->Render(_hdc);
}

void Enemy::Release()
{
	delete BridgeObject;
	BridgeObject = nullptr;
}
