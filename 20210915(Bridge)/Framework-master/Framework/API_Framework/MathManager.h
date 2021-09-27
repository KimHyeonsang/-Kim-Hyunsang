#pragma once
#include "Headers.h"

class MathManager
{
public:
	// ** �Ÿ��� ���ϴ� �Լ�
	static float GetDistance(Vector3 _Current, Vector3 _Target)
	{
		// ** _Current �� _Target ������ �غ��� ���̸� ����.
		float fX = _Target.x - _Current.x;
		float fY = _Target.y - _Current.y;

		// ** ������ ��ȯ
		return sqrt((fX * fX) + (fY * fY));
	}

	// ** ������ ���ϴ� �Լ�
	static Vector3 GetDirection(Vector3 _Current, Vector3 _Target)
	{
		// ** _Current �� _Target ������ �غ��� ���̸� ����.
		float fX = _Target.x - _Current.x;
		float fY = _Target.y - _Current.y;

		// ** ������ ����.
		float Distance = sqrt((fX * fX) + (fY * fY));

		// ** ���⸸ ���ܵα� ���� �������� �����ش�.
		return Vector3(fX / Distance, fY / Distance);
		// ** ���� 
		// ** ������ �ﰢ���� ������ ������ �׻� �غ��̳� ���̺��� ũ��.
		// ** �ڱ� �ڽź��� ū������ �������ٸ� ���� 1���� ���� ���� ���´�.
		// ** Vector ���� 1�̰ų� 1���� ���� ���� ���⸸ �����ִٰ� ����.
		// ** 1 �̶�� ���� ����� ���ϴ��� ���� ���� ������ �����̴�.
	}
};
