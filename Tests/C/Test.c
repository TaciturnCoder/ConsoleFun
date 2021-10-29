
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#include <stdio.h>
#include "../../Headers/ConsoleFun.h"

int main()
{
    CFOpts Options = ConsoleFun.GetOpts();

    Options.BG = ConsoleFun.Color.Yellow;
    Options.Row = 0;
    Options.Col = 0;
    ConsoleFun.EmptyRect(Options);

    Options.Row = 2;
    Options.Col = 2;
    Options.Rows -= 4;
    Options.Cols -= 4;
    Options.FG = ConsoleFun.Color.Black;
    Options.BG = ConsoleFun.Color.Red;
    ConsoleFun.FilledRect(Options);

    ConsoleFun.GotoRC(10, 15);
    ConsoleFun.SetColor(ConsoleFun.Color.Cyan, ConsoleFun.Color.Black);
    printf("Hello World!");

    return 0;
}