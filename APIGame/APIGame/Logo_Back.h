#pragma once
#include"Object.h"

class Logo_Back : public Object
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()	{return new Logo_Back(*this);	};
public:
	Logo_Back();
	virtual ~Logo_Back();
};

