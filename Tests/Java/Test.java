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

        char Str[];
        ConsoleFun.Init("./ConsoleFunJNI");

        CFOpts Options = ConsoleFun.Native.GetOpts();
        System.out.print(ConsoleFun.Struct.Cache.Status);

        Options.BG = ConsoleFun.Struct.Color.Yellow;
        Options.Row = 0;
        Options.Col = 0;
        ConsoleFun.Utils.FilledRect(Options);

        Options.Row = 1;
        Options.Col = 1;
        Options.Rows -= 2;
        Options.Cols -= 2;
        Options.BG = ConsoleFun.Struct.Color.Red;
        ConsoleFun.Utils.EmptyRect(Options);

        Options.Row = 5;
        Options.Col = 5;
        Options.Rows = 5;
        Options.Cols = 40;
        Options.FG = ConsoleFun.Struct.Color.Blue;
        Options.BG = ConsoleFun.Struct.Color.Black;
        ConsoleFun.Native.GotoRC(4, 5);

        System.out.print("Enter text Here: ");
        Str = ConsoleFun.Utils.InputBox(Options);

        ConsoleFun.Native.GotoRC(14, 5);
        Options.Row = 15;
        Options.FG = ConsoleFun.Struct.Color.Black;
        Options.BG = ConsoleFun.Struct.Color.Cyan;
        System.out.print("You Entered: ");
        ConsoleFun.Utils.PrintBox(Str, Options);

        ConsoleFun.Native.GetCh();
        ConsoleFun.Native.SetColor(ConsoleFun.NullOpts.FG, ConsoleFun.NullOpts.BG);
        return;
    } // main
}
