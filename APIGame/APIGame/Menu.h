#pragma once
#include"Scene.h"

class Object;
class Menu:public Scene
{
private:
	Object* m_pSelect;
	Object* LoGo_Back;
	map<string, Bitmap*> ImageList;
public:
	virtual void Initalize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Menu();
	virtual ~Menu();
};

