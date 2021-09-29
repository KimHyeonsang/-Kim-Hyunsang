#include "Logo_Back.h"

Logo_Back::Logo_Back()
{

}

Logo_Back::~Logo_Back()
{

}

void Logo_Back::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);
}

int Logo_Back::Update()
{
	return 0;
}

void Logo_Back::Render(HDC _hdc)
{
	// ** 우주 배경 띄우기
	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["BackGround"]->GetMemDC(),
		0, 0,
		SRCCOPY);


}

void Logo_Back::Release()
{
}


