#include"Header.h"

class MainUpdate
{
private:
	HDC m_hdc;
public:
	void Initalize();
	void Update();
	void Render();
	void Release();
public:
	MainUpdate();
	~MainUpdate();
};
