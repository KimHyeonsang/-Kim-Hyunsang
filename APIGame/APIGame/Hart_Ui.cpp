#include "Hart_Ui.h"
#include"ObjectManager.h"

Hart_Ui::Hart_Ui()
{

}

Hart_Ui::~Hart_Ui()
{

}

void Hart_Ui::Initialize()
{
	TransInfo.Position = Vector3(50, 50);
	TransInfo.Scale = Vector3(70.0f, 46.0f);
	strKey = "Hart";

	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();
}

int Hart_Ui::Update()
{
    return 0;
}

void Hart_Ui::Render(HDC _hdc)
{
	for (int i = 0; i < m_pPlayer->GetHart(); ++i)
	{
		TransparentBlt(_hdc, // ** 최종 출력 위치
			int((TransInfo.Position.x - (TransInfo.Scale.x / 2) ) + (60 * i)),
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
}

void Hart_Ui::Release()
{
}


