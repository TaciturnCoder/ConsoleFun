
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_H
#define ConsoleFun_Native_GetCh_H 1

char ConsoleFun_Native_GetCh()
{
    char Ch = 0;

    if ((ConsoleFun.Struct.Cache.Status & ConsoleFun.Struct.Cache.Flag.Init) == ConsoleFun.Struct.Cache.Flag.Init)
    {
#ifdef __linux__
        struct termios Old, Current;
        fflush(stdout);

        if (tcgetattr(0, &Old) >= 0)
        {
            ConsoleFun.Struct.Cache.Status = ConsoleFun.Struct.Cache.Status | ConsoleFun.Struct.Cache.Flag.GetCh;
            Current = Old;
            Current.c_lflag &= ~ICANON;
            Current.c_lflag &= ~ECHO;
            Current.c_cc[VMIN] = 1;
            Current.c_cc[VTIME] = 0;
            tcsetattr(0, TCSANOW, &Current);
            read(0, &Ch, 1);
            if (tcsetattr(0, TCSANOW, &Old) < 0)
                ConsoleFun.Struct.Cache.Status = ConsoleFun.Struct.Cache.Status & (~ConsoleFun.Struct.Cache.Flag.GetCh);
        }
        else
            ConsoleFun.Struct.Cache.Status = ConsoleFun.Struct.Cache.Status & (~ConsoleFun.Struct.Cache.Flag.GetCh);
#elif _WIN32
        DWORD mode, cc;
        HANDLE hConsole = ConsoleFun.Struct.Cache.hConsoleIn;

        if (GetConsoleMode(hConsole, &mode))
        {
            ConsoleFun.Struct.Cache.Status = ConsoleFun.Struct.Cache.Status | ConsoleFun.Struct.Cache.Flag.GetCh;
            SetConsoleMode(hConsole, mode & ~ENABLE_LINE_INPUT);
            ReadConsole(hConsole, &Ch, 1, &cc, NULL);
            if (!SetConsoleMode(hConsole, mode))
                ConsoleFun.Struct.Cache.Status = ConsoleFun.Struct.Cache.Status & (~ConsoleFun.Struct.Cache.Flag.GetCh);
        }
        else
            ConsoleFun.Struct.Cache.Status = ConsoleFun.Struct.Cache.Status & (~ConsoleFun.Struct.Cache.Flag.GetCh);
#endif
    }

#ifdef __linux__
    if (Ch == ConsoleFun.Struct.KeyMap.DEL)
        Ch = ConsoleFun.Struct.KeyMap.BS;
#elif _WIN32
#endif

    if (Ch == ConsoleFun.Struct.KeyMap.ESC)
    {
        ConsoleFun.Struct.KeyMap.Status = ConsoleFun.Struct.KeyMap.Status | ConsoleFun.Struct.KeyMap.Flag.Esc;
        Ch = ConsoleFun.Native.GetCh();

        if (Ch == '[')
        {
            Ch = ConsoleFun.Native.GetCh();

            if (Ch >= ConsoleFun.Struct.KeyMap.ArrowUp && Ch <= ConsoleFun.Struct.KeyMap.ArrowLeft)
            {
                ConsoleFun.Struct.KeyMap.Status = ConsoleFun.Struct.KeyMap.Status | ConsoleFun.Struct.KeyMap.Flag.Arrow;
            }
            else if (Ch == '3')
            {
                Ch = ConsoleFun.Native.GetCh();
                if (Ch == '~')
                    Ch = ConsoleFun.Struct.KeyMap.DEL;
            }
        }
        else if (Ch >= ConsoleFun.Struct.KeyMap.FirstPrintable && Ch <= ConsoleFun.Struct.KeyMap.LastPrintable)
        {
            ConsoleFun.Struct.KeyMap.Status = ConsoleFun.Struct.KeyMap.Status | ConsoleFun.Struct.KeyMap.Flag.Alt;
        }
    }

    return Ch;
} // ConsoleFun_Native_GetCh

#endif // ConsoleFun_H
