#include "Menu.h"
#include"Player.h"
#include"MenuButton.h"
#include"Logo_Back.h"
#include"SceneManager.h"
#include"ObjectManager.h"
#include"SoundManager.h"

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

	SoundManager::GetInstance()->Initialize();

	
	SoundManager::GetInstance()->OnPlaySound("BGM");
	// ** 배경이미지
	LoGo_Back = new Logo_Back;
	LoGo_Back->Initialize();

	((MenuButton*)m_pSelect)->SetID(MENUID::ZERO);
}

void Menu::Update()
{
	// ** 화살표 움직임
	m_pSelect->Update();	

	// ** 화살표가 가르켜 선택한 번호
		// ** 시작
	if (((MenuButton*)m_pSelect)->GetID() == MENUID::START)
	{
		SceneManager::GetInstance()->SetScene(SCENEID::PLAYERSELECTSCENE);
	}
	// ** 도움말
	else if (((MenuButton*)m_pSelect)->GetID() == MENUID::HELP)
	{
		SceneManager::GetInstance()->SetScene(SCENEID::HELPSCENE);
		
	}
	// ** 종료
	else if (((MenuButton*)m_pSelect)->GetID() == MENUID::EXIT)
	{
		if (g_hWnd)
			SendMessage(g_hWnd, WM_CLOSE, 0, 0);
	}
}

void Menu::Render(HDC _hdc)
{
	// ** 배경 이미지
	LoGo_Back->Render(ImageList["Buffer"]->GetMemDC());

	m_pSelect->Render(ImageList["Buffer"]->GetMemDC());


	// ** 로고 띄우기
	TransparentBlt(ImageList["Buffer"]->GetMemDC(), // ** 최종 출력 위치
		150, 100,
		503,
		249,
		ImageList["Logo"]->GetMemDC(),
		0, 0,
		503,
		249,
		RGB(255, 0, 255));

	// ** 시작
	TransparentBlt(ImageList["Buffer"]->GetMemDC(),
		180, 300,
		361,
		257,
		ImageList["START"]->GetMemDC(),
		0, 0,
		287,
		200,
		RGB(255, 0, 255));

	// ** 도움말
	TransparentBlt(ImageList["Buffer"]->GetMemDC(),
		190, 500,
		361,
		257,
		ImageList["Help"]->GetMemDC(),
		0, 0,
		412,
		200,
		RGB(255, 0, 255));


	// ** 종료
	TransparentBlt(ImageList["Buffer"]->GetMemDC(), 
		250, 700,
		361,
		257,
		ImageList["END"]->GetMemDC(),
		0, 0,
		412,
		200,
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
	//SoundManager::GetInstance()->Release();
}

