#include "ObjectManager.h"
#include"ObjectFactory.h"
#include"Boomb.h"

ObjectManager* ObjectManager::Instance = nullptr;

void ObjectManager::Initialize()
{

}



void ObjectManager::AddBoomb(Vector3 _vPos)
{
	BulletList.push_back(
		ObjectFactory<Boomb>::CreateObject(_vPos));
}

void ObjectManager::Release()
{
	
}


