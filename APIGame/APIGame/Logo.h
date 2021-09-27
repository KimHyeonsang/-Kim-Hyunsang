#pragma once
#include"Scene.h"

class Object;
class Logo:public Scene
{
private:
	Object* LoGo_Back;
	map<string, Bitmap*> ImageList;
	ULONGLONG Time;
public:
	virtual void Initalize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Logo();
	virtual ~Logo();
};

