#pragma once
#include"Header.h"

class Object;
class Bridge
{
protected:
	string DrawKey;
	Object* RealObject;
	map<string, Bitmap*> ImageList;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& _rTransInfo)PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;
public:
	void SetObject(Object* _pObject) {	RealObject = _pObject;	}

	void SetImageList(map<string, Bitmap*>& _ImageList) {ImageList = _ImageList;	}
public:
	Bridge();
	virtual ~Bridge();
};

