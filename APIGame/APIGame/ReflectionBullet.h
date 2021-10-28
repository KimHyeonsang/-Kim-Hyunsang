#pragma once
#include"BulletBridge.h"

class ReflectionBullet :public BulletBridge
{
private:
	int Count;
	float Angle;
	Object* a;
public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	int GetCount() {return Count;}
public:
	ReflectionBullet();
	virtual ~ReflectionBullet();
};

