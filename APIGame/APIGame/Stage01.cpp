#include "Stage01.h"
#include"SceneManager.h"
#include"ObjectManager.h"
#include"ObjectFactory.h"
#include"Player.h"
#include"Logo_Back.h"

Stage01::Stage01()
{

}

Stage01::~Stage01()
{
	Release();
}

void Stage01::Initalize()
{
	// ** 플레이어를 오브젝트매니저에서 받아온다.
	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();

	// ** 총알을 오브젝트 매니저에서 받아온다.
	BulletList = ObjectManager::GetInstance()->GetBulletList();

	LogoBack = new Logo_Back;
	LogoBack->Initialize();

	ImageList = Object::GetImageList();
}

void Stage01::Update()
{
	m_pPlayer->Update();



	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end();)
	{
		int iResult = (*iter)->Update();

		// ** 총알을 삭제하는 구간.
		if (iResult == 1)
			iter = BulletList->erase(iter);
		else
			++iter;
	}


}

void Stage01::Render(HDC _hdc)
{
	LogoBack->Render(ImageList["Buffer"]->GetMemDC());

	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

	m_pPlayer->Render(ImageList["Buffer"]->GetMemDC());

	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Stage01::Release()
{
}


