
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

#ifdef ConsoleFun_Include

    void ConsoleFun_GotoRC(int Row, int Col)
    {
#ifdef __linux__
        printf("%c[%d;%df", 0x1B, Row + 1, Col + 1);
#elif _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD Coordinates;

        Coordinates.X = Col;
        Coordinates.Y = Row;
        SetConsoleCursorPosition(hConsole, Coordinates);
#endif
        return;
    } // ConsoleFun_GotoRC

#endif // ConsoleFun_Include

#ifdef __cplusplus
}
#endif
