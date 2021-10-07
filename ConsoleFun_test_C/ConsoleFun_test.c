
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#include <stdio.h>
#include "../ConsoleFun.h"

int main()
{
    cfopts opts = ConsoleFun_getopts();

    opts.bg = ConsoleFun_COLOR_YELLOW;
    ConsoleFun_emptyrect(0, 0, opts);

    opts.rows -= 4;
    opts.cols -= 4;
    opts.fg = ConsoleFun_COLOR_BLACK;
    opts.bg = ConsoleFun_COLOR_RED;
    ConsoleFun_filledrect(2, 2, opts);

    ConsoleFun_gotorc(10, 15);
    ConsoleFun_setcolor(ConsoleFun_COLOR_CYAN, ConsoleFun_COLOR_BLACK);
    printf("Hello World!\n\tDIMENSIONS: %dx%d", opts.rows, opts.cols);

    return 0;
}