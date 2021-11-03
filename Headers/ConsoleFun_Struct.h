
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_H
#define ConsoleFun_Struct_H 1

#include "./Struct/ConsoleFun_Cache.h"
#include "./Struct/ConsoleFun_Color.h"
#include "./Struct/ConsoleFun_KeyMap.h"
/**
 * @brief Object to access all structures
 *
 */
struct ConsoleFun_Struct_
{
    struct ConsoleFun_Struct_Cache_ Cache;
    struct ConsoleFun_Struct_Color_ Color;
    struct ConsoleFun_Struct_KeyMap_ KeyMap;
};

const struct ConsoleFun_Struct_ ConsoleFun_Struct = {ConsoleFun_Struct_Cache,
                                                     ConsoleFun_Struct_Color,
                                                     ConsoleFun_Struct_KeyMap};

char ConsoleFun_Native_GetCh();
CFOpts ConsoleFun_Native_GetOpts();
void ConsoleFun_Native_GotoRC(int, int);
void ConsoleFun_Native_SetColor(int, int);
/**
 * @brief Object to access native methods
 *
 */
struct ConsoleFun_Native_
{
    char (*GetCh)();
    CFOpts (*GetOpts)();
    void (*GotoRC)(int, int);
    void (*SetColor)(int, int);
};

const struct ConsoleFun_Native_ ConsoleFun_Native = {ConsoleFun_Native_GetCh,
                                                     ConsoleFun_Native_GetOpts,
                                                     ConsoleFun_Native_GotoRC,
                                                     ConsoleFun_Native_SetColor};

void ConsoleFun_Utils_EmptyRect(CFOpts);
void ConsoleFun_Utils_FilledRect(CFOpts);
char *ConsoleFun_Utils_InputBox(CFOpts);
void ConsoleFun_Utils_PrintBox(char *, CFOpts);
/**
 * @brief Object to access utility methods
 *
 */
struct ConsoleFun_Utils_
{
    void (*EmptyRect)(CFOpts);
    void (*FilledRect)(CFOpts);
    char *(*InputBox)(CFOpts);
    void (*PrintBox)(char *, CFOpts);
};

const struct ConsoleFun_Utils_ ConsoleFun_Utils = {ConsoleFun_Utils_EmptyRect,
                                                   ConsoleFun_Utils_FilledRect,
                                                   ConsoleFun_Utils_InputBox,
                                                   ConsoleFun_Utils_PrintBox};
#endif // ConsoleFun_H
