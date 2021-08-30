#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*  깊은복사와 얕은복사의 차이점
* 
* 얕은 복사 
* 앝은 복사란 메모리복사가 이루어지므로 복사해야할 대상이 포인터인 경우
* 실제 값의 복사가 이루어 지는것이 아니라 주소복사가 이루어 지므로
* 메모리 복사가 이루어진 만큼 메모리 공간에서 데이터를 가르키는 주소를 참조하게 되고,
* 기존 데이터가 사라지면 참조받은 모든 주소의 데이터가 사라지게된다
* 데이터는 하나고 해당 데이터를 카르키는 주소만 참조받았기 떄문에 
* 데이터가 삭제되면 주소를 참조받았던 곳에서 더이상 데이터를  사용할 수 없게 된다.
* 
* [깊은복사]
* 데이터르 복사할 떄 주소가 가르키고 있는 곳의 실제 데이터를 복사하므로,
* 기존 데이터가 삭제 되더라도 복제된 데이터의 손실이 없다.* 
*/


class AAA
{
private:
	char* Name;
public:
	AAA() {}
	AAA(char* _name) :Name(_name) 
	{
		Name = new char[strlen(_name) + 1];
		strcpy(Name, _name);
	}
	/*
	void Input() //입력하다.
	{
		char Buffer[1024] = "";
		cout << "이름 입력 :";
		cin >> Buffer;

		Name = new char[strlen(Buffer)];
		strcpy(Name, Buffer);
		
	}
	*/
	void Output()
	{
		cout << Name << endl;
	}
};


int main(void)
{
	//얕은복사
	AAA aaa((char*)"홍길동");
	AAA bbb(aaa);

	//깊은복사
	/*
	AAA* aaa = new AAA((char*)"홍길동");
	AAA* bbb = new AAA((aaa));

	aaa->Output();
	delete aaa;

	bbb->Output();

	*/


//	aaa.Input();

	aaa.Output();
	return 0;
}