#pragma once
#include"EnemyBridge.h"

class BaseEnemy :public EnemyBridge
{
private:
	bool bButton;
public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	BaseEnemy();
	virtual ~BaseEnemy();
};

