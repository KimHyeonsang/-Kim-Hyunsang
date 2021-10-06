#pragma once
#include"Scene.h"

class Object;
class Stage01:public Scene
{
private:
	ULONGLONG Time;
	
	Object* m_pPlayer;
	vector<Object*>* EnemyList;
	vector<Object*>* BulletList;
	vector<Object*>* BoombList;
	Object* LogoBack;

	map<string, Bitmap*> ImageList;

	int FieldNumber;
	int CurrentNumber;
public:
	virtual void Initalize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	template<typename T>
	Object* CreateEnemy();
public:
	Stage01();
	virtual ~Stage01();
};