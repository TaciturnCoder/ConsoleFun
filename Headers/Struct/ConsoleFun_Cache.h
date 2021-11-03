
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_H
#define ConsoleFun_Struct_Cache_H 1

typedef unsigned char ConsoleFun_Struct_Cache_Flag_;

const ConsoleFun_Struct_Cache_Flag_ ConsoleFun_Struct_Cache_Flag_Init = (ConsoleFun_Struct_Cache_Flag_)0b00000001;
const ConsoleFun_Struct_Cache_Flag_ ConsoleFun_Struct_Cache_Flag_GetCh = (ConsoleFun_Struct_Cache_Flag_)0b00000010;
const ConsoleFun_Struct_Cache_Flag_ ConsoleFun_Struct_Cache_Flag_GetOpts = (ConsoleFun_Struct_Cache_Flag_)0b00000100;
const ConsoleFun_Struct_Cache_Flag_ ConsoleFun_Struct_Cache_Flag_GotoRC = (ConsoleFun_Struct_Cache_Flag_)0b00001000;
const ConsoleFun_Struct_Cache_Flag_ ConsoleFun_Struct_Cache_Flag_SetColor = (ConsoleFun_Struct_Cache_Flag_)0b00010000;

struct ConsoleFun_Struct_Cache_
{
    const struct
    {
        const ConsoleFun_Struct_Cache_Flag_ Init;
        const ConsoleFun_Struct_Cache_Flag_ GetCh;
        const ConsoleFun_Struct_Cache_Flag_ GetOpts;
        const ConsoleFun_Struct_Cache_Flag_ GotoRC;
        const ConsoleFun_Struct_Cache_Flag_ SetColor;
    } Flag;

    ConsoleFun_Struct_Cache_Flag_ Status;
#ifdef __linux__
#elif _WIN32
    HANDLE hConsoleOut;
    HANDLE hConsoleIn;
#endif
};

const struct ConsoleFun_Struct_Cache_ ConsoleFun_Struct_Cache = {
    {ConsoleFun_Struct_Cache_Flag_Init,
     ConsoleFun_Struct_Cache_Flag_GetCh,
     ConsoleFun_Struct_Cache_Flag_GetOpts,
     ConsoleFun_Struct_Cache_Flag_GotoRC,
     ConsoleFun_Struct_Cache_Flag_SetColor},
    (ConsoleFun_Struct_Cache_Flag_)0b11111110,
#ifdef __linux__
#elif _WIN32
    NULL,
    NULL
#endif
};

#endif // ConsoleFun_H
