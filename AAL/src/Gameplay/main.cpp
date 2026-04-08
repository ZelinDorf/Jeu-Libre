#include "pch.h"
#include "main.h"

#ifdef _DEBUG
// Forcer le mode console
#pragma comment(linker, "/SUBSYSTEM:CONSOLE")

int main()
{
    CPU_RUN(800, 450, false, false);
    return 0;
}
#else
// OU forcer le mode fenetre (pas de console)
#pragma comment(linker, "/SUBSYSTEM:WINDOWS")

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    CPU_RUN(1920, 1080, true, false);
    return 0;
}
#endif