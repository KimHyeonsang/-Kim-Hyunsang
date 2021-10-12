#pragma once
#include"Bridge.h"

class BulletBridge : public Bridge
{
protected:
	float Speed;
	int Damage;
	Transform TransInfo;
	BULLETID Id;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& _rTransInfo)PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;
public:
	int GetDamage() {return Damage;	}
	BULLETID GetID() {	return Id;	}
public:
	BulletBridge();
	virtual ~BulletBridge();
};

