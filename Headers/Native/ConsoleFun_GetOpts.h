
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_H
#define ConsoleFun_Native_GetOpts_H 1

CFOpts ConsoleFun_Native_GetOpts()
{
    CFOpts Options = ConsoleFun.CloneOpts(ConsoleFun.NullOpts);

    if ((ConsoleFun.Struct.Cache.Status & ConsoleFun.Struct.Cache.Flag.Init) == ConsoleFun.Struct.Cache.Flag.Init)
    {
#ifdef __linux__
        struct winsize max;
        if (ioctl(0, TIOCGWINSZ, &max) >= 0)
        {
            ConsoleFun.Struct.Cache.Status = ConsoleFun.Struct.Cache.Status | ConsoleFun.Struct.Cache.Flag.GetOpts;

            Options.Cols = max.ws_col;
            Options.Rows = max.ws_row;

            Options.Col = 0;
            Options.Row = 0;
        }
        else
            ConsoleFun.Struct.Cache.Status = ConsoleFun.Struct.Cache.Status & (~ConsoleFun.Struct.Cache.Flag.GetOpts);
#elif _WIN32
        HANDLE hConsole = ConsoleFun.Struct.Cache.hConsoleOut;
        CONSOLE_SCREEN_BUFFER_INFO CSBI;
        COORD Coordinates;

        if (GetConsoleScreenBufferInfo(hConsole, &CSBI))
        {
            ConsoleFun.Struct.Cache.Status = ConsoleFun.Struct.Cache.Status | ConsoleFun.Struct.Cache.Flag.GetOpts;
            Coordinates = CSBI.dwCursorPosition;

            Options.Cols = CSBI.srWindow.Right - CSBI.srWindow.Left + 1;
            Options.Rows = CSBI.srWindow.Bottom - CSBI.srWindow.Top + 1;

            Options.Col = Coordinates.X;
            Options.Row = Coordinates.Y;
        }
        else
            ConsoleFun.Struct.Cache.Status = ConsoleFun.Struct.Cache.Status & (~ConsoleFun.Struct.Cache.Flag.GetOpts);
#endif
    }

    return Options;
} // ConsoleFun_Native_GetOpts

#endif // ConsoleFun_H
