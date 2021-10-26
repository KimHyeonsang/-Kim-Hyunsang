#pragma once
#include<Windows.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<random>
using namespace std;


#pragma comment(lib,"msimg32.lib")

#include<fmod.hpp>
#pragma comment(lib,"fmod_vc.lib")

using namespace FMOD;

extern HWND g_hWnd;

#include"Enum.h"
#include"Bitmap.h"
#include"Constant.h"
#include"Struct.h"

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