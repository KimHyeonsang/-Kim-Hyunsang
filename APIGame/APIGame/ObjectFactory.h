#pragma once
#include"Object.h"
#include"Bridge.h"

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

	static Object* CreateObject(Vector3 _vPos, Bridge* pBridge)
	{
		Object* pObj = new T;
		pObj->Initialize();
		pObj->SetPosition(_vPos);

		if (pObj->GetKey() == "Bullet")
			pBridge->SetBulletObject(pObj);
		else if (pObj->GetKey() == "Enemy")
			pBridge->SetEnemyObject(pObj);

		pBridge->Initialize();


		((T*)pObj)->SetBridge(pBridge);

		return pObj;
	}

	static Object* CreateObject(float _x, float _y, Bridge* pBridge)
	{
		Object* pObj = new T;
		pObj->Initialize();
		pObj->SetPosition(_x, _y);

		if (pObj->GetKey() == "Bullet")
			pBridge->SetBulletObject(pObj);
		else if (pObj->GetKey() == "Enemy")
			pBridge->SetEnemyObject(pObj);
		pBridge->Initialize();


		((T*)pObj)->SetBridge(pBridge);

		return pObj;
	}
};