#include "Player.h"
#include"ObjectFactory.h"
#include"ObjectManager.h"
#include"InputManager.h"

#include"Bullet.h"
#include"NormalBullet.h"
#include"Boomb.h"
#include"SoundManager.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::Initialize()
{
	TransInfo.Position = Vector3(WindowsWidth / 2, 750);
	TransInfo.Scale = Vector3(54.0f, 84.0f);

	strKey = "Player1";
	// ** ½ºÇÇµå
	Speed = 5.0f;

	// ** ¸ñ¼û
	Hart = 2;
	// ** ÃÑ¾Ë ¾÷±Û°¹¼ö
	Bullet_Upgrade = 0;
	// ** ÆøÅº °¹¼ö
	iBoomb = 9;

	BulletList = ObjectManager::GetInstance()->GetBulletList();
	BoombList = ObjectManager::GetInstance()->GetBoombtList();

	Time = GetTickCount64();
}

int Player::Update()
{
	if (GetAsyncKeyState(VK_UP))
	{
		if(TransInfo.Position.y  > 0)
			TransInfo.Position.y -= Speed;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		if (TransInfo.Position.y + (TransInfo.Scale.y ) <= WindowsHeight - 50)
			TransInfo.Position.y += Speed;		
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		if(TransInfo.Position.x  > 0)
			TransInfo.Position.x -= Speed;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		if(TransInfo.Position.x + (TransInfo.Scale.x ) <= WindowsWidth - 25)
			TransInfo.Position.x += Speed;
	}

	if (GetAsyncKeyState('Z'))
	{
		// ÆøÅº °¹¼ö°¡ 0 ÀÌ»óÀÏ¶§
		if (iBoomb > 0)
		{
			if (Time + 500 < GetTickCount64())
			{
				SoundManager::GetInstance()->OnPlaySound("BoombShoot");

				Vector3 Pos;
				Pos.x = TransInfo.Position.x + (TransInfo.Scale.x / 2) - 8;
				Pos.y = TransInfo.Position.y - 10;

				Object* pBoomb = ObjectFactory<Boomb>::CreateObject(Pos);
				BoombList->push_back(pBoomb);
				--iBoomb;

				Time = GetTickCount64();
			}
		}
	}
			

	if (GetAsyncKeyState(VK_SPACE))
	{
		if (Time + 50 < GetTickCount64())
		{
			SoundManager::GetInstance()->OnPlaySound("Shoot");

			if(Bullet_Upgrade == 0)
 				BulletList->push_back(CreateBullet<NormalBullet>());
			if (Bullet_Upgrade == 1)
			{

			}
			if (Bullet_Upgrade == 2)
			{

			}
		}
		Time = GetTickCount64();
	}

	return 0;
}

void Player::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** ÃÖÁ¾ Ãâ·Â À§Ä¡
		int(TransInfo.Position.x ),
		int(TransInfo.Position.y ),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		0,
		0,
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));
}

void Player::Release()
{
}

void Player::SetNumber(int _Number)
{
	PlayerNumber = _Number;

	switch (PlayerNumber)
	{
	case 0:
		strKey = "Player1";
		break;
	case 1:
		strKey = "Player2";
		break;
	case 2:
		strKey = "Player3";
		break;
	case 3:
		strKey = "Player4";
		break;
	}
}

template<typename T>
inline Object* Player::CreateBullet()
{
	Bridge* pBridge = new T;

	Vector3 Pos; 
	Pos.x = TransInfo.Position.x + (TransInfo.Scale.x / 2) - 8;
	Pos.y = TransInfo.Position.y - 10;
	Object* pBullet = ObjectFactory<Bullet>::CreateObject(Pos  , pBridge);

	return pBullet;
}
