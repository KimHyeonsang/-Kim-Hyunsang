#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*  ��������� ���������� ������
* 
* ���� ���� 
* ���� ����� �޸𸮺��簡 �̷�����Ƿ� �����ؾ��� ����� �������� ���
* ���� ���� ���簡 �̷�� ���°��� �ƴ϶� �ּҺ��簡 �̷�� ���Ƿ�
* �޸� ���簡 �̷���� ��ŭ �޸� �������� �����͸� ����Ű�� �ּҸ� �����ϰ� �ǰ�,
* ���� �����Ͱ� ������� �������� ��� �ּ��� �����Ͱ� ������Եȴ�
* �����ʹ� �ϳ��� �ش� �����͸� ī��Ű�� �ּҸ� �����޾ұ� ������ 
* �����Ͱ� �����Ǹ� �ּҸ� �����޾Ҵ� ������ ���̻� �����͸�  ����� �� ���� �ȴ�.
* 
* [��������]
* �����͸� ������ �� �ּҰ� ����Ű�� �ִ� ���� ���� �����͸� �����ϹǷ�,
* ���� �����Ͱ� ���� �Ǵ��� ������ �������� �ս��� ����.* 
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
	void Input() //�Է��ϴ�.
	{
		char Buffer[1024] = "";
		cout << "�̸� �Է� :";
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
	//��������
	AAA aaa((char*)"ȫ�浿");
	AAA bbb(aaa);

	//��������
	/*
	AAA* aaa = new AAA((char*)"ȫ�浿");
	AAA* bbb = new AAA((aaa));

	aaa->Output();
	delete aaa;

	bbb->Output();

	*/


//	aaa.Input();

	aaa.Output();
	return 0;
}