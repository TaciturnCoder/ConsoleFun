
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_H
#define ConsoleFun_Native_GotoRC_H 1

void ConsoleFun_Native_GotoRC(int Row, int Col)
{
    if ((ConsoleFun.Struct.Cache.Status & ConsoleFun.Struct.Cache.Flag.Init) == ConsoleFun.Struct.Cache.Flag.Init)
    {
#ifdef __linux__
        printf("%c[%d;%df", 0x1B, Row + 1, Col + 1);
        fflush(stdout);
        ConsoleFun.Struct.Cache.Status = ConsoleFun.Struct.Cache.Status | ConsoleFun.Struct.Cache.Flag.GotoRC;
#elif _WIN32
        COORD Coordinates;
        HANDLE hConsole = ConsoleFun.Struct.Cache.hConsoleOut;

        Coordinates.X = Col;
        Coordinates.Y = Row;
        if (SetConsoleCursorPosition(hConsole, Coordinates))
            ConsoleFun.Struct.Cache.Status = ConsoleFun.Struct.Cache.Status | ConsoleFun.Struct.Cache.Flag.GotoRC;
        else
            ConsoleFun.Struct.Cache.Status = ConsoleFun.Struct.Cache.Status & (~ConsoleFun.Struct.Cache.Flag.GotoRC);
#endif
    }
    return;
} // ConsoleFun_Native_GotoRC

#endif // ConsoleFun_H
