#include "BoomEffect.h"
#include"ObjectManager.h"

BoomEffect::BoomEffect()
{

}

BoomEffect::~BoomEffect()
{

}

void BoomEffect::Initialize()
{
	Frame = 0;

	// 폭탄의 위치
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(270.0f, 214.0f);

	Collider.Position = Vector3(0.0f, 0.0f);
	Collider.Scale = Vector3(0.0f, 0.0f);

//	Offset = Vector3(41.0f, -39.0f);

	strKey = "Effect";

	Active = false;
	Time = GetTickCount64();
}

int BoomEffect::Update()
{
	if (Frame >= 3)
	{
		Active = false;
		Frame = 0;
	}

	if (Time + 40 < GetTickCount64())
	{
		Time = GetTickCount64();
		Frame++;
	}

    return 0;
}

void BoomEffect::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2) ),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2) ),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x * Frame),
		int(TransInfo.Scale.y * 0),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));
}

void BoomEffect::Release()
{
}


