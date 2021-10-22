#pragma once
#include"Scene.h"

class Object;
class PlayerSelect :public Scene
{
private:
	ULONGLONG Time;
	ULONGLONG MoveTime;
	Transform TransInfo;
	bool m_bSelect;
	int m_iSelect;
	int m_iPointx;
	Object* m_pPlayer;
	Object* LogoBack;
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

