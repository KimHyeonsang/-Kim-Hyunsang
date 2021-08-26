#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;

		return Instance;
	}
private:
	// ** �÷��̾�
	Object* pPlayer;

	// ** ������Ʈ ����Ʈ
	// ** ������� ��ü
	map<string, list<Object*>> EnableList;

	// ** ������� �ʴ� ��ü
	map<string, list<Object*>> DisabletList;
public:
	void FindObject();
	void AddObject(string _strKey);
	void Release();
public:
	// ** �÷��̾ ��ȯ.
	Object* GetPlayer() { return pPlayer; }
	void SetPlayer(Object* _pPlayer) { pPlayer = _pPlayer; }

	// ** map �����̳ʸ� ����ϰ��ִ� ObjectList�� ��ȯ.
	map<string, list<Object*>>* GetEndableList() { return &EnableList; }
	map<string, list<Object*>>* GetDisabletList() { return &DisabletList;	}

	// ** map �����̳ʸ� ����ϰ��ִ� ObjectList�� ���Ե� list �� Ž���Ͽ� ��ȯ.
	list<Object*>* FindList(string _Key) 
	{
		map<string, list<Object*>>::iterator iter = DisabletList.find(_Key);

		// ** �������� �ʴ� key������ nullptr�� ��ȯ.
		if (iter == DisabletList.end())
			return nullptr;

		return &iter->second;
	}
private:
	ObjectManager() : pPlayer(nullptr) { }
public:
	~ObjectManager() { Release(); }
};

