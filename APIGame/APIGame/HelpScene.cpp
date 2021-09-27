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
	// ** �̹����� �޾ƿ���
	ImageList = Object::GetImageList();

	Arrow_key = ObjectManager::GetInstance()->GetSelect();
	// ** ����̹���
	LoGo_Back = new Logo_Back;
	LoGo_Back->Initialize();

	Time = GetTickCount64();
}

void HelpScene::Update()
{
	// ** ���͸� ������ �޴������� �̵�
	if (Time + 100 < GetTickCount64())
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			// ** ����ĭ�� ����Ű�� ��ȣ 0���� ����
			((MenuButton*)Arrow_key)->SetID(MENUID::ZERO);
			// ** �޴� ������ �̵�
			SceneManager::GetInstance()->SetScene(SCENEID::MENU);
		}
		Time = GetTickCount64();
	}
}

void HelpScene::Render(HDC _hdc)
{

	// ** ��� �̹���
	LoGo_Back->Render(ImageList["Buffer"]->GetMemDC());

	// ���򸻱׸�
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


