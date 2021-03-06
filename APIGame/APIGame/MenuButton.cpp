#include "MenuButton.h"

MenuButton::MenuButton()
{

}

MenuButton::~MenuButton()
{

}
void MenuButton::Initialize()
{
	TransInfo.Position = Vector3(120, 420);
	TransInfo.Scale = Vector3(246.0f, 166.0f);

	strKey = "Select";

	Number = MENUID::ZERO;

	Time = GetTickCount64();
}

int MenuButton::Update()
{
	if (Time + 100 < GetTickCount64())
	{
		// ** 윗키
		if (GetAsyncKeyState(VK_UP))
		{
			if(TransInfo.Position.y > 420)
				TransInfo.Position.y -= 200;			
		}

		// ** 아랫키
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (TransInfo.Position.y < 820)
				TransInfo.Position.y += 200;
		}

		// ** 스페이스바 확인 버튼
		if (GetAsyncKeyState(VK_SPACE))
		{
			if (TransInfo.Position.y == 420)
				Number = MENUID::START;
			else if (TransInfo.Position.y == 620)
				Number = MENUID::HELP;
			else if (TransInfo.Position.y == 820)
				Number = MENUID::EXIT;
		}

		Time = GetTickCount64();
	}

	return 0;
}

void MenuButton::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		0,	0,
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));
}

void MenuButton::Release()
{

}


