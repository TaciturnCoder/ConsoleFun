
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_CFOpts_
#define ConsoleFun_GetCh_ 1

char ConsoleFun_GetCh()
{
    char Ch = 0;
#ifdef __linux__
    struct termios Old = {0}, Current;
    fflush(stdout);
    tcgetattr(0, &Old);
    Current = Old;
    Current.c_lflag &= ~ICANON;
    Current.c_lflag &= ~ECHO;
    Current.c_cc[VMIN] = 1;
    Current.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &Current);
    read(0, &Ch, 1);
    tcsetattr(0, TCSANOW, &Old);
#elif _WIN32
    DWORD mode, cc;
    HANDLE hConsole;

    if (ConsoleFun.Cache.hConsoleIn == NULL)
    {
        hConsole = GetStdHandle(STD_INPUT_HANDLE);
        ConsoleFun.Cache.hConsoleIn = hConsole;
    }
    else
    {
        hConsole = ConsoleFun.Cache.hConsoleIn;
    }

    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode & ~ENABLE_LINE_INPUT);
    ReadConsole(hConsole, &Ch, 1, &cc, NULL);
    SetConsoleMode(hConsole, mode);
#endif

    return Ch;
} // ConsoleFun_GetCh

#endif // ConsoleFun_CFOpts_
