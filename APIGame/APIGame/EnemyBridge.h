#pragma once
#include"Bridge.h"

class EnemyBridge:public Bridge
{
protected:
	float Speed;
	ENEMYID ID;
	int Hart;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& _rTransInfo)PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;
public:
	ENEMYID GetID() {return ID;	}
	int GetHart() {	return Hart;}

public:
	EnemyBridge();
	virtual ~EnemyBridge();
};


