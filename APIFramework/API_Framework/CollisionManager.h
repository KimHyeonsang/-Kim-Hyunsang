#pragma once
#include"Object.h"

class CollisionManager
{
public:
	static bool EllipseCollision(Object* _Temp, Object* _Dest)
	{
		// ** 플레이어의 반지름과 Target의 반지름의 합을 구함
		float Sum = (_Temp->GetScale().x / 2) + (_Dest->GetScale().x / 2);

		float fX = _Temp->GetPosition().x - _Dest->GetPosition().x;
		float fY = _Temp->GetPosition().y - _Dest->GetPosition().y;

		float Distance = sqrt((fX * fX) + (fY * fY));

		if (Sum > Distance)
			return true;


		return false;
	}
};

