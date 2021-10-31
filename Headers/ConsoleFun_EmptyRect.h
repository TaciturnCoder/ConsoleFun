
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_CFOpts_
#define ConsoleFun_EmptyRect_ 1

void ConsoleFun_EmptyRect(CFOpts Options)
{
    int i;

    ConsoleFun.SetColor(Options.FG, Options.BG);

    ConsoleFun.GotoRC(Options.Row, Options.Col);
    for (i = 0; i < Options.Cols; i += 1)
    {
        printf(" ");
    }

    ConsoleFun.GotoRC(Options.Row + Options.Rows - 1, Options.Col);
    for (i = 0; i < Options.Cols; i += 1)
    {
        printf(" ");
    }

    for (i = 2; i < Options.Rows; i += 1)
    {
        ConsoleFun.GotoRC(Options.Row + i - 1, Options.Col);
        printf(" ");
        ConsoleFun.GotoRC(Options.Row + i - 1, Options.Col + Options.Cols - 1);
        printf(" ");
    }
    return;
} // ConsoleFun_EmptyRect

#endif // ConsoleFun_CFOpts_
