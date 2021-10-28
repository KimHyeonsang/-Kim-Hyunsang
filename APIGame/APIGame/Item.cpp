#include "Item.h"

Item::Item()
{

}

Item::~Item()
{

}

void Item::Initialize()
{
	random_device rd;
	srand(rd());
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(53.0f, 53.0f);

	strKey = "BoombItem";
	ItemNumber = 0;
	Speed = 2.0f;
	Angle = -0.4f;
}

int Item::Update()
{
	// 아이템이 나오고 나서 각도에 의해 팅김
	// 몬스터가 죽으면 랜덤 각도 설정

	TransInfo.Position.x += cosf(Angle) * Speed;
	TransInfo.Position.y += -sinf(Angle) * Speed;


	//왼쪽 벽에 부딪혔을떄   
	// x축관련(좌우) 반사각을 이용해서 벽과의 충돌 구현
	// 좌우 반사각 = 180 - 입사각
	if (TransInfo.Position.x - (TransInfo.Scale.x / 2) <= 0)
	{
		Angle = PI - Angle;
	}
	if (TransInfo.Position.x + (TransInfo.Scale.x / 2) >= WindowsWidth)
	{
		Angle = PI - Angle;
	}


	//상하 반사각을 이용해 벽과의 충돌 구현
	//상하 반사각 = 360 - 입사각

	if (TransInfo.Position.y - (TransInfo.Scale.y / 2) < 0)
	{
		Angle = 2 * PI - Angle;
	}
	if (TransInfo.Position.y + (TransInfo.Scale.y / 2) > WindowsHeight)
	{
		Angle = 2 * PI - Angle;
	}
    return 0;
}

void Item::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		0, 0,
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));
}

void Item::SetNumber()
{
	// 폭탄 70퍼 일반 공격 20퍼 반사공격 10퍼
	int Number = rand() % 100;

	if (Number < 70)
	{
		strKey = "BoombItem";
		ItemNumber = 0;
	}
	else if (Number >= 70 && Number < 90)
	{
  		strKey = "NomalBulletItem";
		ItemNumber = 1;
	}
	else
	{
		strKey = "ReflectionBulletItem";
		ItemNumber = 2;
	}
}

void Item::Release()
{
}


