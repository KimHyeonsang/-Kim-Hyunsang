#pragma once
#include"Header.h"

class Bitmap;
class Object
{
protected:
	Transform TransInfo;
	Transform Collider;
	Vector3 Offset;

	string strKey;
	float Speed;
	int Hart;
	bool Active;
	int Damage;

	int m_iScore;

	static map<string, Bitmap*> ImageList;

	BULLETID BulletID;
	ENEMYID EnemyID;
public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;

	virtual Object* Clone()PURE;
public:
	static void SetImageList(const map<string,Bitmap*>& _ImageList) {ImageList = _ImageList;}
	static map<string, Bitmap*> GetImageList() {return ImageList;	}
	string GetKey()const {	return strKey;	}
	// ** ��ǥ�� Setting (Vector3)
	void SetPosition(Vector3 _position) {	TransInfo.Position = _position;	}
	// ** ��ǥ�� Setting (_x, _y)
	void SetPosition(float _x, float _y) {	TransInfo.Position.x = _x; TransInfo.Position.y = _y;	}
	// ** ��ǥ�� Vector3�� out
	Vector3 GetPosition() { return TransInfo.Position; }

	// ** ũ�⸦ Vector3�� out
	Vector3 GetDirection() { return TransInfo.Direction; }

	// ** ũ�⸦ ����
	void SetDirection(float _Scale_x,float _Scale_y){
		TransInfo.Direction.x = _Scale_x;
		TransInfo.Direction.y = _Scale_y;
	}

	// ** ũ�⸦ Vector3�� out
	Vector3 GetScale() {
		return TransInfo.Scale;
	}

	// ** ũ�⸦ ����
	void SetScale(float _Scale_x, float _Scale_y) {
		TransInfo.Scale.x = _Scale_x;
		TransInfo.Scale.y = _Scale_y;
	}

	// ** �浹ü�� out.
	RECT GetCollider();

	Vector3 GetColliderPosition() {	return Collider.Position;	}
	Transform GetColliderTransform() {	return Collider;	}

	// ** �浹ü�� Setting
	void SetColliderPosition(float _x, float _y) {
		Collider.Position.x = _x; Collider.Position.y = _y;
	}

	// ** �浹ü ũ��
	void SetColliderScale(float _x, float _y) {
		Collider.Scale.x = _x; Collider.Scale.y = _y;
	}
	bool GetActive() const {return Active;	}
	// ** ��� Ȯ��
	int GetHart() {	return Hart;}
	// ** ��� ����
	void SetHart(int _Number) {	Hart = _Number;	}

	// ** �ǰ�
	void HartHit(int _Damage);

	// ������
	int GetDamage() {	return Damage;	}
	// ** ������ ����
	void SetDamage(int _Number) {	Damage = _Number;	}
	// BulletID
	void SetBulletID(BULLETID _ID) {BulletID = _ID;	}
	BULLETID GetBulletID() {	return BulletID;	}

	// EnemyID
	void SetEnemyID(ENEMYID _ID) {	EnemyID = _ID;	}
	ENEMYID GetEnemyID() {	return EnemyID;	}

	int GetScore() {	return m_iScore;	}
	void SetScore(int _Score) {	m_iScore += _Score;	}

	void SetActive(const bool& _Active) {	Active = _Active;	}
public:
	Object();
	Object(const Transform& _rTransInfo) : TransInfo(_rTransInfo) { }
	virtual ~Object();
};

