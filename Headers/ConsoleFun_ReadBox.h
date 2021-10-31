
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_CFOpts_
#define ConsoleFun_ReadBox_ 1

char *ConsoleFun_ReadBox(CFOpts Options)
{
    int i, j, k = -1, *EOL, JFlag = 0, SFlag = 0;
    char Ch, *Str;
    ConsoleFun.FilledRect(Options);

    EOL = (int *)malloc(sizeof(int) * Options.Rows + 1);
    Str = (char *)malloc(sizeof(char) * Options.Rows * Options.Cols + 1);

    for (i = 0; i < Options.Rows; i += 1)
    {
        ConsoleFun.GotoRC(Options.Row + i, Options.Col);

        for (j = 0; j < Options.Cols; j += 1)
        {
            if (JFlag)
            {
                j = EOL[i];

                ConsoleFun.GotoRC(Options.Row + i, Options.Col + j);

                if (j + 1 == Options.Cols)
                {
                    printf(" \b");
                }

                JFlag = 0;
            }

            Ch = ConsoleFun.GetCh();

            if (Ch == 0x1B)
            {
                SFlag = 1;
                j -= 1;
            }
            else if (Ch == '\n' || Ch == '\r')
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
            else if (Ch == '\t')
            {
                i = Options.Rows;
                break;
            }
            else if (Ch == '\b' || Ch == 127) // \b or DEL
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
                if (Ch > 31 && Ch < 127)
                {
                    if (SFlag > 0)
                    {
                        if ((Ch >= 'a' && Ch <= 'z') || (Ch >= 'A' && Ch <= 'Z'))
                        {
                            SFlag = 0;
                        }
                        j -= 1;
                    }
                    else
                    {
                        k += 1;
                        Str[k] = Ch;
                        printf("%c", Ch);
                    }
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

    return Str;
} // ConsoleFun_ReadBox

#endif // ConsoleFun_CFOpts_
