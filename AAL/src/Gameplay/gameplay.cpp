#include "pch.h"
#include "gameplay.h"

#ifdef _DEBUG


#pragma comment(linker, "/SUBSYSTEM:CONSOLE")

int main()
{

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