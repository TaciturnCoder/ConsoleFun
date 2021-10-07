
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

#ifndef ConsoleFun_
#define ConsoleFun_ 1

#include <stdio.h>
#include <stdlib.h>

#ifdef __linux__
#elif _WIN32
#endif

#ifdef __linux__
#include <sys/ioctl.h>
#elif _WIN32
#include <windows.h>
#endif

#ifdef __linux__
    enum
    {
        ConsoleFun_COLOR_BLACK,
        ConsoleFun_COLOR_RED,
        ConsoleFun_COLOR_GREEN,
        ConsoleFun_COLOR_YELLOW,
        ConsoleFun_COLOR_BLUE,
        ConsoleFun_COLOR_MAGENTA,
        ConsoleFun_COLOR_CYAN,
        ConsoleFun_COLOR_WHITE
    };
#elif _WIN32
    enum
    {
        ConsoleFun_COLOR_BLACK,
        ConsoleFun_COLOR_BLUE,
        ConsoleFun_COLOR_GREEN,
        ConsoleFun_COLOR_CYAN,
        ConsoleFun_COLOR_RED,
        ConsoleFun_COLOR_MAGENTA,
        ConsoleFun_COLOR_YELLOW,
        ConsoleFun_COLOR_WHITE
    };
#endif

    typedef struct
    {
        int rows;
        int cols;

        int fg;
        int bg;
    } cfopts;

    cfopts ConsoleFun_getopts();
    void ConsoleFun_gotorc(int, int);
    void ConsoleFun_setcolor(int, int);
    void ConsoleFun_emptyrect(int, int, cfopts);
    void ConsoleFun_filledrect(int, int, cfopts);

    cfopts ConsoleFun_getopts()
    {
        cfopts opts;

#ifdef __linux__
        struct winsize max;
        ioctl(0, TIOCGWINSZ, &max);

        opts.rows = max.ws_row;
        opts.cols = max.ws_col;
#elif _WIN32
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int cols, rows;

        GetConsoleScreenBufferInfo(handle, &csbi);
        cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        opts.rows = rows;
        opts.cols = cols;
#endif

        opts.fg = ConsoleFun_COLOR_WHITE;
        opts.bg = ConsoleFun_COLOR_BLACK;

        return opts;
    }

    void ConsoleFun_gotorc(int row, int col)
    {
#ifdef __linux__
        printf("%c[%d;%df", 0x1B, row + 1, col + 1);
#elif _WIN32
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD coordinates;
        coordinates.X = col;
        coordinates.Y = row;
        SetConsoleCursorPosition(handle, coordinates);
#endif

        return;
    }

    void ConsoleFun_setcolor(int fg, int bg)
    {
#ifdef __linux__
        printf("%c[%d;%dm", 0x1B, fg + 30, bg + 40);
#elif _WIN32
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(handle, bg * 16 + fg);
#endif

        return;
    }

    void ConsoleFun_emptyrect(int row, int col, cfopts opts)
    {
        int i, j;

        ConsoleFun_setcolor(opts.fg, opts.bg);

        ConsoleFun_gotorc(row, col);
        for (j = 0; j < opts.cols; j += 1)
        {
            printf(" ");
        }

        ConsoleFun_gotorc(row + opts.rows - 1, col);
        for (j = 0; j < opts.cols; j += 1)
        {
            printf(" ");
        }

        for (i = 2; i < opts.rows; i += 1)
        {
            ConsoleFun_gotorc(row + i - 1, col);
            printf(" ");
            ConsoleFun_gotorc(row + i - 1, col + opts.cols - 1);
            printf(" ");
        }

        return;
    }

    void ConsoleFun_filledrect(int row, int col, cfopts opts)
    {
        row -= 1;
        col -= 1;
        opts.cols += 2;
        for (; opts.rows > 0; opts.rows -= 2)
        {
            row += 1;
            col += 1;
            opts.cols -= 2;
            ConsoleFun_emptyrect(row, col, opts);
        }

        return;
    }

#endif // ConsoleFun_

#ifdef __cplusplus
}
#endif
