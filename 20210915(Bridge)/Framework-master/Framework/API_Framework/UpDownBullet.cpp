#include "UpDownBullet.h"
#include"Object.h"

UpDownBullet::UpDownBullet()
{

}

UpDownBullet::~UpDownBullet()
{

}

void UpDownBullet::Initialize()
{
	Speed = 3.0f;
	bCheck = false;
	DrawKey = "UpDownBullet";
}

int UpDownBullet::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;

	if (bCheck)
		_rTransInfo.Direction.y = 1.0f;
	else
		_rTransInfo.Direction.y = -1.0f;

	//만약 위에 도달하면 아래로 이동 
	if (_rTransInfo.Position.y <= 0)
		bCheck = true;
	//아래에 도달하면 위로 이동.
	else if (_rTransInfo.Position.y >= (WindowsHeight - 50))
		bCheck = false;


	_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;
	

	if (_rTransInfo.Position.x >= (WindowsWidth - 100))
		return 1;
	return 0;
}

void UpDownBullet::Render(HDC _hdc)
{
	Ellipse(_hdc,
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
		int(RealObject->GetPosition().x + (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y + (RealObject->GetScale().y / 2)));
}

void UpDownBullet::Release()
{

}


