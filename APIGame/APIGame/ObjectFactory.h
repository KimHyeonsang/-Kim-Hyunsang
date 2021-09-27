#pragma once
#include"Object.h"


template<typename T>
class ObjectFactory
{
public:
	static Object* CreateObject()
	{
		Object* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	static Object* CreateObject(Vector3 _vPos)
	{
		Object* pObj = new T;
		pObj->Initialize();
		pObj->SetPosition(_vPos);

		return pObj;
	}

	static Object* CreateObject(float _x, float _y)
	{
		Object* pObj = new T;
		pObj->Initialize();
		pObj->SetPosition(_x, _y);

		return pObj;
	}
};