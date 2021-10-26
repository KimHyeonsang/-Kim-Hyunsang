#pragma once
#include"Object.h"

#define PI 3.141592f

class Item : public Object
{
private:
	float Angle;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override {return new Item(*this);	};
public:

public:
	Item();
	Item(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Item();
};

