#pragma once
#include"Header.h"

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
	// ** 메뉴 이동 물체
	Object* pSelect;
public:
	// ** 초기화
	void Initialize();

	// ** 객체 생성
//	Object* CreateObject(string _Key);
//
//	// ** 컨테이너에서 객체를 찾음
//	void FindObject(string _Key);
//
//	// ** 객체 생성
//	Object* CreateObject(string _Key, Vector3 _Position);
//
//	// ** 컨테이너에서 객체를 찾음
//	void FindObject(string _Key, Vector3 _Position);
//
//	// ** 객체 추가.
//	void AddObject(string _strKey);
//
//	// ** 사용후 더이상 사용하지 않는 오브젝트 회수
//	void RecallObject(Object* _Object);
//
//	// ** 현재 타겟의 위치를 갖는다.
//	Object* GetTarget(Vector3 _Pos);

	void Release();

public:
	// ** 플레이어를 반환.
	Object* GetPlayer() {return pPlayer;}
	void SetPlayer(Object* _pPlayer) {	pPlayer = _pPlayer;	}

	// ** 선택 화살표를 반환.
	Object* GetSelect() {return pSelect;}
	void SetSelect(Object* _pSelect) {	pSelect = _pSelect;	}

private:
	ObjectManager() : pPlayer(nullptr) { }
public:
	~ObjectManager() {	Release();	}
};

