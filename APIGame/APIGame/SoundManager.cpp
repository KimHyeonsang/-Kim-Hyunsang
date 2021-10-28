#include "SoundManager.h"

SoundManager* SoundManager::Instance = nullptr;

void SoundManager::Initialize()
{	
	FMOD_RESULT Result;
	FMOD::System_Create(&m_pSystem);

	// ** 32���� ä���� ���ڴ�.
	if (FMOD_OK != m_pSystem->init(32, FMOD_INIT_NORMAL, nullptr))
	{
		cout << "Initialization Error. " << endl;
		return;
	}
	
}

void SoundManager::LoadSoundDate(const char* FileName, string _Key,int a)
{
	SOUNDINFO* SoundInfo = new SOUNDINFO;
	if (FMOD_OK != m_pSystem->createSound(FileName, FMOD_LOOP_OFF, 0, &SoundInfo->SoundObj))
	{
		cout << "Date Load Error!! " << endl;
		return;
	}

	SoundInfo->ChannelID = a;
	SoundInfo->SoundObj->setMusicChannelVolume(SoundInfo->ChannelID, 0.2f);

	SoundList.insert(make_pair(_Key, SoundInfo));
}

void SoundManager::LoadBGMSoundDate(const char* FileName, string _Key)
{
	SOUNDINFO* SoundInfo = new SOUNDINFO;

	if (FMOD_OK != m_pSystem->createSound(FileName, FMOD_LOOP_NORMAL, 0, &SoundInfo->SoundObj))
	{
		cout << "Date Load Error!! " << endl;
		return;
	}

	SoundInfo->ChannelID = 0;
	SoundInfo->SoundObj->setMusicChannelVolume(SoundInfo->ChannelID, 0.3f);

	SoundList.insert(make_pair(_Key, SoundInfo));
}


void SoundManager::StringUpdate()
{
	m_pSystem->update();
}

void SoundManager::OnPlaySound(string _Key)
{
	// ** ���带 ã�´�.
	map<string, SOUNDINFO*>::iterator iter = SoundList.find(_Key);


	// ** ���࿡ ã�� ���尡 ���ٸ�...
	if (iter == SoundList.end())
	{
		// ** ���� �����Ͱ� ���ٴ� �޽����� ��� �� �����Ŵ..
		cout << "Sound date Does not exits " << endl;
		return;
	}

	// ** ���带 ��� ��Ŵ..
	if (FMOD_OK != m_pSystem->playSound(iter->second->SoundObj, 0, false, &iter->second->SoundChannel))
	{
		cout << "���� ���� " << endl;
		return;
	}
}

void SoundManager::Release()
{
	for (map<string, SOUNDINFO*>::iterator iter = SoundList.begin();
		iter != SoundList.end(); iter++)
	{
		iter->second->SoundObj->release();
		iter = SoundList.erase(iter);
	}
	SoundList.clear();
}

void SoundManager::VolumeUp()
{
	if (Volume < SOUND_VOLUME_MAX)
	{
		Volume += SOUND_VOLUME;

		for (map<string, SOUNDINFO*>::iterator iter = SoundList.begin();
			iter != SoundList.end(); iter++)
		{
			iter->second->SoundChannel->setVolume(Volume);
		}
	}
}

void SoundManager::VolumeDown()
{
	if (Volume < SOUND_VOLUME_MIN)
	{
		Volume -= SOUND_VOLUME;

		for (map<string, SOUNDINFO*>::iterator iter = SoundList.begin();
			iter != SoundList.end(); iter++)
		{
			iter->second->SoundChannel->setVolume(Volume);
		}
	}
}
