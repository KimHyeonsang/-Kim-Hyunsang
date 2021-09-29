#include "SceneManager.h"

#include"Logo.h"
#include"Menu.h"
#include"HelpScene.h"
#include"PlayerSelect.h"
#include"Stage01.h"

SceneManager* SceneManager::Instance = nullptr;

void SceneManager::SetScene(SCENEID _SceneID)
{
	::Safe_Delete(pSceneState);


	switch (_SceneID)
	{
	case SCENEID::LOGO:
		pSceneState = new Logo;
		break;
	case SCENEID::MENU:
		pSceneState = new Menu;
		break;
	case SCENEID::HELPSCENE:
		pSceneState = new HelpScene;
		break;
	case SCENEID::PLAYERSELECTSCENE:
		pSceneState = new PlayerSelect;
		break;
	case SCENEID::STAGE:
		pSceneState = new Stage01;
		break;
	case SCENEID::EXIT:
		exit(NULL);
		break;
	}
	pSceneState->Initalize();


}

void SceneManager::Update()
{
	pSceneState->Update();
}

void SceneManager::Render(HDC _hdc)
{
	pSceneState->Render(_hdc);
}

void SceneManager::Release()
{
	::Safe_Delete(pSceneState);
}
