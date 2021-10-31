
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_CFOpts_
#define ConsoleFun_GotoRC_ 1

void ConsoleFun_GotoRC(int Row, int Col)
{
#ifdef __linux__
    printf("%c[%d;%df", 0x1B, Row + 1, Col + 1);
#elif _WIN32
    HANDLE hConsole;
    COORD Coordinates;
    if (ConsoleFun.Cache.hConsoleOut == NULL)
    {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        ConsoleFun.Cache.hConsoleOut = hConsole;
    }
    else
    {
        hConsole = ConsoleFun.Cache.hConsoleOut;
    }

    Coordinates.X = Col;
    Coordinates.Y = Row;
    SetConsoleCursorPosition(hConsole, Coordinates);
#endif
    return;
} // ConsoleFun_GotoRC

#endif // ConsoleFun_CFOpts_
