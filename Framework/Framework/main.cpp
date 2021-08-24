#include "Headers.h"
#include "MainUpdate.h"
#include"InputManager.h"
/*********************************************
class AAA
{
public:
	int Number;
public:
	AAA();
	AAA(const int& _Number) : Number(_Number) { }
	~AAA();
};

AAA::AAA() : Number(0)
{
	cout << "생성자 호출" << endl;
}

AAA::~AAA()
{
	cout << "소멸자 호출" << endl;
}


void Add(int& _Number1, int _Number2)
{
	_Number1 += _Number2;
}

void Add(int* _Number1, int _Number2)
{
	(*_Number1) += _Number2;
}
**********************************************/

float FrameTime = 1000.0f;

int main(void)
{
	//****************************************
	// 	   예제
	//int i = 10, n = 20;
	//Add(i, n);

	//cout << i << endl;
	//****************************************
	


	MainUpdate Main;
	Main.Initialize();
	
	ULONGLONG Time = GetTickCount64(); // 1/1000 초를 반환 하는 함수

	while (true)
	{
		if (Time + FrameTime < GetTickCount64())
		{
			system("cls");
			Time = GetTickCount64();

			

			//** 루프
			Main.Update();
			Main.Render();

		}
	}

	return 0;
}
