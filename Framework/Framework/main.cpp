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
	cout << "������ ȣ��" << endl;
}

AAA::~AAA()
{
	cout << "�Ҹ��� ȣ��" << endl;
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
	// 	   ����
	//int i = 10, n = 20;
	//Add(i, n);

	//cout << i << endl;
	//****************************************
	


	MainUpdate Main;
	Main.Initialize();
	
	ULONGLONG Time = GetTickCount64(); // 1/1000 �ʸ� ��ȯ �ϴ� �Լ�

	while (true)
	{
		if (Time + FrameTime < GetTickCount64())
		{
			system("cls");
			Time = GetTickCount64();

			

			//** ����
			Main.Update();
			Main.Render();

		}
	}

	return 0;
}
