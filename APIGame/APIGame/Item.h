#pragma once
#include"Object.h"

class Item : public Object
{
private:
	float Angle;
	int ItemNumber;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override {return new Item(*this);	};
public:
	void SetNumber();
	int GetItemNumber() {return ItemNumber;	}
public:
	Item();
	Item(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Item();
};

