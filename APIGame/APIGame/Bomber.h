#pragma once
#include"EnemyBridge.h"

class Bomber: public EnemyBridge
{
private:
	Object* Target;
public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Bomber();
	virtual ~Bomber();
};

