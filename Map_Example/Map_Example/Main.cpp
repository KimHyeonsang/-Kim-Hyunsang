#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<list>
#include<map>
#include<vector>

using namespace std;

//** ����ü
struct StudentScore
{
	char* Name;
	int Kor;
	int Math;
	int Eng;

	StudentScore() :Kor(0), Math(0), Eng(0) { }
	StudentScore(char* _Name, int _Kor, int _Math, int _Eng)
		: Name(_Name), Kor(_Kor), Math(_Math), Eng(_Eng) { }
};


// ** �̸� ����
char* SetName();

// ** ����
StudentScore* CreateStudent();

// ** �ʱ�ȭ
void Initialize(StudentScore* _pStudent);

// ** ����Ʈ�� �߰�
void AddStudent(map<string, list<StudentScore*>>* _pStudentScoreList, string _strKey);

// ** ���
void Output(map<string, list<StudentScore*>>* _pStudentScoreList);


int main(void)
{
	//** <Key, Value>
	map<string, list<StudentScore*>> StudentScoreList;

	//[S �б�] : [S�浿][S����][S����]
	//[G �б�] : [G�浿][G����][G����]
	//[A �б�] : [A�浿][A����][A����]

	/*
	list<StudentScore*> Temp;
	Temp.push_back(new StudentScore((char*)"S�浿", 1, 2, 3));
	Temp.push_back(new StudentScore((char*)"S����", 4, 5, 6));
	Temp.push_back(new StudentScore((char*)"S����", 7, 8, 9));
	StudentScoreList["S �б�"] = Temp;
	Temp.clear();

	Temp.push_back(new StudentScore((char*)"G�浿", 10, 20, 30));
	Temp.push_back(new StudentScore((char*)"G����", 40, 50, 60));
	Temp.push_back(new StudentScore((char*)"G����", 70, 80, 90));
	StudentScoreList["G �б�"] = Temp;
	Temp.clear();

	Temp.push_back(new StudentScore((char*)"A�浿", 100, 200, 300));
	Temp.push_back(new StudentScore((char*)"A����", 400, 500, 600));
	Temp.push_back(new StudentScore((char*)"A����", 700, 800, 900));
	StudentScoreList["A �б�"] = Temp;
	*/
	AddStudent(&StudentScoreList,"[S �б�]");
	AddStudent(&StudentScoreList, "[G �б�]");
	AddStudent(&StudentScoreList, "[A �б�]");
	// ** ���
	Output(&StudentScoreList);

	return 0;
}

char* SetName()
{
	char Buffer[1024] = "";

	cout << "�̸� �Է� : ";	cin >> Buffer;

	char* pName = new char[strlen(Buffer)];
	strcpy(pName, Buffer);

	return pName;
}

StudentScore* CreateStudent()
{
	StudentScore* pStudent = new StudentScore;

	Initialize(pStudent);

	return pStudent;
}

void Initialize(StudentScore* _pStudent)
{
	_pStudent->Name = SetName();

	cout << "���� ���� �Է� : "; cin >> _pStudent->Kor;
	cout << "���� ���� �Է� : "; cin >> _pStudent->Eng;
	cout << "���� ���� �Է� : "; cin >> _pStudent->Math;
}

void AddStudent(map<string, list<StudentScore*>>* _pStudentScoreList, string _strKey)
{
	map<string, list<StudentScore*>>::iterator iter = _pStudentScoreList->find(_strKey);
	
	if (iter == _pStudentScoreList->end())
	{
		cout << _strKey << endl;
		list<StudentScore*> TempList;
		
		for (int i = 0; i < 3; i++)
				TempList.push_back(CreateStudent());

		_pStudentScoreList->insert(make_pair(_strKey, TempList));
	}
	else
	{
		iter->second.push_back(CreateStudent());
	}
}


// ** ���� : map ����  list ������ ���
void Output(map<string, list<StudentScore*>>* _pStudentScoreList)
{	
	for (map<string, list<StudentScore*>>::iterator iter = _pStudentScoreList->begin();
		iter != _pStudentScoreList->end(); ++iter)
	{
		cout << iter->first << endl;
		for (list<StudentScore*>::iterator List_iter = iter->second.begin();
			List_iter != iter->second.end(); ++List_iter)
		{

			cout << "�̸� : " << (*List_iter)->Name << endl;
			cout << "���� ���� : " << (*List_iter)->Kor << endl;
			cout << "���� ���� : " << (*List_iter)->Eng << endl;
			cout << "���� ���� : " << (*List_iter)->Math << endl;
		}
		cout << "-----------------------------------" << endl;
	}
}