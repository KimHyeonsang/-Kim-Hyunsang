#include "Bullet.h"
#include"ObjectManager.h"
#include"MathManager.h"
#include"NormalBullet.h"

Bullet::Bullet() : BridgeObject(NULL)
{

}

Bullet::~Bullet()
{
	Release();
}

void Bullet::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(0.0f, 1.0f);
	TransInfo.Scale = Vector3(15.0f, 18.0f);

	BridgeObject = NULL;

//	strKey = "Bullet";
//	Active = false;

	//imageList 를 넘겨줘야한다.
	ImageList = Object::GetImageList();
//	BridgeObject->SetImageList(ImageList);
}

int Bullet::Update()
{
	if (BridgeObject)
		if (BridgeObject->Update(TransInfo))
			return 1;
	
	return 0;
}

void Bullet::Render(HDC _hdc)
{
	if (BridgeObject)
		BridgeObject->Render(_hdc);
}

void Bullet::Release()
{
	delete BridgeObject;
	BridgeObject = nullptr;
}


