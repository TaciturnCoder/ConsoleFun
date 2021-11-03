
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifndef ConsoleFun_H
#define ConsoleFun_H 1

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdlib.h>

#ifdef __linux__
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#elif _WIN32
#include <windows.h>
#endif

#include "./ConsoleFun_CFOpts.h"
#include "./ConsoleFun_Struct.h"

    void ConsoleFun_Init();

    /**
     * @brief Object to access all methods
     *
     */
    struct
    {
        CFOpts NullOpts;
        CFOpts (*CloneOpts)(CFOpts);
        struct ConsoleFun_Struct_ Struct;
        struct ConsoleFun_Native_ Native;
        struct ConsoleFun_Utils_ Utils;
        void (*Init)();
    } ConsoleFun = {{0, 0, 0, 0, 0, 0},
                    ConsoleFun_CloneOpts,
                    ConsoleFun_Struct,
                    ConsoleFun_Native,
                    ConsoleFun_Utils,
                    ConsoleFun_Init};

#include "./Native/ConsoleFun_GetCh.h"
#include "./Native/ConsoleFun_GetOpts.h"
#include "./Native/ConsoleFun_GotoRC.h"
#include "./Native/ConsoleFun_SetColor.h"

#include "./Utils/ConsoleFun_EmptyRect.h"
#include "./Utils/ConsoleFun_FilledRect.h"
#include "./Utils/ConsoleFun_InputBox.h"
#include "./Utils/ConsoleFun_PrintBox.h"

#include "./ConsoleFun_Init.h"

#ifdef __cplusplus
}
#endif

#endif // ConsoleFun_H
