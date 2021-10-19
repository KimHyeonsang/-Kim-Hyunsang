#pragma once
#include"EnemyBridge.h"

class Boss:public EnemyBridge
{
private:
	ULONGLONG Pattem1;
	ULONGLONG Pattem2;
	ULONGLONG Pattem3;
	ULONGLONG MoveTime;
	bool bButton;
public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	void Move(Transform& _rTransInfo);
	template <typename T>
	Object* CreateBullet(float _x,float _y, DIRECTION _Dir);
public:
	Boss();
	virtual ~Boss();
};

