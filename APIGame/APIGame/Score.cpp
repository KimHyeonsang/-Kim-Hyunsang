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
	TransInfo.Position = Vector3((WindowsWidth / 2), 50.0f);
	TransInfo.Scale = Vector3(38.5f, 58.0f);
	strKey = "Number";
	
	m_iScore = 0;

	Ten_Thousand = 0;
	Thousand = 0;
	Hundred = 0;
	Ten = 0;
	One = 0;

}

int Score::Update()
{
	if (m_iScore >= 10000)
	{
		Ten_Thousand = m_iScore / 10000;
		Thousand = (m_iScore % 10000) / 1000;
		Hundred = ((m_iScore % 10000) % 1000) / 100;
		Ten = (((m_iScore % 10000) % 1000) % 100) / 10;
		One = (((m_iScore % 10000) % 1000) % 100) % 10;
	}
	else if (m_iScore >= 1000)
	{
		Thousand = m_iScore / 1000;
		Hundred = (m_iScore % 1000) / 100;
		Ten = ((m_iScore % 1000) % 100) / 10;
		One = (((m_iScore % 1000) % 100) % 10);
	}
	else if (m_iScore >= 100)
	{
 		Hundred = m_iScore / 100;
		Ten = (m_iScore % 100) / 10;
		One = ((m_iScore % 100) % 10);
	}
	else if (m_iScore >= 10)
	{
		Ten = m_iScore / 10;
		One = Ten;
	}
	else if (m_iScore >= 1)
		One = m_iScore;


    return 0;
}

void Score::Render(HDC _hdc)
{
	// ** 만단위
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int((TransInfo.Position.x - (TransInfo.Scale.x / 2) - (38 * 2))),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x * Ten_Thousand),
		int(TransInfo.Scale.y * 0),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));

	// ** 천단위
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int((TransInfo.Position.x - (TransInfo.Scale.x / 2) - 38)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x * Thousand),
		int(TransInfo.Scale.y * 0),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));

	// ** 백단위
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int((TransInfo.Position.x - (TransInfo.Scale.x / 2))),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x * Hundred),
		int(TransInfo.Scale.y * 0),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));

	// ** 십단위
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int((TransInfo.Position.x - (TransInfo.Scale.x / 2) + 38)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x * Ten),
		int(TransInfo.Scale.y * 0),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));

	// ** 일단위

	TransparentBlt(_hdc, // ** 최종 출력 위치
		int((TransInfo.Position.x - (TransInfo.Scale.x / 2) + (38 * 2))),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x * One),
		int(TransInfo.Scale.y * 0),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));

}

void Score::Release()
{
}


