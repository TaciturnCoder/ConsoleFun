
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef ConsoleFun_Include

    void ConsoleFun_SetColor(int FG, int BG)
    {
#ifdef __linux__
        printf("%c[%d;%dm", 0x1B, FG + 30, BG + 40);
#elif _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(hConsole, BG * 16 + FG);
#endif
        return;
    } // ConsoleFun_SetColor

#endif // ConsoleFun_Include

#ifdef __cplusplus
}
#endif
