#pragma once
#include"Object.h"

class Score:public Object
{
private:
	ULONGLONG Time;
	Object* m_pPlayer;
	int Frame_x, Frame_y;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override {
		return new Score(*this);
	}
public:
	Score();
	Score(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Score();

};

