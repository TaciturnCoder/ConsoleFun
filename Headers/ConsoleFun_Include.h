
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

#ifdef ConsoleFun_
#define ConsoleFun_Include 1

#include <stdio.h>
#include <stdlib.h>

#ifdef __linux__
#include <sys/ioctl.h>
#elif _WIN32
#include <windows.h>
#endif

#ifdef __linux__
    enum
    {
        ConsoleFun_Color_Black,
        ConsoleFun_Color_Red,
        ConsoleFun_Color_Green,
        ConsoleFun_Color_Yellow,
        ConsoleFun_Color_Blue,
        ConsoleFun_Color_Magenta,
        ConsoleFun_Color_Cyan,
        ConsoleFun_Color_White
    };
#elif _WIN32
    enum
    {
        ConsoleFun_Color_Black,
        ConsoleFun_Color_Blue,
        ConsoleFun_Color_Green,
        ConsoleFun_Color_Cyan,
        ConsoleFun_Color_Red,
        ConsoleFun_Color_Magenta,
        ConsoleFun_Color_Yellow,
        ConsoleFun_Color_White
    };
#endif

    typedef struct
    {
        int Row;
        int Col;

        int Rows;
        int Cols;

        int FG;
        int BG;
    } CFOpts;

    struct ConsoleFun_Color_
    {
        int Black;
        int Blue;
        int Green;
        int Cyan;
        int Red;
        int Magenta;
        int Yellow;
        int White;
    };

    const struct ConsoleFun_Color_ ConsoleFun_Color = {ConsoleFun_Color_Black,
                                                       ConsoleFun_Color_Blue,
                                                       ConsoleFun_Color_Green,
                                                       ConsoleFun_Color_Cyan,
                                                       ConsoleFun_Color_Red,
                                                       ConsoleFun_Color_Magenta,
                                                       ConsoleFun_Color_Yellow,
                                                       ConsoleFun_Color_White};

    CFOpts ConsoleFun_GetOpts();
    void ConsoleFun_GotoRC(int, int);
    void ConsoleFun_SetColor(int, int);
    void ConsoleFun_EmptyRect(CFOpts);
    void ConsoleFun_FilledRect(CFOpts);

#endif // ConsoleFun_

#ifdef __cplusplus
}
#endif
