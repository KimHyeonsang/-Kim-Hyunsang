#include "ObjectManager.h"
#include"Object.h"

ObjectManager* ObjectManager::Instance = nullptr;

void ObjectManager::AddObject(Object* _object)
{	
	//키값 받기
	string Key = _object->GetKey();
	
	//list의 값 저장
	list< Object*>* ObjList = FindList(Key);

	//값이 없으면 map의 저장
	if (ObjList == nullptr)
	{
		list<Object*> TempList;
		TempList.push_back(_object);
		ObjectList.insert(make_pair(Key, TempList));
	}
	else
	{
		//값이 있으면 바로 저장
		ObjList->push_back(_object);
	}

}


void ObjectManager::Release()
{
	//map에 저장된 순서대로 불러오기
	for (map<string, list<Object*>>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
	{
		//map안에있는 list를 순서대로 지우기
		for (list<Object*>::iterator List_iter = iter->second.begin();
			List_iter != iter->second.end(); ++List_iter)
		{
			delete (*List_iter);
			(*List_iter) = nullptr;
		}
		iter->second.clear();
	}
	ObjectList.clear();
}
