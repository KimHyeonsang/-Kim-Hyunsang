#include "Player.h"
#include"ObjectFactory.h"
#include"ObjectManager.h"
#include"InputManager.h"

#include"Bullet.h"
#include"NormalBullet.h"
#include"Boomb.h"


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

	// ** �浹 ��ġ�� ũ��
	Collider.Position = Vector3(TransInfo.Position.x, TransInfo.Position.y - 20.0f);
	Collider.Scale = Vector3(54.0f, 54.0f);

	strKey = "Player1";
	// ** ���ǵ�
	Speed = 5.0f;

	// ** ���
	Hart = 2;
	// ** �Ѿ� ���۰���
	Bullet_Upgrade = 0;
	// ** ��ź ����
	iBoomb = 1;

	Offset = Vector3(95.0f, -85.0f);
	BulletList = ObjectManager::GetInstance()->GetBulletList();
	BoombList = ObjectManager::GetInstance()->GetBoombtList();

	Time = GetTickCount64();
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

	if (GetAsyncKeyState('Z'))
	{
		// ��ź ������ 0 �̻��϶�
		if (iBoomb > 0)
		{
			Object* pBoomb = ObjectFactory<Boomb>::CreateObject(TransInfo.Position);
			BoombList->push_back(pBoomb);
			--iBoomb;
		}
	}
			

	if (GetAsyncKeyState(VK_SPACE))
	{
		if (Time + 100 < GetTickCount64())
		{
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

//	DWORD dwKey = InputManager::GetInstance()->GetKey();

	return 0;
}

void Player::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** ���� ��� ��ġ
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
