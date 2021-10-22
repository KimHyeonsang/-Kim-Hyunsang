#include "Enemy.h"
#include"Boss.h"
#include"BaseEnemy.h"
#include"EnemyBridge.h"

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

    Collider.Position = Vector3(0.0f, 0.0f);
    Collider.Scale = Vector3(50.0f, 50.0f);

    strKey = "Enemy";

    BridgeObject = NULL;
}

int Enemy::Update()
{    
    // ** 적ID가 비었으면
    if (GetEnemyID() == ENEMYID::ZERO)
    {
        // ** ID저장
        SetEnemyID(((EnemyBridge*)BridgeObject)->GetID());
        // ** 체력 입력
        SetHart(((EnemyBridge*)BridgeObject)->GetHart());
        SetScore(((EnemyBridge*)BridgeObject)->GetScore());
    }


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
