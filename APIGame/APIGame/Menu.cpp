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
	// ** ȭ��ǥ �޾ƿ���
	m_pSelect = ObjectManager::GetInstance()->GetSelect();

	// ** �̹����� �޾ƿ���
	ImageList = Object::GetImageList();

	SoundManager::GetInstance()->Initialize();

	
	SoundManager::GetInstance()->OnPlaySound("BGM");
	// ** ����̹���
	LoGo_Back = new Logo_Back;
	LoGo_Back->Initialize();

	((MenuButton*)m_pSelect)->SetID(MENUID::ZERO);
}

void Menu::Update()
{
	// ** ȭ��ǥ ������
	m_pSelect->Update();	

	// ** ȭ��ǥ�� ������ ������ ��ȣ
		// ** ����
	if (((MenuButton*)m_pSelect)->GetID() == MENUID::START)
	{
		SceneManager::GetInstance()->SetScene(SCENEID::PLAYERSELECTSCENE);
	}
	// ** ����
	else if (((MenuButton*)m_pSelect)->GetID() == MENUID::HELP)
	{
		SceneManager::GetInstance()->SetScene(SCENEID::HELPSCENE);
		
	}
	// ** ����
	else if (((MenuButton*)m_pSelect)->GetID() == MENUID::EXIT)
	{
		if (g_hWnd)
			SendMessage(g_hWnd, WM_CLOSE, 0, 0);
	}
}

void Menu::Render(HDC _hdc)
{
	// ** ��� �̹���
	LoGo_Back->Render(ImageList["Buffer"]->GetMemDC());

	m_pSelect->Render(ImageList["Buffer"]->GetMemDC());


	// ** �ΰ� ����
	TransparentBlt(ImageList["Buffer"]->GetMemDC(), // ** ���� ��� ��ġ
		150, 100,
		503,
		249,
		ImageList["Logo"]->GetMemDC(),
		0, 0,
		503,
		249,
		RGB(255, 0, 255));

	// ** ����
	TransparentBlt(ImageList["Buffer"]->GetMemDC(),
		180, 300,
		361,
		257,
		ImageList["START"]->GetMemDC(),
		0, 0,
		287,
		200,
		RGB(255, 0, 255));

	// ** ����
	TransparentBlt(ImageList["Buffer"]->GetMemDC(),
		190, 500,
		361,
		257,
		ImageList["Help"]->GetMemDC(),
		0, 0,
		412,
		200,
		RGB(255, 0, 255));


	// ** ����
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

