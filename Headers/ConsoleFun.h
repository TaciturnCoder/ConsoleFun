
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

#include "./ConsoleFun_Include.h"

#include "./ConsoleFun_GetOpts.h"
#include "./ConsoleFun_GotoRC.h"
#include "./ConsoleFun_SetColor.h"

#include "./ConsoleFun_EmptyRect.h"
#include "./ConsoleFun_FilledRect.h"

    struct
    {
        struct ConsoleFun_Color_ Color;
        CFOpts (*GetOpts)();
        void (*GotoRC)(int, int);
        void (*SetColor)(int, int);
        void (*EmptyRect)(CFOpts);
        void (*FilledRect)(CFOpts);
    } ConsoleFun = {ConsoleFun_Color,
                    ConsoleFun_GetOpts,
                    ConsoleFun_GotoRC,
                    ConsoleFun_SetColor,
                    ConsoleFun_EmptyRect,
                    ConsoleFun_FilledRect};

#endif // ConsoleFun_

#ifdef __cplusplus
}
#endif
