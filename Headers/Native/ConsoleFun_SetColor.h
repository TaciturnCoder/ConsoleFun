
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_H
#define ConsoleFun_Native_SetColor_H 1

void ConsoleFun_Native_SetColor(int FG, int BG)
{
    if ((ConsoleFun.Struct.Cache.Status & ConsoleFun.Struct.Cache.Flag.Init) == ConsoleFun.Struct.Cache.Flag.Init)
    {
#ifdef __linux__
        printf("%c[%d;%dm", 0x1B, FG + 30, BG + 40);
        fflush(stdout);
        ConsoleFun.Struct.Cache.Status = ConsoleFun.Struct.Cache.Status | ConsoleFun.Struct.Cache.Flag.SetColor;
#elif _WIN32
        HANDLE hConsole = ConsoleFun.Struct.Cache.hConsoleOut;

        if (SetConsoleTextAttribute(hConsole, BG * 16 + FG))
            ConsoleFun.Struct.Cache.Status = ConsoleFun.Struct.Cache.Status | ConsoleFun.Struct.Cache.Flag.SetColor;
        else
            ConsoleFun.Struct.Cache.Status = ConsoleFun.Struct.Cache.Status & (~ConsoleFun.Struct.Cache.Flag.SetColor);
#endif
    }
    return;
} // ConsoleFun_Native_SetColor

#endif // ConsoleFun_H
