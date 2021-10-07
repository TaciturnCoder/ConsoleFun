
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

package ConsoleFun_test_Java;

import ConsoleFun.ConsoleFun;
import ConsoleFun.cfopts;

public class ConsoleFun_test {
    public static void main(String args[]) {
        cfopts opts = new cfopts();

        opts.rows = 20;
        opts.cols = 20;

        opts.fg = 0;
        opts.bg = ConsoleFun.COLOR_YELLOW;

        ConsoleFun.emptyrect(1, 1, opts);

        opts.rows -= 4;
        opts.cols -= 4;
        opts.fg = ConsoleFun.COLOR_BLACK;
        opts.bg = ConsoleFun.COLOR_RED;
        ConsoleFun.filledrect(3, 3, opts);

        ConsoleFun.gotorc(10, 15);
        ConsoleFun.setcolor(ConsoleFun.COLOR_CYAN, ConsoleFun.COLOR_BLACK);
        System.out.print("Hello World");
    }
}
