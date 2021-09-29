#include "Player.h"
#include"ObjectFactory.h"
#include"ObjectManager.h"
#include"InputManager.h"

#include"Bullet.h"
#include"NormalBullet.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::Initialize()
{
	TransInfo.Position = Vector3(WindowsWidth / 2, 750);
	TransInfo.Scale = Vector3(108.0f, 167.0f);

	Collider.Position = Vector3(TransInfo.Position.x, TransInfo.Position.y - 20.0f);
	Collider.Scale = Vector3(120.0f, 60.0f);

	strKey = "Player1";
	Speed = 3.0f;

	Offset = Vector3(95.0f, -85.0f);
	BulletList = ObjectManager::GetInstance()->GetBulletList();
}

int Player::Update()
{
	if (GetAsyncKeyState(VK_UP))
	{
		if(TransInfo.Position.y  - (TransInfo.Scale.y / 2) > 0)
			TransInfo.Position.y -= Speed;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		if (TransInfo.Position.y + (TransInfo.Scale.y / 2) < (WindowsHeight - 30))		
			TransInfo.Position.y += Speed;		
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		if(TransInfo.Position.x  - (TransInfo.Scale.x / 2) > 0)
			TransInfo.Position.x -= Speed;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		if(TransInfo.Position.x + (TransInfo.Scale.x / 2) < (WindowsWidth - 20))
			TransInfo.Position.x += Speed;
	}

//	if (GetAsyncKeyState('Z'))
		//	Key |= KEY_ESCAPE;

		if (GetAsyncKeyState(VK_SPACE))
 			BulletList->push_back(CreateBullet<NormalBullet>());

//	DWORD dwKey = InputManager::GetInstance()->GetKey();

	return 0;
}

void Player::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
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

template<typename T>
inline Object* Player::CreateBullet()
{
	Bridge* pBridge = new T;

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, pBridge);

	return pBullet;
}

//게임엔진 프로그래밍