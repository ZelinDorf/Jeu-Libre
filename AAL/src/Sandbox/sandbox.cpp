#include "pch.h"
#include "sandbox.h"

#ifdef _DEBUG


#pragma comment(linker, "/SUBSYSTEM:CONSOLE")

int main()
{
    CPU_RUN(512, 256, true, true);

    return 0;
}
#else
// OU forcer le mode fenetre (pas de console)
#pragma comment(linker, "/SUBSYSTEM:WINDOWS")

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) 
{

    return 0;
}
#endif