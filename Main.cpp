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
	
	StScore->Name = "홍길동";
	StScore->Kor = 1;
	StScore->Eng = 2;
	StScore->Math = 3;
	StudentScoreList.push_back(StScore);
	StScore->Name = "임꺽정";
	StScore->Kor = 10;
	StScore->Eng = 20;
	StScore->Math = 30;
	StudentScoreList.push_back(StScore);
	StScore->Name = "이몽룡";
	StScore->Kor = 100;
	StScore->Eng = 200;
	StScore->Math = 300;
	StudentScoreList.push_back(StScore);


	for (iter = StudentScoreList.begin(); iter != StudentScoreList.end(); ++iter)
	{
		StudentScore* a = *iter;
		cout << a->Name << endl;
		cout << "국어 점수 :" << a->Kor << endl;
		cout << "영어 점수 :" << a->Eng << endl;
		cout << "수학 점수 :" << a->Math << endl;
	}

	
		
	/*************************************************************
	* [출력]
	*
	* 홍길동
	* 국어점수 : 1
	* 영어점수 : 2
	* 수학점수 : 3
	*
	* 임꺽정
	* 국어점수 : 10
	* 영어점수 : 20
	* 수학점수 : 30
	*
	* 이몽룡
	* 국어점수 : 100
	* 영어점수 : 200
	* 수학점수 : 300
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