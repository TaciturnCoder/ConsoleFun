
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

package ConsoleFunJNI;

public class ConsoleFun {
    public static int COLOR_BLACK = 0;
    public static int COLOR_BLUE = 1;
    public static int COLOR_GREEN = 2;
    public static int COLOR_CYAN = 3;
    public static int COLOR_RED = 4;
    public static int COLOR_MAGENTA = 5;
    public static int COLOR_YELLOW = 6;
    public static int COLOR_WHITE = 7;

    public native static cfopts getopts();

    public native static void gotorc(int row, int col);

    public native static void setcolor(int fg, int bg);

    public native static void emptyrect(int row, int col, cfopts opts);

    public native static void filledrect(int row, int col, cfopts opts);
}