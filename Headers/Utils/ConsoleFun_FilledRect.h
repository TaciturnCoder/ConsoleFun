
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_H
#define ConsoleFun_Utils_FilledRect_H 1

void ConsoleFun_Utils_FilledRect(CFOpts Options)
{
    CFOpts Temp;

    ConsoleFun_Struct_Cache_Flag_ RequiredFlag = ConsoleFun.Struct.Cache.Flag.Init;

    if ((ConsoleFun.Struct.Cache.Status & RequiredFlag) == RequiredFlag)
    {
        Temp = ConsoleFun.CloneOpts(Options);

        for (; Temp.Rows > 0;)
        {
            ConsoleFun.Utils.EmptyRect(Temp);
            Temp.Row += 1;
            Temp.Col += 1;
            Temp.Rows -= 2;
            Temp.Cols -= 2;
        }
    }

    return;
} // ConsoleFun_Utils_FilledRect

#endif // ConsoleFun_H
