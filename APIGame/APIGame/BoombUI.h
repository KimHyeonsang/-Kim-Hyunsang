#pragma once
#include"Object.h"

class BoombUI :public Object
{
private:
	bool MOVE;
	ULONGLONG Time;
	Object* m_BoombCount;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override {
		return new BoombUI(*this);
	}
public:
	BoombUI();
	BoombUI(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~BoombUI();
};

