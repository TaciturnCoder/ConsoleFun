
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_CFOpts_
#define ConsoleFun_SetColor_ 1

void ConsoleFun_SetColor(int FG, int BG)
{
#ifdef __linux__
    printf("%c[%d;%dm", 0x1B, FG + 30, BG + 40);
#elif _WIN32
    HANDLE hConsole;
    if (ConsoleFun.Cache.hConsoleOut == NULL)
    {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        ConsoleFun.Cache.hConsoleOut = hConsole;
    }
    else
    {
        hConsole = ConsoleFun.Cache.hConsoleOut;
    }

    SetConsoleTextAttribute(hConsole, BG * 16 + FG);
#endif
    return;
} // ConsoleFun_SetColor

#endif // ConsoleFun_CFOpts_
