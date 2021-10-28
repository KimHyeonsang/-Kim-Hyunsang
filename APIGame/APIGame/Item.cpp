#include "Item.h"

Item::Item()
{

}

Item::~Item()
{

}

void Item::Initialize()
{
	random_device rd;
	srand(rd());
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(53.0f, 53.0f);

	strKey = "BoombItem";
	ItemNumber = 0;
	Speed = 2.0f;
	Angle = -0.4f;
}

int Item::Update()
{
	// �������� ������ ���� ������ ���� �ñ�
	// ���Ͱ� ������ ���� ���� ����

	TransInfo.Position.x += cosf(Angle) * Speed;
	TransInfo.Position.y += -sinf(Angle) * Speed;


	//���� ���� �ε�������   
	// x�����(�¿�) �ݻ簢�� �̿��ؼ� ������ �浹 ����
	// �¿� �ݻ簢 = 180 - �Ի簢
	if (TransInfo.Position.x - (TransInfo.Scale.x / 2) <= 0)
	{
		Angle = PI - Angle;
	}
	if (TransInfo.Position.x + (TransInfo.Scale.x / 2) >= WindowsWidth)
	{
		Angle = PI - Angle;
	}


	//���� �ݻ簢�� �̿��� ������ �浹 ����
	//���� �ݻ簢 = 360 - �Ի簢

	if (TransInfo.Position.y - (TransInfo.Scale.y / 2) < 0)
	{
		Angle = 2 * PI - Angle;
	}
	if (TransInfo.Position.y + (TransInfo.Scale.y / 2) > WindowsHeight)
	{
		Angle = 2 * PI - Angle;
	}
    return 0;
}

void Item::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** ���� ��� ��ġ
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		0, 0,
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));
}

void Item::SetNumber()
{
	// ��ź 70�� �Ϲ� ���� 20�� �ݻ���� 10��
	int Number = rand() % 100;

	if (Number < 70)
	{
		strKey = "BoombItem";
		ItemNumber = 0;
	}
	else if (Number >= 70 && Number < 90)
	{
  		strKey = "NomalBulletItem";
		ItemNumber = 1;
	}
	else
	{
		strKey = "ReflectionBulletItem";
		ItemNumber = 2;
	}
}

void Item::Release()
{
}


