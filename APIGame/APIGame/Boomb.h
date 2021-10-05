#pragma once
#include"Object.h"

class Boomb : public Object
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override {return new Boomb(*this);	};
public:
	Boomb();
	Boomb(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Boomb();
};

