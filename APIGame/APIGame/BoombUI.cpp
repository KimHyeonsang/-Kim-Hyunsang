#include "BoombUI.h"
#include"ObjectManager.h"
#include"Player.h"
#include"BoombCount.h"

BoombUI::BoombUI()
{

}

BoombUI::~BoombUI()
{

}

void BoombUI::Initialize()
{
	TransInfo.Position = Vector3(40, 900);
	TransInfo.Scale = Vector3(15.0f, 18.0f);
	strKey = "Boomb";

	Offset = Vector3(40,60);

	m_BoombCount = new BoombCount;
	m_BoombCount->Initialize();
	m_BoombCount->SetPosition(90, 900);
	
}

int BoombUI::Update()
{
	m_BoombCount->Update();

	return 0;
}

void BoombUI::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int((TransInfo.Position.x - (TransInfo.Scale.x / 2))),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x * 2),
		int(TransInfo.Scale.y * 2),
		ImageList[strKey]->GetMemDC(),
		0,
		0,
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));

	m_BoombCount->Render(_hdc);
}

void BoombUI::Release()
{
}


