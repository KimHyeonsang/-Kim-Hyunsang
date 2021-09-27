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
	// ** �÷��̾�
	Object* pPlayer;
	// ** �޴� �̵� ��ü
	Object* pSelect;
public:
	// ** �ʱ�ȭ
	void Initialize();

	// ** ��ü ����
//	Object* CreateObject(string _Key);
//
//	// ** �����̳ʿ��� ��ü�� ã��
//	void FindObject(string _Key);
//
//	// ** ��ü ����
//	Object* CreateObject(string _Key, Vector3 _Position);
//
//	// ** �����̳ʿ��� ��ü�� ã��
//	void FindObject(string _Key, Vector3 _Position);
//
//	// ** ��ü �߰�.
//	void AddObject(string _strKey);
//
//	// ** ����� ���̻� ������� �ʴ� ������Ʈ ȸ��
//	void RecallObject(Object* _Object);
//
//	// ** ���� Ÿ���� ��ġ�� ���´�.
//	Object* GetTarget(Vector3 _Pos);

	void Release();

public:
	// ** �÷��̾ ��ȯ.
	Object* GetPlayer() {return pPlayer;}
	void SetPlayer(Object* _pPlayer) {	pPlayer = _pPlayer;	}

	// ** ���� ȭ��ǥ�� ��ȯ.
	Object* GetSelect() {return pSelect;}
	void SetSelect(Object* _pSelect) {	pSelect = _pSelect;	}

private:
	ObjectManager() : pPlayer(nullptr) { }
public:
	~ObjectManager() {	Release();	}
};

