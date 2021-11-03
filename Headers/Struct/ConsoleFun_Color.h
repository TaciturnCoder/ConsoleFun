
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_H
#define ConsoleFun_Struct_Color_H 1

#ifdef __linux__
enum
{
    ConsoleFun_Struct_Color_Black,
    ConsoleFun_Struct_Color_Red,
    ConsoleFun_Struct_Color_Green,
    ConsoleFun_Struct_Color_Yellow,
    ConsoleFun_Struct_Color_Blue,
    ConsoleFun_Struct_Color_Magenta,
    ConsoleFun_Struct_Color_Cyan,
    ConsoleFun_Struct_Color_White
};
#elif _WIN32
enum
{
    ConsoleFun_Struct_Color_Black,
    ConsoleFun_Struct_Color_Blue,
    ConsoleFun_Struct_Color_Green,
    ConsoleFun_Struct_Color_Cyan,
    ConsoleFun_Struct_Color_Red,
    ConsoleFun_Struct_Color_Magenta,
    ConsoleFun_Struct_Color_Yellow,
    ConsoleFun_Struct_Color_White
};
#endif

struct ConsoleFun_Struct_Color_
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

const struct ConsoleFun_Struct_Color_ ConsoleFun_Struct_Color = {ConsoleFun_Struct_Color_Black,
                                                                 ConsoleFun_Struct_Color_Blue,
                                                                 ConsoleFun_Struct_Color_Green,
                                                                 ConsoleFun_Struct_Color_Cyan,
                                                                 ConsoleFun_Struct_Color_Red,
                                                                 ConsoleFun_Struct_Color_Magenta,
                                                                 ConsoleFun_Struct_Color_Yellow,
                                                                 ConsoleFun_Struct_Color_White};

#endif // ConsoleFun_H
