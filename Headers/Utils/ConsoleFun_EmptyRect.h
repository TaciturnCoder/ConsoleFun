
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_H
#define ConsoleFun_Utils_EmptyRect_H 1

void ConsoleFun_Utils_EmptyRect(CFOpts Options)
{
    int i;
    char *Line;
    ConsoleFun_Struct_Cache_Flag_ RequiredFlag = ConsoleFun.Struct.Cache.Flag.Init | ConsoleFun.Struct.Cache.Flag.GotoRC | ConsoleFun.Struct.Cache.Flag.SetColor;

    if ((ConsoleFun.Struct.Cache.Status & RequiredFlag) == RequiredFlag)
    {
        Line = (char *)malloc(sizeof(char) * Options.Cols + 1);
        for (i = 0; i < Options.Cols; i += 1)
        {
            Line[i] = ' ';
        }
        Line[Options.Cols] = '\0';

        ConsoleFun.Native.SetColor(Options.FG, Options.BG);

        ConsoleFun.Native.GotoRC(Options.Row, Options.Col);
        printf("%s", Line);
        ConsoleFun.Native.GotoRC(Options.Row + Options.Rows - 1, Options.Col);
        printf("%s", Line);

        for (i = 2; i < Options.Rows; i += 1)
        {
            ConsoleFun.Native.GotoRC(Options.Row + i - 1, Options.Col);
            printf(" ");
            ConsoleFun.Native.GotoRC(Options.Row + i - 1, Options.Col + Options.Cols - 1);
            printf(" ");
        }
    }
    return;
} // ConsoleFun_Utils_EmptyRect

#endif // ConsoleFun_H
