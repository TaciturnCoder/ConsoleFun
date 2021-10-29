
// Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
//                                                                     //
// Licensed under the Taciturn Coder License v0.0.1, the "License";    //
// You may not use this file except in compliance with the License.    //
// You may obtain a copy of the License at:                            //
//         https://taciturncoder.github.io/License/v0-0-1              //
//                                                                     //
// See the License for the permissions and limitations.                //

package ConsoleFunJNI;

import java.io.File;

public class ConsoleFun {
    public static class Color {
        public static int Black = 0;
        public static int Blue = 1;
        public static int Green = 2;
        public static int Cyan = 3;
        public static int Red = 4;
        public static int Magenta = 5;
        public static int Yellow = 6;
        public static int White = 7;
    }

    public native static CFOpts GetOpts();

    public native static void GotoRC(int Row, int Col);

    public native static void SetColor(int FG, int BG);

    public static void EmptyRect(CFOpts Options) {
        int i;

        SetColor(Options.FG, Options.BG);

        GotoRC(Options.Row, Options.Col);
        for (i = 0; i < Options.Cols; i += 1) {
            System.out.print(" ");
        }

        GotoRC(Options.Row + Options.Rows - 1, Options.Col);
        for (i = 0; i < Options.Cols; i += 1) {
            System.out.print(" ");
        }

        for (i = 2; i < Options.Rows; i += 1) {
            GotoRC(Options.Row + i - 1, Options.Col);
            System.out.print(" ");
            GotoRC(Options.Row + i - 1, Options.Col + Options.Cols - 1);
            System.out.print(" ");
        }
        return;
    } // EmptyRect

    public static void FilledRect(CFOpts Options) {
        for (; Options.Rows > 0;) {
            EmptyRect(Options);
            Options.Row += 1;
            Options.Col += 1;
            Options.Rows -= 2;
            Options.Cols -= 2;
        }

        return;
    } // FilledRect

    public static void LoadLib(String relativePath) {
        String Arch = System.getProperty("os.arch");
        String LibName = "ConsoleFunJNI";

        if (Arch.equals("x86")) {
            LibName = LibName + "32";
        } else if (Arch.equals("amd64")) {
            LibName = LibName + "64";
        }

        File Lib = new File(relativePath + "/Bin/" + System.mapLibraryName(LibName));

        System.load(Lib.getAbsolutePath());
    }
}