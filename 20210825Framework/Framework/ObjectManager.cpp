#include "ObjectManager.h"
#include"ObjectFactory.h"
#include "Object.h"
#include"Enemy.h"

ObjectManager* ObjectManager::Instance = nullptr;




void ObjectManager::FindObject()
{
	// ** DisableList�� �����Ϸ��� ������Ʈ�� �ִ��� Ȯ��.

	// ** �ִٸ� EnableList�� �̵���Ŵ

	// ** ���ٸ� AddObject()����.

	// ** �׸��� �ٽ� EnableList�� �̵���Ŵ



}

void ObjectManager::AddObject(string _strKey)
{
	// ** Ű������ Ž���� Ž���� �Ϸ�� ������� ��ȯ.
	map<string, list<Object*>>::iterator Disableiter = DisabletList.find(_strKey);

	for (int i = 0; i < 5; ++i)
	{
		// ** Object ��ü�� ����
		Object* pObj = ObjectFactory<Enemy>::CreateObject();

		// ** ���� ������� �������� �ʴ´ٸ�....
		if (Disableiter == DisabletList.end())
		{
			// ** ���ο� ����Ʈ�� ����.
			list<Object*> TempList;


			// ** ������Ʈ�� �߰��� ����Ʈ�� �ʿ� ����.
			DisabletList.insert(make_pair(_strKey, TempList));
		}
		// ** ������� ���� �Ѵٸ�...
		else
			// ** �ش� ����Ʈ�� ������Ʈ�� �߰�
			Disableiter->second.push_back(pObj);
	}
}

void ObjectManager::Release()
{
	// ** ������ ����.
	::Safe_Delete(pPlayer);

	for (map<string, list<Object*>>::iterator iter = DisabletList.begin();
		iter != DisabletList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			::Safe_Delete((*iter2));
		}
		iter->second.clear();
	}
	DisabletList.clear();

	for (map<string, list<Object*>>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			::Safe_Delete((*iter2));
		}
		iter->second.clear();
	}
	EnableList.clear();
}
