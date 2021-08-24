#include "ObjectManager.h"
#include"Object.h"

ObjectManager* ObjectManager::Instance = nullptr;

void ObjectManager::AddObject(Object* _object)
{	
	//Ű�� �ޱ�
	string Key = _object->GetKey();
	
	//list�� �� ����
	list< Object*>* ObjList = FindList(Key);

	//���� ������ map�� ����
	if (ObjList == nullptr)
	{
		list<Object*> TempList;
		TempList.push_back(_object);
		ObjectList.insert(make_pair(Key, TempList));
	}
	else
	{
		//���� ������ �ٷ� ����
		ObjList->push_back(_object);
	}

}


void ObjectManager::Release()
{
	//map�� ����� ������� �ҷ�����
	for (map<string, list<Object*>>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
	{
		//map�ȿ��ִ� list�� ������� �����
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
