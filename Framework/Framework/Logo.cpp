#include "Logo.h"
#include "Player.h"
#include "Enemy.h"

#include "SceneManager.h"


Logo::Logo()
{

}

Logo::~Logo()
{

}

void Logo::Initialize()
{

}

void Logo::Update()
{
	cout << "Logo::Update" << endl;

	if (GetAsyncKeyState('A'))
	{
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
	}
}

void Logo::Render()
{
	cout << "Logo::Render" << endl;
}

void Logo::Release()
{

}
