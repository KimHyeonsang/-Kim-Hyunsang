#pragma once
#include"Object.h"

class Hart_Ui:public Object
{
private:	
	bool MOVE;	
	ULONGLONG Time;
	Object* m_pPlayer;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override {
		return new Hart_Ui(*this);
	}
public:
	void Check();
public:
	Hart_Ui();
	Hart_Ui(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Hart_Ui();
};

