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
	// ** ȭ��ǥ �޾ƿ���
	m_pSelect = ObjectManager::GetInstance()->GetSelect();

	// ** �̹����� �޾ƿ���
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

	//���ð��� �������� 2��
	// Ű����� ����

	// ĳ���ͼ���â
}

void Menu::Render(HDC _hdc)
{
// ���� ���� ���� �����

	// ** ��� �̹���
	LoGo_Back->Render(ImageList["Buffer"]->GetMemDC());

	m_pSelect->Render(ImageList["Buffer"]->GetMemDC());

	// ** ����
	TransparentBlt(ImageList["Buffer"]->GetMemDC(),
		150, 300,
		361,
		257,
		ImageList["START"]->GetMemDC(),
		0, 0,
		361,
		257,
		RGB(255, 0, 255));

	// ** ����
	TransparentBlt(ImageList["Buffer"]->GetMemDC(),
		160, 500,
		361,
		257,
		ImageList["Help"]->GetMemDC(),
		0, 0,
		361,
		257,
		RGB(255, 0, 255));


	// ** ����
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

