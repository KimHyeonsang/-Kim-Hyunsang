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
	// ** 플레이어
	Object* pPlayer;

	// ** 오브젝트 리스트
	// ** 사용중인 객체
	map<string, list<Object*>> EnableList;

	// ** 사용하지 않는 객체
	map<string, list<Object*>> DisabletList;
public:
	void FindObject();
	void AddObject(string _strKey);
	void Release();
public:
	// ** 플레이어를 반환.
	Object* GetPlayer() { return pPlayer; }
	void SetPlayer(Object* _pPlayer) { pPlayer = _pPlayer; }

	// ** map 컨테이너를 사용하고있는 ObjectList를 반환.
	map<string, list<Object*>>* GetEndableList() { return &EnableList; }
	map<string, list<Object*>>* GetDisabletList() { return &DisabletList;	}

	// ** map 컨테이너를 사용하고있는 ObjectList에 포함된 list 를 탐색하여 반환.
	list<Object*>* FindList(string _Key) 
	{
		map<string, list<Object*>>::iterator iter = DisabletList.find(_Key);

		// ** 존재하지 않는 key값에는 nullptr를 반환.
		if (iter == DisabletList.end())
			return nullptr;

		return &iter->second;
	}
private:
	ObjectManager() : pPlayer(nullptr) { }
public:
	~ObjectManager() { Release(); }
};

