#include "Bullet.h"


Bullet::Bullet()
{

}

Bullet::~Bullet()
{

}

void Bullet::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);

	strKey = "Bullet";
	Count = 0;
	Active = false;
}

int Bullet::Update()
{
	++Count;;
	//** Count 가 50이 되면 삭제시킴.
	if (Count >= 50)
		return 1;

	return 0;
}

void Bullet::Render()
{
	cout << "Bullet Position : (" << TransInfo.Position.x << ", " << TransInfo.Position.y << ") Count :" << Count << endl;
}

void Bullet::Release()
{

}
