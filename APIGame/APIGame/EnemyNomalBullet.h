#pragma once
#include"BulletBridge.h"

class EnemyNomalBullet : public BulletBridge
{

public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	
public:
	EnemyNomalBullet();
	virtual ~EnemyNomalBullet();
};

