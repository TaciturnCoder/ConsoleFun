
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

import ConsoleFunJNI.ConsoleFun;
import ConsoleFunJNI.cfopts;

import java.io.File;

public class ConsoleFun_Test {
    public static void main(String args[]) {
        File lib = new File("../../" + System.mapLibraryName("ConsoleFunJNI"));
        System.load(lib.getAbsolutePath());

        cfopts opts = new cfopts();

        opts.rows = 20;
        opts.cols = 40;

        opts.fg = 0;
        opts.bg = ConsoleFun.COLOR_YELLOW;

        ConsoleFun.emptyrect(0, 0, opts);

        opts.rows -= 4;
        opts.cols -= 4;
        opts.fg = ConsoleFun.COLOR_BLACK;
        opts.bg = ConsoleFun.COLOR_RED;
        ConsoleFun.filledrect(2, 2, opts);

        ConsoleFun.gotorc(10, 15);
        ConsoleFun.setcolor(ConsoleFun.COLOR_CYAN, ConsoleFun.COLOR_BLACK);
        System.out.print("Hello World");
    }
}
