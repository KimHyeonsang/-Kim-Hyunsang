#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform transform;
	string strKey;
public:
	virtual void Initialize()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	string GetKey() { return strKey;}
public:
	Object();
	virtual ~Object();
};