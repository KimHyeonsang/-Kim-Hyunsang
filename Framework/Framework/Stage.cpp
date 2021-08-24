#include "Stage.h"
#include "SceneManager.h"
#include"InputManager.h"

Stage::Stage()
{

}

Stage::~Stage()
{

}

void Stage::Initialize()
{
	FrameTime = 0;
}

void Stage::Update()
{
	cout << "Stage::Update" << FrameTime << endl;


	if (GetAsyncKeyState('D'))
	{
		SceneManager::GetInstance()->SetScene(SCENEID::EXIT);
	}

	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & 1)
		FrameTime += 50;
	if (dwKey & 2)
		FrameTime -= 50;

	if (FrameTime < 0)
		FrameTime = 0;
	if (dwKey & 4)
		cout << "Left" << endl;
	if (dwKey & 8)
		cout << "Right" << endl;
	if (dwKey & 16)
		cout << "VK_SPACE" << endl;
	if (dwKey & 32)
		cout << "VK_ESCAPE" << endl;
	if (dwKey & 64)
		cout << "VK_RETURN" << endl;
}

void Stage::Render()
{
	cout << "Stage::Render" << endl;
}

void Stage::Release()
{

}
