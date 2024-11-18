#include "pch.h"
class Vector3 {
public: 
    float x, y, z;
};
void thread()
{
    MessageBox(NULL, L"Removing Shadow Ban", L"Legend is god", MB_OK);
    static bool once = false;
    while (true)
    {
        uintptr_t process = (uintptr_t)GetModuleHandle(L"GameAssembly.dll");
        auto RemoveFlagged = reinterpret_cast<void(*)(uintptr_t,bool)>(process + 12088400);
        auto getPlayer = reinterpret_cast<uintptr_t(*)()>(process + 4418560);
        auto getisflaged = reinterpret_cast<bool(*)(uintptr_t)>(process + 12087712);
        if((uintptr_t)getPlayer() > 0x100 && !once)
            MessageBox(NULL, (L"Found Main Player"), L"Legend is god", MB_OK);

        if (getisflaged(getPlayer()) && !once)
            MessageBox(NULL, L"Account Status Flagged", L"Legend is god", MB_OK);

        RemoveFlagged(getPlayer(), false);

        if (getisflaged(getPlayer()) && !once)
            MessageBox(NULL, L"Account Status Flagged", L"Legend is god", MB_OK);

        if(!once)
            MessageBox(NULL, L"Removed Shadow Ban", L"Legend is god", MB_OK);
       (*reinterpret_cast<bool*>(getPlayer() + 0x99)) = 1; // unlock all towners
        (*reinterpret_cast<bool*>(getPlayer() + 0x98)) = 1; // unlock all updateds

        once = true;
    }
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)thread, 0, 0, 0);
    }
    return TRUE;
}

