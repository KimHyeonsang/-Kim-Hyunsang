#pragma once
#include"Object.h"

class CollisionManager
{
public:
	static bool RectCollision(Object* V1, Object* V2)
	{
		if ((V1->GetPosition().x + (V1->GetScale().x / 2)) > (V2->GetPosition().x - (V2->GetScale().x / 2)) &&
			(V1->GetPosition().y + (V1->GetScale().y / 2)) > (V2->GetPosition().y - (V2->GetScale().y / 2)) &&
			(V1->GetPosition().x - (V1->GetScale().x / 2)) < (V2->GetPosition().x + (V2->GetScale().x / 2)) &&
			(V1->GetPosition().y - (V1->GetScale().y / 2)) < (V2->GetPosition().y + (V2->GetScale().y / 2)))
			return true;
		return false;
	}

	static bool RectCollision(RECT V1, RECT V2)
	{
		if (V1.left < V2.right && V1.top < V2.bottom &&
			V2.left < V1.right && V2.top < V1.bottom)
			return true;
		return false;
	}
};