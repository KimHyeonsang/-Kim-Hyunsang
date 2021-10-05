#pragma once
#include"Header.h"

class Bitmap;
class Object
{
protected:
	Transform TransInfo;
	Transform Collider;
	Vector3 Offset;

	string strKey;
	float Speed;
	int Hart;
	static map<string, Bitmap*> ImageList;
public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;

	virtual Object* Clone()PURE;
public:
	static void SetImageList(const map<string,Bitmap*>& _ImageList) {ImageList = _ImageList;}
	static map<string, Bitmap*> GetImageList() {return ImageList;	}
	string GetKey()const {	return strKey;	}
	// ** ÁÂÇ¥¸¦ Setting (Vector3)
	void SetPosition(Vector3 _position) {	TransInfo.Position = _position;	}
	// ** ÁÂÇ¥¸¦ Setting (_x, _y)
	void SetPosition(float _x, float _y) {	TransInfo.Position.x = _x; TransInfo.Position.y = _y;	}
	// ** ÁÂÇ¥¸¦ Vector3·Î out
	Vector3 GetPosition() { return TransInfo.Position; }

	// ** Å©±â¸¦ Vector3·Î out
	Vector3 GetScale() { return TransInfo.Scale; }

	// ** Å©±â¸¦ º¯°æ
	void SetScale(float _Scale_x,float _Scale_y){	
		TransInfo.Scale.x = _Scale_x;
		TransInfo.Scale.y = _Scale_y;
	}
public:
	Object();
	Object(const Transform& _rTransInfo) : TransInfo(_rTransInfo) { }
	virtual ~Object();
};

