#pragma once
#include<Windows.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

#include"Enum.h"
#include"Bitmap.h"
#include"Constant.h"
#include"Struct.h"
#pragma comment(lib,"msimg32.lib")

extern HWND g_hWnd;

#define ENEMYMAX 100

template<typename T>
inline void Safe_Delete(T& _pObj)
{
	if (_pObj)
	{
		delete _pObj;
		_pObj = nullptr;
	}
}