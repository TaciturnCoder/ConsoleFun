
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_H
#define ConsoleFun_Utils_PrintBox_H 1

void ConsoleFun_Utils_PrintBox(char *Str, CFOpts Options)
{
    int i, j, k = 0;
    char Ch;

    ConsoleFun_Struct_Cache_Flag_ RequiredFlag = ConsoleFun.Struct.Cache.Flag.Init | ConsoleFun.Struct.Cache.Flag.GetCh | ConsoleFun.Struct.Cache.Flag.GotoRC;

    if ((ConsoleFun.Struct.Cache.Status & RequiredFlag) == RequiredFlag)
    {
        ConsoleFun.Utils.FilledRect(Options);

        for (i = 0; i < Options.Rows; i += 1)
        {
            ConsoleFun.Native.GotoRC(Options.Row + i, Options.Col);

            for (j = 0; j < Options.Cols; j += 1)
            {
                Ch = Str[k];

                if (Ch == ConsoleFun.Struct.KeyMap.NL)
                {
                    k += 1;
                    break;
                }
                else if (Ch == ConsoleFun.Struct.KeyMap.CR)
                {
                    i -= 1;
                    k += 1;
                    break;
                }
                else if (Ch == '\0')
                {
                    i = Options.Row;
                    break;
                }
                else if (Ch == ConsoleFun.Struct.KeyMap.TAB)
                {
                    printf(" ");
                }
                else if (Ch == ConsoleFun.Struct.KeyMap.BS || Ch == ConsoleFun.Struct.KeyMap.DEL)
                {
                    if (j > 0)
                    {
                        printf("\b \b");
                        j -= 1;
                    }
                }
                else
                {
                    printf("%c", Ch);
                }

                k += 1;
            }
        }
    }

    fflush(stdout);
    return;
} // ConsoleFun_Utils_PrintBox

#endif // ConsoleFun_H
