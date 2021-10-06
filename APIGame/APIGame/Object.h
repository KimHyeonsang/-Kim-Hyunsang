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

	BULLETID BulletID;
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
	// ** 좌표를 Setting (Vector3)
	void SetPosition(Vector3 _position) {	TransInfo.Position = _position;	}
	// ** 좌표를 Setting (_x, _y)
	void SetPosition(float _x, float _y) {	TransInfo.Position.x = _x; TransInfo.Position.y = _y;	}
	// ** 좌표를 Vector3로 out
	Vector3 GetPosition() { return TransInfo.Position; }

	// ** 크기를 Vector3로 out
	Vector3 GetScale() { return TransInfo.Scale; }

	// ** 크기를 변경
	void SetScale(float _Scale_x,float _Scale_y){	
		TransInfo.Scale.x = _Scale_x;
		TransInfo.Scale.y = _Scale_y;
	}

	// ** 충돌체를 out.
	RECT GetCollider();

	Vector3 GetColliderPosition() {	return Collider.Position;	}
	Transform GetColliderTransform() {	return Collider;	}

	// ** 충돌체를 Setting
	void SetColliderPosition(float _x, float _y) {
		Collider.Position.x = _x; Collider.Position.y = _y;
	}

	// ** 목숨 확인
	int GetHart() {	return Hart;}
	// ** 목숨 지정
	void SetHart(int _Number) {	Hart = _Number;	}

	// BulletID
	void SetBulletID(BULLETID _ID) {BulletID = _ID;	}
	BULLETID GetBulletID() {	return BulletID;	}
public:
	Object();
	Object(const Transform& _rTransInfo) : TransInfo(_rTransInfo) { }
	virtual ~Object();
};

