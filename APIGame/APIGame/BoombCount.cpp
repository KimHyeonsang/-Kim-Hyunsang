#include "BoombCount.h"
#include"Player.h"
#include"ObjectManager.h"

BoombCount::BoombCount()
{

}

BoombCount::~BoombCount()
{

}
void BoombCount::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(38.5f, 58.0f);
	strKey = "Number";
	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	Frame_x = ((Player*)m_pPlayer)->GetBoomb();
	

	
	
}

int BoombCount::Update()
{
	Frame_x = ((Player*)m_pPlayer)->GetBoomb();



	return 0;
}

void BoombCount::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int((TransInfo.Position.x - (TransInfo.Scale.x / 2))),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x * Frame_x),
		int(TransInfo.Scale.y * 0),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));
}

void BoombCount::Release()
{
}


