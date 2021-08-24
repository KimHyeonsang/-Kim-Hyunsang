#pragma once
#include"Headers.h"

class InputManager
{
private:
	static InputManager* Instance;
public:
	static InputManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new InputManager;

		return Instance;
	}
private:
	DWORD Key;
public:
	DWORD GetKey() const{ return Key; }
	void CheckKey();
private:
	InputManager() : Key(0) { }
public:
	~InputManager();

};

//inline의조건 짧아야하고 복잡하지 않아야한다.