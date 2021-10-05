#pragma once
#include"Header.h"

class Object;
class Bridge
{
protected:
	string DrawKey;
	Object* BulletObject;
	Object* EnemyObject;
	map<string, Bitmap*> ImageList;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& _rTransInfo)PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;
public:
	void SetBulletObject(Object* _pObject) {	BulletObject = _pObject;	}
	void SetEnemyObject(Object* _pObject) {	EnemyObject = _pObject;	}
//	void SetImageList(map<string, Bitmap*>& _ImageList) {ImageList = _ImageList;	}

	// �Ʊ��� ��ġ�� ã�� ���ڸ��� ����
public:
	Bridge();
	virtual ~Bridge();
};

