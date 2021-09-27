#pragma once
#include"Scene.h"

class Object;
class PlayerSelect :public Scene
{
private:
	ULONGLONG Time;
	Object* Arrow_key;
	Object* LoGo_Back;
	map<string, Bitmap*> ImageList;
public:
	virtual void Initalize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	PlayerSelect();
	virtual ~PlayerSelect();
};

