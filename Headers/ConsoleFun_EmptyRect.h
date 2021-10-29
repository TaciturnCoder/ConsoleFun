
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

    void ConsoleFun_EmptyRect(CFOpts Options)
    {
        int i;

        ConsoleFun_SetColor(Options.FG, Options.BG);

        ConsoleFun_GotoRC(Options.Row, Options.Col);
        for (i = 0; i < Options.Cols; i += 1)
        {
            printf(" ");
        }

        ConsoleFun_GotoRC(Options.Row + Options.Rows - 1, Options.Col);
        for (i = 0; i < Options.Cols; i += 1)
        {
            printf(" ");
        }

        for (i = 2; i < Options.Rows; i += 1)
        {
            ConsoleFun_GotoRC(Options.Row + i - 1, Options.Col);
            printf(" ");
            ConsoleFun_GotoRC(Options.Row + i - 1, Options.Col + Options.Cols - 1);
            printf(" ");
        }
        return;
    } // ConsoleFun_EmptyRect

#endif // ConsoleFun_Include

#ifdef __cplusplus
}
#endif
