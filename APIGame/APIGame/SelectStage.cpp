#include "SelectStage.h"
#include"SceneManager.h"

SelectStage::SelectStage()
{

}

SelectStage::~SelectStage()
{
	Release();
}
void SelectStage::Initalize()
{
//	ImageList = Object::GetImageList();
}

void SelectStage::Update()
{
}

void SelectStage::Render(HDC _hdc)
{
	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void SelectStage::Release()
{
}


