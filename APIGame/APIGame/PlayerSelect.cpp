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
	// ����Ű�� �� �Ʒ� �̵��� �Ҷ� ����̹����� �����̰�
	

	// �ӽ�	
	SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
	
}

void PlayerSelect::Render(HDC _hdc)
{
	// ĳ���� �� �Ʒ� �̹��� ���
	// ����̹����� ���� ������ �����  ���
}

void PlayerSelect::Release()
{

}


