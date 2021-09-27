#pragma once
#include"Scene.h"

class Object;
class SelectStage:public Scene
{
private:
	map<string, Bitmap*> ImageList;
public:
	virtual void Initalize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	SelectStage();
	virtual ~SelectStage();
};

