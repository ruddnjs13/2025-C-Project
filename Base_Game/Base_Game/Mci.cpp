#include "Mci.h"
#include<mmsystem.h>
#include<Digitalv.h>;
#include <vector>;
#include"Console.h";
#pragma comment(lib, "winmm.lib")

static std::vector<SoundEntry> SoundTable =
{
    { L"Sound\\dancing-juice-222031.mp3", 50, 0 },
    { L"Sound\\foley-office-computer-mouse-draw-02.wav", 20, 0 },
    { L"Sound\\object-pen-pencil-scribble-character-01.wav", 20, 0 },
};

bool OpenMciDevice(LPCWSTR _deviceType, LPCWSTR _name, UINT& _deviceid)
{
    MCI_OPEN_PARMS openParams = {};
    openParams.lpstrDeviceType = _deviceType; // ex. mpegvideo, waveaudio
    openParams.lpstrElementName = _name; // ���� ���(�̸�)

    if (mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openParams) != 0)
    {
        // ���� �߻� �� false ��ȯ
        return false;
    }

    _deviceid = openParams.wDeviceID; // �Ҵ�� ��ġ ID ��ȯ
    return true;
}

void CloseMciDevice(UINT& _deviceid)
{
    if (_deviceid != 0)
    {
        // RAII: �ڿ� ����
        mciSendCommand(_deviceid, MCI_CLOSE, 0, 0);
        _deviceid = 0; // �ߺ� �ݱ� ����
    }
}

void PlayMciDevice(UINT _deviceid, bool repeat)
{
    MCI_PLAY_PARMS playParams = {};
    DWORD_PTR playFlags = repeat ? MCI_DGV_PLAY_REPEAT : MCI_NOTIFY; // 0�� �⺻ ���

    if (repeat == false && _deviceid != 0)
        mciSendCommand(_deviceid, MCI_SEEK, MCI_SEEK_TO_START
            , (DWORD_PTR)&playParams);
    mciSendCommand(_deviceid, MCI_PLAY, playFlags, (DWORD_PTR)&playParams);
}

bool InitAllSounds()
{
    for (auto it = SoundTable.begin(); it != SoundTable.end(); ++it)
    {
        // ��ΰ� ��� ������ �ε����� ����
        if (it->path.empty())
            continue;

        // ����̽� ���� �Ǵ�         // C��Ÿ��: wcs1���� wcs2�� ù��° ǥ�ø� ã�´�.
        //LPCWSTR devType = (wcsstr(it->path.c_str(), L".mp3") != NULL) 
        bool isMpeg = it->path.ends_with(L".mp3");
        LPCWSTR devType = isMpeg // C++20: �־��� �κ� ���ڿ��� �������� �˻�
            ? TEXT("mpegvideo")
            : TEXT("waveaudio");

        // ����
        if (!OpenMciDevice(devType, it->path.c_str(), it->deviceId))
            return false;

        // ���� ���� mp3�� ����
        if (isMpeg)
        {
            std::wstring volumeCommand = L"setaudio " + it->path +
                L" volume to " + std::to_wstring(it->volume);
            mciSendString(volumeCommand.c_str(), NULL, NULL, NULL);
        }
    }
    return true;
}

void PlaySoundID(SOUNDID _id, bool _repeat)
{
    // Ȯ�� �� ó��
    UINT devId = SoundTable[(int)_id].deviceId;
    if (devId == 0)
        return;
    // ���� ���
    PlayMciDevice(devId, _repeat);
}

void CloseSoundID(SOUNDID id)
{
    UINT devId = SoundTable[(int)id].deviceId;
    if (devId == 0)
        return;
    // ���� ���
    CloseMciDevice(devId);
}

void ReleaseAllSounds()
{
    for (auto& sound : SoundTable)
    {
        CloseMciDevice(sound.deviceId);
    }
}
