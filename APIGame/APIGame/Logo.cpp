#include "Logo.h"
#include"Logo_Back.h"
#include"MenuButton.h"

#include"SceneManager.h"
#include"ObjectManager.h"
#include"ObjectFactory.h"

Logo::Logo()
{

}

Logo::~Logo()
{

}

void Logo::Initalize()
{
	ObjectManager::GetInstance()->Initialize();

	ObjectManager::GetInstance()->SetSelect(ObjectFactory<MenuButton>::CreateObject());

	Time = GetTickCount64();

	ImageList["BackGround"] = (new Bitmap)->LoadBmp(L"../Resource/Space.bmp");
	ImageList["Buffer"] = (new Bitmap)->LoadBmp(L"../Resource/Buffer.bmp");
	ImageList["Logo"] = (new Bitmap)->LoadBmp(L"../Resource/Logo.bmp");
	ImageList["START"] = (new Bitmap)->LoadBmp(L"../Resource/START.bmp");
	ImageList["Help"] = (new Bitmap)->LoadBmp(L"../Resource/HELP.bmp");
	ImageList["END"] = (new Bitmap)->LoadBmp(L"../Resource/END.bmp");
	ImageList["Select"] = (new Bitmap)->LoadBmp(L"../Resource/Select.bmp");
	ImageList["HelpScene"] = (new Bitmap)->LoadBmp(L"../Resource/HelpScene.bmp");

	LoGo_Back = new Logo_Back;
	LoGo_Back->Initialize();

	Object::SetImageList(ImageList);
}

void Logo::Update()
{
	// ** GetTickCount64보다 작을 경우 실행
	if (Time + 2000 < GetTickCount64())
	{
		// ** 자동으로 다음 Scene넘어가기
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
	}
}

void Logo::Render(HDC _hdc)
{
	// ** 배경 이미지
	LoGo_Back->Render(ImageList["Buffer"]->GetMemDC());

	// ** 백버퍼
	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Logo::Release()
{

}


