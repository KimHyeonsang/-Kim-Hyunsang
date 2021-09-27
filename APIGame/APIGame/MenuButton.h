#pragma once
#include"Object.h"

class MenuButton:public Object
{
private:
	MENUID Number;
	ULONGLONG Time;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override {
		return new MenuButton(*this);
	};
public:
	MENUID GetID() { return Number; }
	void SetID(MENUID _Number) { Number = _Number; }
public:
	MenuButton();
	MenuButton(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~MenuButton();
};

