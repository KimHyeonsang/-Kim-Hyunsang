#include "Logo.h"
#include"Logo_Back.h"
#include"Player.h"
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

	ObjectManager::GetInstance()->SetPlayer(ObjectFactory<Player>::CreateObject());

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
	ImageList["Player1"] = (new Bitmap)->LoadBmp(L"../Resource/A-01.bmp");
	ImageList["PlayerBullet"] = (new Bitmap)->LoadBmp(L"../Resource/NomalBullet.bmp");
	ImageList["Boss"] = (new Bitmap)->LoadBmp(L"../Resource/Boss.bmp");
	ImageList["EnemyBullet"] = (new Bitmap)->LoadBmp(L"../Resource/EnemyBullet.bmp");
	ImageList["NomalEnemy"] = (new Bitmap)->LoadBmp(L"../Resource/NomalEnemy.bmp");
	ImageList["BomberEnemy"] = (new Bitmap)->LoadBmp(L"../Resource/BoombEnemy.bmp");
	LoGo_Back = new Logo_Back;
	LoGo_Back->Initialize();

	Object::SetImageList(ImageList);
}

void Logo::Update()
{
	// ** GetTickCount64���� ���� ��� ����
	if (Time + 2000 < GetTickCount64())
	{
		// ** �ڵ����� ���� Scene�Ѿ��
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
	}
}

void Logo::Render(HDC _hdc)
{
	// ** ��� �̹���
	LoGo_Back->Render(ImageList["Buffer"]->GetMemDC());

	// ** �����
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


