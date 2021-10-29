
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

    CFOpts ConsoleFun_GetOpts()
    {
        CFOpts Options;

        Options.Row = 0;
        Options.Col = 0;

#ifdef __linux__
        struct winsize max;
        ioctl(0, TIOCGWINSZ, &max);

        Options.Rows = max.ws_row;
        Options.Cols = max.ws_col;

        Options.Col = 0;
        Options.Row = 0;
#elif _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO CSBI;
        COORD Coordinates;

        GetConsoleScreenBufferInfo(hConsole, &CSBI);
        Coordinates = CSBI.dwCursorPosition;

        Options.Cols = CSBI.srWindow.Right - CSBI.srWindow.Left + 1;
        Options.Rows = CSBI.srWindow.Bottom - CSBI.srWindow.Top + 1;

        Options.Col = Coordinates.X;
        Options.Row = Coordinates.Y;
#endif
        Options.FG = ConsoleFun_Color.Cyan;
        Options.BG = ConsoleFun_Color.Black;

        return Options;
    } // ConsoleFun_GetOpts

#endif // ConsoleFun_Include

#ifdef __cplusplus
}
#endif
