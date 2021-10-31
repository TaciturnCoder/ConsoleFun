
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_CFOpts_
#define ConsoleFun_WriteBox_ 1

void ConsoleFun_WriteBox(char *Str, CFOpts Options)
{
    int i, j, k = 0;
    char Ch;
    ConsoleFun.FilledRect(Options);

    for (i = 0; i < Options.Rows; i += 1)
    {
        ConsoleFun.GotoRC(Options.Row + i, Options.Col);

        for (j = 0; j < Options.Cols; j += 1)
        {
            Ch = Str[k];

            if (Ch == '\n')
            {
                k += 1;
                break;
            }
            else if (Ch == '\r')
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
            else if (Ch == '\t')
            {
                printf(" ");
            }
            else if (Ch == '\b')
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

    fflush(stdin);
    return;
} // ConsoleFun_WriteBox

#endif // ConsoleFun_CFOpts_
