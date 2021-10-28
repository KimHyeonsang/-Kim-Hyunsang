#include "PlayerSelect.h"
#include"SceneManager.h"
#include"ObjectManager.h"
#include"Player.h"
#include"Logo_Back.h"
#include"SoundManager.h"

PlayerSelect::PlayerSelect()
{

}

PlayerSelect::~PlayerSelect()
{

}

void PlayerSelect::Initalize()
{
	TransInfo.Scale = Vector3(120.0f, 186.0f);
	TransInfo.Position = Vector3(110 - (TransInfo.Scale.x / 2), 445 - (TransInfo.Scale.y / 2));

	m_iPointx = TransInfo.Position.x;

	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	LogoBack = new Logo_Back;
	LogoBack->Initialize();

	ImageList = Object::GetImageList();
	m_iSelect = 0;
	Time = GetTickCount64();
	MoveTime = GetTickCount64();
	m_bSelect = false;
}

void PlayerSelect::Update()
{
	// 방향키를 위 아래 이동을 할때 사람이미지가 움직이고
	if (Time + 800 < GetTickCount64())
	{
		m_bSelect = !m_bSelect;
		Time = GetTickCount64();
	}

	if (MoveTime + 500 < GetTickCount64())
	{
		if (GetAsyncKeyState(VK_LEFT))
		{
			SoundManager::GetInstance()->OnPlaySound("SelectMove");
			if (m_iSelect == 1)
			{
				--m_iSelect;
				TransInfo.Position.x = (m_iPointx  + (150 * m_iSelect));
			}
			else if (m_iSelect == 2)
			{
				--m_iSelect;
				TransInfo.Position.x = (m_iPointx + (150 * m_iSelect));
			}
			else if (m_iSelect == 3)
			{
				--m_iSelect;
				TransInfo.Position.x = (m_iPointx + (150 * m_iSelect));
			}
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			SoundManager::GetInstance()->OnPlaySound("SelectMove");
			if (m_iSelect == 0)
			{
				++m_iSelect;
				TransInfo.Position.x = (m_iPointx + (150 * m_iSelect));
			}
			else if (m_iSelect == 1)
			{
				++m_iSelect;
				TransInfo.Position.x = (m_iPointx + (150 * m_iSelect));
			}
			else if (m_iSelect == 2)
			{
				++m_iSelect;
				TransInfo.Position.x = (m_iPointx + (150 * m_iSelect));
			}
		}

		// 클릭시
		if (GetAsyncKeyState(VK_SPACE))
		{
			SoundManager::GetInstance()->OnPlaySound("Select");
			((Player*)m_pPlayer)->SetNumber(m_iSelect);
			SceneManager::GetInstance()->SetScene(SCENEID::STAGE);

		}
		MoveTime = GetTickCount64();
	}
	
	// 임시	
	
}

void PlayerSelect::Render(HDC _hdc)
{
	// // ** 배경
	LogoBack->Render(ImageList["Buffer"]->GetMemDC());

	TransparentBlt(ImageList["Buffer"]->GetMemDC(), // ** 최종 출력 위치
		int(WindowsWidth / 2 - (669 / 2)),
		int(WindowsHeight / 2 - (329 / 2)),
		669,
		329,
		ImageList["PlayerSelectScene"]->GetMemDC(),
		0, 0,
		669,
		329,
		RGB(255, 0, 255));

	
	if (m_bSelect)
	{
		// 선택 창
		TransparentBlt(ImageList["Buffer"]->GetMemDC(), // ** 최종 출력 위치
			int(TransInfo.Position.x),
			int(TransInfo.Position.y),
			int(TransInfo.Scale.x * 1.3f),
			int(TransInfo.Scale.y * 1.6f),
			ImageList["PlayerSelect"]->GetMemDC(),
			0, 0,
			TransInfo.Scale.x,
			TransInfo.Scale.y,
			RGB(255, 0, 255));		
	}
	



	// 비행기 1번
	TransparentBlt(ImageList["Buffer"]->GetMemDC(), // ** 최종 출력 위치
		70,
		400,
		int(m_pPlayer->GetScale().x * 2),
		int(m_pPlayer->GetScale().y * 2),
		ImageList["Player1"]->GetMemDC(),
		0, 0,
		int(m_pPlayer->GetScale().x),
		int(m_pPlayer->GetScale().y),
		RGB(255, 0, 255));


	//플레이어 2번
	TransparentBlt(ImageList["Buffer"]->GetMemDC(), // ** 최종 출력 위치
		220,
		400,
		int(m_pPlayer->GetScale().x * 2),
		int(m_pPlayer->GetScale().y * 2),
		ImageList["Player2"]->GetMemDC(),
		0, 0,
		int(m_pPlayer->GetScale().x),
		int(m_pPlayer->GetScale().y),
		RGB(255, 0, 255));

	//플레이어 3번
	TransparentBlt(ImageList["Buffer"]->GetMemDC(), // ** 최종 출력 위치
		370,
		400,
		int(m_pPlayer->GetScale().x * 2),
		int(m_pPlayer->GetScale().y * 2),
		ImageList["Player3"]->GetMemDC(),
		0, 0,
		int(m_pPlayer->GetScale().x),
		int(m_pPlayer->GetScale().y),
		RGB(255, 0, 255));

	//플레이어 4번
	TransparentBlt(ImageList["Buffer"]->GetMemDC(), // ** 최종 출력 위치
		520,
		400,
		int(m_pPlayer->GetScale().x * 2),
		int(m_pPlayer->GetScale().y * 2),
		ImageList["Player4"]->GetMemDC(),
		0, 0,
		int(m_pPlayer->GetScale().x),
		int(m_pPlayer->GetScale().y),
		RGB(255, 0, 255));

	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);

}

void PlayerSelect::Release()
{

}


