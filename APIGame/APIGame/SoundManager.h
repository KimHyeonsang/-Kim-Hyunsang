#pragma once
#include"Header.h"

class SoundManager
{
private:
	static SoundManager* Instance;
public:
	static SoundManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SoundManager;
		return Instance;
	}
private:
	FMOD::System* m_pSystem;
	map<string, SOUNDINFO*> SoundList;

	float Volume;

public:
	void Initialize();
	void LoadSoundDate(const char* FileName, string _Key);
	void LoadBGMSoundDate(const char* FileName, string _Key);
	void LoadEnemySoundDate(const char* FileName, string _Key);
	void StringUpdate();
	void OnPlaySound(string _Key);
	void Release();
	void VolumeUp();
	void VolumeDown();
private:
	SoundManager() {};
public:
	~SoundManager() {	Release();	};
};

