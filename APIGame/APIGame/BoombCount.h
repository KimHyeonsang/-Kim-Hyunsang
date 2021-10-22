#pragma once
#include"Object.h"

class BoombCount:public Object
{
private:
private:
	ULONGLONG Time;
	Object* m_pPlayer;
	int Frame_x;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override {
		return new BoombCount(*this);
	}
public:
	BoombCount();
	BoombCount(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~BoombCount();
};

