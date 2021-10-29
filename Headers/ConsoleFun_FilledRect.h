
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

    void ConsoleFun_FilledRect(CFOpts Options)
    {
        for (; Options.Rows > 0;)
        {
            ConsoleFun_EmptyRect(Options);
            Options.Row += 1;
            Options.Col += 1;
            Options.Rows -= 2;
            Options.Cols -= 2;
        }

        return;
    } // ConsoleFun_FilledRect

#endif // ConsoleFun_Include

#ifdef __cplusplus
}
#endif
