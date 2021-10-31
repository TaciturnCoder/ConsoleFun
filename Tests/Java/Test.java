// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

package Tests.Java;

import ConsoleFunJNI.ConsoleFun;
import ConsoleFunJNI.CFOpts;

public class Test {
    public static void main(String args[]) {

        ConsoleFun.LoadLib("./ConsoleFunJNI");

        char Str[];
        CFOpts Options = ConsoleFun.GetOpts();

        Options.BG = ConsoleFun.Color.Yellow;
        Options.Row = 0;
        Options.Col = 0;
        ConsoleFun.FilledRect(Options);

        Options.Row = 1;
        Options.Col = 1;
        Options.Rows -= 2;
        Options.Cols -= 2;
        Options.BG = ConsoleFun.Color.Red;
        ConsoleFun.EmptyRect(Options);

        Options.Row = 5;
        Options.Col = 5;
        Options.Rows = 5;
        Options.Cols = 40;
        Options.BG = ConsoleFun.Color.Black;
        ConsoleFun.GotoRC(4, 5);

        System.out.print("Enter text Here: ");
        Str = ConsoleFun.ReadBox(Options);

        ConsoleFun.GotoRC(14, 5);
        Options.Row = 15;
        Options.FG = ConsoleFun.Color.Black;
        Options.BG = ConsoleFun.Color.Cyan;

        System.out.print("You Entered: ");
        ConsoleFun.WriteBox(Str, Options);

        ConsoleFun.GetCh();
        return;
    } // main
}
