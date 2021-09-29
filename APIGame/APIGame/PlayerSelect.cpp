#include "PlayerSelect.h"
#include"SceneManager.h"

PlayerSelect::PlayerSelect()
{

}

PlayerSelect::~PlayerSelect()
{

}

void PlayerSelect::Initalize()
{

}

void PlayerSelect::Update()
{
	// 방향키를 위 아래 이동을 할때 사람이미지가 움직이고
	

	// 임시	
	SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
	
}

void PlayerSelect::Render(HDC _hdc)
{
	// 캐릭터 위 아래 이미지 출력
	// 사람이미지로 내가 선택한 비행기  출력
}

void PlayerSelect::Release()
{

}


