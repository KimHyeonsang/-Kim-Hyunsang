#include "Enemy.h"
#include"Boss.h"
#include"BaseEnemy.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
    Release();
}
void Enemy::Initialize()
{
    TransInfo.Position = Vector3(0.0f, 0.0f);
    TransInfo.Direction = Vector3(1.0f, 1.0f);
    TransInfo.Scale = Vector3(30.0f, 30.0f);

  //  strKey = "Enemy";

    BridgeObject = NULL;
}

int Enemy::Update()
{
    if (BridgeObject)
        if (BridgeObject->Update(TransInfo))
            return 1;
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


