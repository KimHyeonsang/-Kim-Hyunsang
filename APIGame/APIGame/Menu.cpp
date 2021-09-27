#include "Menu.h"
#include"Player.h"
#include"Logo_Back.h"
#include"SceneManager.h"
#include"ObjectManager.h"

Menu::Menu()
{

}

Menu::~Menu()
{
	Release();
}

void Menu::Initalize()
{
	// ** 화살표 받아오기
	m_pSelect = ObjectManager::GetInstance()->GetSelect();

	// ** 이미지들 받아오기
	ImageList = Object::GetImageList();

	LoGo_Back = new Logo_Back;
	LoGo_Back->Initialize();
}

void Menu::Update()
{
	if((MENUID)m_pSelect->Update() == MENUID::START)
		SceneManager::GetInstance()->SetScene(SCENEID::SELECTSTAGE);
	else if ((MENUID)m_pSelect->Update() == MENUID::HELP)
  		SceneManager::GetInstance()->SetScene(SCENEID::SELECTSTAGE);
	else if ((MENUID)m_pSelect->Update() == MENUID::EXIT)
		SceneManager::GetInstance()->SetScene(SCENEID::SELECTSTAGE);

	//슈팅게임 스테이지 2개
	// 키보드로 선택

	// 캐릭터선택창
}

void Menu::Render(HDC _hdc)
{
// 시작 도움말 종료 만들기

	// ** 배경 이미지
	LoGo_Back->Render(ImageList["Buffer"]->GetMemDC());

	m_pSelect->Render(ImageList["Buffer"]->GetMemDC());

	// ** 시작
	TransparentBlt(ImageList["Buffer"]->GetMemDC(),
		150, 300,
		361,
		257,
		ImageList["START"]->GetMemDC(),
		0, 0,
		361,
		257,
		RGB(255, 0, 255));

	// ** 도움말
	TransparentBlt(ImageList["Buffer"]->GetMemDC(),
		160, 500,
		361,
		257,
		ImageList["Help"]->GetMemDC(),
		0, 0,
		361,
		257,
		RGB(255, 0, 255));


	// ** 종료
	TransparentBlt(ImageList["Buffer"]->GetMemDC(), 
		150, 700,
		361,
		257,
		ImageList["END"]->GetMemDC(),
		0, 0,
		361,
		257,
		RGB(255, 0, 255));

	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Menu::Release()
{
}

