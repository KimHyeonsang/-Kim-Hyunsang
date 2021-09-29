#pragma once
#include"Scene.h"

class Object;
class Stage01:public Scene
{
private:
	ULONGLONG Time;
	
	Object* m_pPlayer;
	vector<Object*> EnemyList;

	Object* LogoBack;

	map<string, Bitmap*> ImageList;
public:
	virtual void Initalize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Stage01();
	virtual ~Stage01();
};

