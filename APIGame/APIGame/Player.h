#pragma once
#include"Object.h"

class Player : public Object
{
private:
	vector<Object*>* BulletList;
	vector<Object*>* BoombList;
	int Bullet_Upgrade;
	int iBoomb;
	int PlayerNumber;
	ULONGLONG Time;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override {return new Player(*this);	};
public:
	void LoseHart() { Hart -=1;	}
	void SetNumber(int _Number);
	template <typename T>
	Object* CreateBullet();
	int GetBoomb() {return iBoomb;	}
public:
	Player();
	Player(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Player();
};

