#include "Boomb.h"
#include"ObjectManager.h"


Boomb::Boomb()
{

}

Boomb::~Boomb()
{

}

void Boomb::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(0.0f, 1.0f);
	TransInfo.Scale = Vector3(15.0f, 18.0f);

	strKey = "Boomb";

	Damage = 10;

	Speed = 3;

	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();

	Pos = m_pPlayer->GetPosition();

}

int Boomb::Update()
{
	TransInfo.Position.x += TransInfo.Direction.x * Speed;
	TransInfo.Position.y -= TransInfo.Direction.y * Speed;

	

	// ** 일정거리되면 터지기 캐릭터 위치 - 일정거리
	if (TransInfo.Position.y <= ( Pos.y - 300))
		return 1;
	
    return 0;
}

void Boomb::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x),
		int(TransInfo.Position.y),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		0,
		0,
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));
}


void Boomb::Release()
{
}


