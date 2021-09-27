#include "HelpScene.h"
#include"Logo_Back.h"
#include"MenuButton.h"
#include"SceneManager.h"
#include"ObjectManager.h"

HelpScene::HelpScene()
{

}

HelpScene::~HelpScene()
{

}


void HelpScene::Initalize()
{
	// ** 이미지들 받아오기
	ImageList = Object::GetImageList();

	Arrow_key = ObjectManager::GetInstance()->GetSelect();
	// ** 배경이미지
	LoGo_Back = new Logo_Back;
	LoGo_Back->Initialize();

	Time = GetTickCount64();
}

void HelpScene::Update()
{
	// ** 엔터를 누르면 메뉴씬으로 이동
	if (Time + 100 < GetTickCount64())
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			// ** 선택칸이 가르키는 번호 0으로 변경
			((MenuButton*)Arrow_key)->SetID(MENUID::ZERO);
			// ** 메뉴 씬으로 이동
			SceneManager::GetInstance()->SetScene(SCENEID::MENU);
		}
		Time = GetTickCount64();
	}
}

void HelpScene::Render(HDC _hdc)
{

	// ** 배경 이미지
	LoGo_Back->Render(ImageList["Buffer"]->GetMemDC());

	// 도움말그림
	TransparentBlt(ImageList["Buffer"]->GetMemDC(),
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["HelpScene"]->GetMemDC(),
		0, 0,
		WindowsWidth,
		WindowsHeight,
		RGB(255, 0, 255));



	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void HelpScene::Release()
{
}


