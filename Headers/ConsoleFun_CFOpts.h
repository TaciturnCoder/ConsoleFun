
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

#ifdef ConsoleFun_H
#define ConsoleFun_CFOpts_H 1

/**
 * @brief ConsoleFun Options - Object to store frequently used data
 *
 */
typedef struct ConsoleFun_CFOpts_
{
    int Row;
    int Col;

    int Rows;
    int Cols;

    int FG;
    int BG;
} CFOpts;

CFOpts ConsoleFun_CloneOpts(CFOpts Options)
{
    return Options;
} // ConsoleFun_CloneOpts

#endif // ConsoleFun_H
