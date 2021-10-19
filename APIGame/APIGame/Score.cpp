#include "Score.h"
#include"ObjectManager.h"
#include"Player.h"

Score::Score()
{

}

Score::~Score()
{

}

void Score::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(40.0f, 60.0f);
	strKey = "Number";
	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	Frame_x = ((Player*)m_pPlayer)->GetBoomb();
	Frame_y = 0;

	if (Frame_x / 4 >= 2)
	{
		Frame_y = 1;
		Frame_x -= 5;
	}
}

int Score::Update()
{
	Frame_x = ((Player*)m_pPlayer)->GetBoomb();
	Frame_y = 0;

	if (Frame_x / 4 >= 1)
	{
		if (Frame_x != 4)
		{
			Frame_y = 1;
			Frame_x -= 5;
		}		
	}

    return 0;
}

void Score::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int((TransInfo.Position.x - (TransInfo.Scale.x / 2))),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x * Frame_x),
		int(TransInfo.Scale.y * Frame_y),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));
}

void Score::Release()
{
}


