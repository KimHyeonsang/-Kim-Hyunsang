#include<vector>
#include<list>
#include<Windows.h>
#include<string>
#include <iostream>
using namespace std;

struct StudentScore
{
	char* Name;
	int Kor;
	int Eng;
	int Math;
};

int main(void)
{
	list<StudentScore*> StudentScoreList;
	StudentScore* StScore = new StudentScore;
	list<StudentScore*>::iterator iter;
	
	StScore->Name = "ȫ�浿";
	StScore->Kor = 1;
	StScore->Eng = 2;
	StScore->Math = 3;
	StudentScoreList.push_back(StScore);
	StScore->Name = "�Ӳ���";
	StScore->Kor = 10;
	StScore->Eng = 20;
	StScore->Math = 30;
	StudentScoreList.push_back(StScore);
	StScore->Name = "�̸���";
	StScore->Kor = 100;
	StScore->Eng = 200;
	StScore->Math = 300;
	StudentScoreList.push_back(StScore);


	for (iter = StudentScoreList.begin(); iter != StudentScoreList.end(); ++iter)
	{
		StudentScore* a = *iter;
		cout << a->Name << endl;
		cout << "���� ���� :" << a->Kor << endl;
		cout << "���� ���� :" << a->Eng << endl;
		cout << "���� ���� :" << a->Math << endl;
	}

	
		
	/*************************************************************
	* [���]
	*
	* ȫ�浿
	* �������� : 1
	* �������� : 2
	* �������� : 3
	*
	* �Ӳ���
	* �������� : 10
	* �������� : 20
	* �������� : 30
	*
	* �̸���
	* �������� : 100
	* �������� : 200
	* �������� : 300
	**************************************************************/

	return 0;
}


/*

int main(void)
{
	list<StudentScore*>SudentScoreList;
	/***********************************************
	* 
	* 
	* 
	* 
	* 
	* 
	* 
	* 
	* 
	* 
	* 
	* /




	vector<int> NumberList;

	for (int i = 0; i < 10; i++)
		NumberList.push_back(i);

	for (int i = 0; i < 10; ++i)
		cout << NumberList[i] << endl;

	for (int i = 0; i < NumberList.size(); ++i)
		cout << NumberList[i] << endl;


	list<int> NumberList;

	for (int i = 0; i < 10; i++)
		NumberList.push_back(i);

	list<int>::iterator itr =  NumberList;
	for (int i = 0; i < 10; ++i)
		cout << NumberList[i] << endl;



	return 0;
}
*/