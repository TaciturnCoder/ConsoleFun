
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

#ifndef ConsoleFun_
#define ConsoleFun_ 1

#include <stdio.h>
#include <stdlib.h>

#ifdef __linux__
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
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

    struct ConsoleFun_Cache_
    {
#ifdef __linux__
#elif _WIN32
        HANDLE hConsoleOut;
        HANDLE hConsoleIn;
#endif
    };

    const struct ConsoleFun_Cache_ ConsoleFun_Cache = {
#ifdef __linux__
#elif _WIN32
        NULL,
        NULL
#endif
    };

#include "./ConsoleFun_CFOpts.h"

    CFOpts ConsoleFun_CloneOpts(CFOpts);
    CFOpts ConsoleFun_GetOpts();
    char ConsoleFun_GetCh();
    void ConsoleFun_GotoRC(int, int);
    void ConsoleFun_SetColor(int, int);

    void ConsoleFun_EmptyRect(CFOpts);
    void ConsoleFun_FilledRect(CFOpts);
    void ConsoleFun_WriteBox(char *, CFOpts);
    char *ConsoleFun_ReadBox(CFOpts);

    struct
    {
        struct ConsoleFun_Color_ Color;
        struct ConsoleFun_Cache_ Cache;
        CFOpts (*CloneOpts)(CFOpts);
        CFOpts (*GetOpts)();
        char (*GetCh)();
        void (*GotoRC)(int, int);
        void (*SetColor)(int, int);
        void (*EmptyRect)(CFOpts);
        void (*FilledRect)(CFOpts);
        void (*WriteBox)(char *, CFOpts);
        char *(*ReadBox)(CFOpts);
    } ConsoleFun = {ConsoleFun_Color,
                    ConsoleFun_Cache,
                    ConsoleFun_CloneOpts,
                    ConsoleFun_GetOpts,
                    ConsoleFun_GetCh,
                    ConsoleFun_GotoRC,
                    ConsoleFun_SetColor,
                    ConsoleFun_EmptyRect,
                    ConsoleFun_FilledRect,
                    ConsoleFun_WriteBox,
                    ConsoleFun_ReadBox};

#include "./ConsoleFun_GetOpts.h"
#include "./ConsoleFun_GetCh.h"
#include "./ConsoleFun_GotoRC.h"
#include "./ConsoleFun_SetColor.h"

#include "./ConsoleFun_EmptyRect.h"
#include "./ConsoleFun_FilledRect.h"
#include "./ConsoleFun_WriteBox.h"
#include "./ConsoleFun_ReadBox.h"

#endif // ConsoleFun_

#ifdef __cplusplus
}
#endif
