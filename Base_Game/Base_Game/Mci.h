#pragma once
#include<Windows.h>
#include<string>

// ����
bool OpenMciDevice(LPCWSTR _deviceType, LPCWSTR _name, UINT& _deviceId);

// �ݱ�
void CloseMciDevice(UINT& _deviceId);

// ���
void PlayMciDevice(UINT _deviceId, bool repeat = false);


enum class SOUNDID
{
    BGM, SELECTCOLOR,SELECTWORD,WIN,ENTER, END
};

struct SoundEntry
{
    //LPCWSTR path;     // ���� ���
    std::wstring path; // ���� ���
    int     volume;  // ���� (0~100)  
    UINT    deviceId; // MCI ��ġ ID (�ʱⰪ 0)
};
// �ʱ�ȭ
bool InitAllSounds();
// ���
void PlaySoundID(SOUNDID _id, bool _repeat = false);
void CloseSoundID(SOUNDID id);
// ������ 
void ReleaseAllSounds();
