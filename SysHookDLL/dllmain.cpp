//THIS PROJECT IS NOT MY IDEA; IT IS A PROOF OF CONCEPT FOR 2 PEOPLE WHO ASKED ME TO WRITE IT (xFGhoul, Creo)
#include "pch.h"
#include "Hook.h"
//I use this for output. You can do as you wish
#include <fstream>
//lol
void* GetSystemFunctionAddress()
{
    return &system;
}
//create system function prototype 
void(*System_t)(char* in);
//simple dumper. you can change this as you wish. you could even call it after
void SystemHook(char* in) 
{
    std::ofstream dump_file;
    dump_file.open("dump.txt", std::ios_base::app);
    dump_file << "system called with arg -> " << in << std::endl;
    dump_file.close();
}
//thread that deploys the hooks
DWORD WINAPI HookThread(HMODULE hModule)
{
    uint64_t module_base = (uint64_t)GetModuleHandle(NULL);
    uint64_t system_address = (uint64_t)GetSystemFunctionAddress();
    std::ofstream info_file;
    //output basic information to make sure it hooked correctly
    info_file.open("info.txt");
    info_file << "module_base -> " << module_base << std::endl;
    info_file << "system_addr -> " << system_address << std::endl;
    info_file.close();
    TrampolineHook(SystemHook, (void*)system_address, (PVOID*)&System_t);
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}
//entry point
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        //start the hook thread to create the hooks and leave asap
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HookThread, hModule, 0, nullptr));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}