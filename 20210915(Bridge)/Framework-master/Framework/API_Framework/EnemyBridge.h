#pragma once
#include "Bridge.h"

class EnemyBridge : public Bridge
{
protected:
	int Hart;
	Vector3 Offset;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& _rTransInfo)PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;
public:
	EnemyBridge();
	virtual ~EnemyBridge();
};

