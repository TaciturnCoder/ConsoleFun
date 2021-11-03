
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_H
#define ConsoleFun_Struct_KeyMap_H 1

typedef unsigned char ConsoleFun_Struct_KeyMap_Flag_;

const ConsoleFun_Struct_KeyMap_Flag_ ConsoleFun_Struct_KeyMap_Flag_Esc = (ConsoleFun_Struct_KeyMap_Flag_)0b00000001;
const ConsoleFun_Struct_KeyMap_Flag_ ConsoleFun_Struct_KeyMap_Flag_Alt = (ConsoleFun_Struct_KeyMap_Flag_)0b00000010;
const ConsoleFun_Struct_KeyMap_Flag_ ConsoleFun_Struct_KeyMap_Flag_Ctrl = (ConsoleFun_Struct_KeyMap_Flag_)0b00000100;
const ConsoleFun_Struct_KeyMap_Flag_ ConsoleFun_Struct_KeyMap_Flag_Arrow = (ConsoleFun_Struct_KeyMap_Flag_)0b00001000;

enum
{
    ConsoleFun_Struct_KeyMap_ArrowUp = 'A',
    ConsoleFun_Struct_KeyMap_ArrowDown,
    ConsoleFun_Struct_KeyMap_ArrowRight,
    ConsoleFun_Struct_KeyMap_ArrowLeft
};

struct ConsoleFun_Struct_KeyMap_
{
    const struct
    {
        const ConsoleFun_Struct_KeyMap_Flag_ Esc;
        const ConsoleFun_Struct_KeyMap_Flag_ Alt;
        const ConsoleFun_Struct_KeyMap_Flag_ Ctrl;
        const ConsoleFun_Struct_KeyMap_Flag_ Arrow;
    } Flag;

    ConsoleFun_Struct_KeyMap_Flag_ Status;

    char ArrowUp;
    char ArrowDown;
    char ArrowRight;
    char ArrowLeft;

    char FirstPrintable;
    char LastPrintable;

    char ESC;
    char BS;
    char TAB;
    char NL;
    char CR;
    char DEL;
};

const struct ConsoleFun_Struct_KeyMap_ ConsoleFun_Struct_KeyMap = {
    {ConsoleFun_Struct_KeyMap_Flag_Esc,
     ConsoleFun_Struct_KeyMap_Flag_Alt,
     ConsoleFun_Struct_KeyMap_Flag_Ctrl,
     ConsoleFun_Struct_KeyMap_Flag_Arrow},
    (ConsoleFun_Struct_KeyMap_Flag_)0b00000000,
    ConsoleFun_Struct_KeyMap_ArrowUp,
    ConsoleFun_Struct_KeyMap_ArrowDown,
    ConsoleFun_Struct_KeyMap_ArrowRight,
    ConsoleFun_Struct_KeyMap_ArrowLeft,
    32,
    126,
    27,
    8,
    9,
    10,
    13,
    127,
};

#endif // ConsoleFun_H
