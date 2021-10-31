
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

    public static CFOpts CloneOpts(CFOpts Options) {
        CFOpts Temp = new CFOpts();

        Temp.Row = Options.Row;
        Temp.Col = Options.Col;

        Temp.Rows = Options.Rows;
        Temp.Cols = Options.Cols;

        Temp.FG = Options.FG;
        Temp.BG = Options.BG;

        return Temp;
    }

    public native static CFOpts GetOpts();

    public native static char GetCh();

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
        CFOpts Temp = CloneOpts(Options);

        for (; Temp.Rows > 0;) {
            EmptyRect(Temp);
            Temp.Row += 1;
            Temp.Col += 1;
            Temp.Rows -= 2;
            Temp.Cols -= 2;
        }

        return;
    } // FilledRect

    public static char[] ReadBox(CFOpts Options) {
        int i, j, k = -1, EOL[], SFlag = 0;
        Boolean JFlag = false;
        char Ch, Str[];
        ConsoleFun.FilledRect(Options);

        EOL = new int[Options.Rows + 1];
        Str = new char[Options.Rows * Options.Cols + 1];

        for (i = 0; i < Options.Rows; i += 1) {
            ConsoleFun.GotoRC(Options.Row + i, Options.Col);

            for (j = 0; j < Options.Cols; j += 1) {
                if (JFlag) {
                    j = EOL[i];

                    ConsoleFun.GotoRC(Options.Row + i, Options.Col + j);

                    if (j + 1 == Options.Cols) {
                        System.out.print(" \b");
                    }

                    JFlag = false;
                }

                Ch = ConsoleFun.GetCh();

                if (Ch == 0x1B) {
                    SFlag = 1;
                    j -= 1;
                } else if (Ch == '\n' || Ch == '\r') {
                    k += 1;
                    Str[k] = '\n';
                    j += 1;
                    break;
                }
                /*
                 * else if (Ch == '\0') { // Case not possible? }
                 */
                else if (Ch == '\t') {
                    i = Options.Rows;
                    break;
                } else if (Ch == '\b' || Ch == 127) // \b or DEL
                {
                    if (j > 0) {
                        System.out.print("\b \b");
                        j -= 2;
                        k -= 1;
                    } else if (i > 0) {
                        JFlag = true;
                        i -= 2;
                        k -= 1;
                        break;
                    } else {
                        j -= 1;
                    }
                } else {
                    if (Ch > 31 && Ch < 127) {
                        if (SFlag > 0) {
                            if ((Ch >= 'a' && Ch <= 'z') || (Ch >= 'A' && Ch <= 'Z')) {
                                SFlag = 0;
                            }
                            j -= 1;
                        } else {
                            k += 1;
                            Str[k] = Ch;
                            System.out.print(Ch);
                        }
                    } else {
                        j -= 1;
                    }
                }
            }

            if (!JFlag) {
                EOL[i] = j - 1;
            }
        }

        k += 1;
        Str[k] = '\0';

        return Str;
    } // ReadBox

    public static void WriteBox(char Str[], CFOpts Options) {
        int i, j, k = 0;
        char Ch;
        ConsoleFun.FilledRect(Options);

        for (i = 0; i < Options.Rows; i += 1) {
            ConsoleFun.GotoRC(Options.Row + i, Options.Col);

            for (j = 0; j < Options.Cols; j += 1) {
                Ch = Str[k];

                if (Ch == '\n') {
                    k += 1;
                    break;
                } else if (Ch == '\r') {
                    i -= 1;
                    k += 1;
                    break;
                } else if (Ch == '\0') {
                    i = Options.Row;
                    break;
                } else if (Ch == '\t') {
                    System.out.print(" ");
                } else if (Ch == '\b') {
                    if (j > 0) {
                        System.out.print("\b \b");
                        j -= 1;
                    }
                } else {
                    System.out.print(Ch);
                }

                k += 1;
            }
        }
        return;
    } // WriteBox

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