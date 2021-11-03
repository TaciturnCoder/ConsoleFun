
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_H
#define ConsoleFun_Init_H 1

/**
 * @brief Initialize ConsoleFun
 *
 */
void ConsoleFun_Init()
{
    ConsoleFun.NullOpts.BG = ConsoleFun.Struct.Color.Blue;
    ConsoleFun.NullOpts.FG = ConsoleFun.Struct.Color.Black;

    if ((ConsoleFun.Struct.Cache.Status & ConsoleFun.Struct.Cache.Flag.Init) != ConsoleFun.Struct.Cache.Flag.Init)
    {
#ifdef __linux__
#elif _WIN32
        ConsoleFun.Struct.Cache.hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (ConsoleFun.Struct.Cache.hConsoleOut == INVALID_HANDLE_VALUE)
            return;

        ConsoleFun.Struct.Cache.hConsoleIn = GetStdHandle(STD_INPUT_HANDLE);
        if (ConsoleFun.Struct.Cache.hConsoleIn == INVALID_HANDLE_VALUE)
            return;
#endif

        ConsoleFun.Struct.Cache.Status = ConsoleFun.Struct.Cache.Status | ConsoleFun.Struct.Cache.Flag.Init;
    }
    return;
} // ConsoleFun_Init

#endif // ConsoleFun_H
