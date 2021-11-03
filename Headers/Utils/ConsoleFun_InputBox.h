
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_H
#define ConsoleFun_Utils_InputBox_H 1

char *ConsoleFun_Utils_InputBox(CFOpts Options)
{
    int i, j, k = -1, *EOL, JFlag = 0;
    char Ch, *Str;

    ConsoleFun_Struct_Cache_Flag_ RequiredFlag = ConsoleFun.Struct.Cache.Flag.Init | ConsoleFun.Struct.Cache.Flag.GetCh | ConsoleFun.Struct.Cache.Flag.GotoRC;

    if ((ConsoleFun.Struct.Cache.Status & RequiredFlag) == RequiredFlag)
    {
        ConsoleFun.Utils.FilledRect(Options);

        EOL = (int *)malloc(sizeof(int) * Options.Rows + 1);
        Str = (char *)malloc(sizeof(char) * Options.Rows * Options.Cols + 1);

        for (i = 0; i < Options.Rows; i += 1)
        {
            ConsoleFun.Native.GotoRC(Options.Row + i, Options.Col);

            for (j = 0; j < Options.Cols; j += 1)
            {
                if (JFlag)
                {
                    j = EOL[i];

                    ConsoleFun.Native.GotoRC(Options.Row + i, Options.Col + j);

                    if (j + 1 == Options.Cols)
                    {
                        printf(" \b");
                    }

                    JFlag = 0;
                }

                ConsoleFun.Struct.KeyMap.Status = 0;
                Ch = ConsoleFun.Native.GetCh();

                if ((ConsoleFun.Struct.KeyMap.Status & ConsoleFun.Struct.KeyMap.Flag.Esc) == ConsoleFun.Struct.KeyMap.Flag.Esc)
                {
                    j -= 1;
                }
                else if (Ch == ConsoleFun.Struct.KeyMap.NL || Ch == ConsoleFun.Struct.KeyMap.CR)
                {
                    k += 1;
                    Str[k] = '\n';
                    j += 1;
                    break;
                }
                /*
                else if (Ch == '\0')
                {
                    // Case not possible?
                }
                */
                else if (Ch == ConsoleFun.Struct.KeyMap.TAB)
                {
                    i = Options.Rows;
                    break;
                }
                else if (Ch == ConsoleFun.Struct.KeyMap.BS || Ch == ConsoleFun.Struct.KeyMap.DEL) // \b or DEL
                {
                    if (j > 0)
                    {
                        printf("\b \b");
                        j -= 2;
                        k -= 1;
                    }
                    else if (i > 0)
                    {
                        JFlag = 1;
                        i -= 2;
                        k -= 1;
                        break;
                    }
                    else
                    {
                        j -= 1;
                    }
                }
                else
                {
                    if (Ch >= ConsoleFun.Struct.KeyMap.FirstPrintable && Ch <= ConsoleFun.Struct.KeyMap.LastPrintable)
                    {
                        k += 1;
                        Str[k] = Ch;
                        printf("%c", Ch);
                    }
                    else
                    {
                        j -= 1;
                    }
                }
            }

            if (!JFlag)
            {
                EOL[i] = j - 1;
            }
        }

        k += 1;
        Str[k] = '\0';
    }

    return Str;
} // ConsoleFun_Utils_InputBox

#endif // ConsoleFun_H
