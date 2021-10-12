#pragma once
#include"EnemyBridge.h"

class Boss:public EnemyBridge
{
private:
	ULONGLONG Pattem1;
	ULONGLONG Pattem2;
public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	template <typename T>
	Object* CreateBullet(float _x,float _y, DIRECTION _Dir);
public:
	Boss();
	virtual ~Boss();
};

