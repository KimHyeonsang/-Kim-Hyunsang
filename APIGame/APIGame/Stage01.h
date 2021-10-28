#pragma once
#include"Scene.h"

class Object;
class Stage01:public Scene
{
private:
	ULONGLONG Time;
	ULONGLONG SpownTime;
	ULONGLONG InvincibilityTime;
	Object* m_pEffect;
	Object* m_pPlayer;
	vector<Object*>* EnemyList;
	vector<Object*>* BulletList;
	vector<Object*>* BoombList;
	vector<Object*>* ItemList;
	Object* LogoBack;
	Object* m_pHart;
	Object* m_pBoombUi;
	Object* m_pScore;
	map<string, Bitmap*> ImageList;

	int FieldNumber;
	int CurrentNumber;
public:
	virtual void Initalize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Object* CreateItem(Vector3 _Pos);
	template<typename T>
	Object* CreateEnemy();

	
public:
	Stage01();
	virtual ~Stage01();
};