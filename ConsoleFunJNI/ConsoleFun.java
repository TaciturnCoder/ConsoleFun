
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
    public static CFOpts NullOpts = new CFOpts();

    public static CFOpts CloneOpts(CFOpts Options) {
        CFOpts Temp = new CFOpts();

        Temp.Row = Options.Row;
        Temp.Col = Options.Col;

        Temp.Rows = Options.Rows;
        Temp.Cols = Options.Cols;

        Temp.FG = Options.FG;
        Temp.BG = Options.BG;

        return Temp;
    } // CFOpts

    public static class Struct {
        public static class Cache {
            public static class Flag {
                public static int Init = 0b00000001;
                public static int GetCh = 0b00000010;
                public static int GetOpts = 0b00000100;
                public static int GotoRC = 0b00001000;
                public static int SetColor = 0b00010000;
            } // Flag

            public static int Status = 0b11111110;
        } // Cache

        public static class Color {
            public static int Black = 0;
            public static int Blue = 1;
            public static int Green = 2;
            public static int Cyan = 3;
            public static int Red = 4;
            public static int Magenta = 5;
            public static int Yellow = 6;
            public static int White = 7;
        } // Color

        public static class KeyMap {
            public static class Flag {
                public static int Esc = 0b00000001;
                public static int Alt = 0b00000010;
                public static int Ctrl = 0b00000100;
                public static int Arrow = 0b00001000;
            } // Flag

            public static int Status = 0b00000000;

            public static char ArrowUp = 'A';
            public static char ArrowDown = 'B';
            public static char ArrowRight = 'C';
            public static char ArrowLeft = 'D';

            public static char FirstPrintable = (char) 32;
            public static char LastPrintable = (char) 126;

            public static char ESC = (char) 27;
            public static char BS = (char) 8;

            public static char TAB = (char) 9;
            public static char NL = (char) 10;
            public static char CR = (char) 13;
            public static char DEL = (char) 127;
        } // KeyMap
    } // Struct

    public static class Native {
        public static native char GetCh();

        public static native CFOpts GetOpts();

        public static native void GotoRC(int Row, int Col);

        public static native void SetColor(int FG, int BG);
    } // Native

    public static class Utils {
        public static void EmptyRect(CFOpts Options) {
            int i;
            char Line[];
            int RequiredFlag = ConsoleFun.Struct.Cache.Flag.Init | ConsoleFun.Struct.Cache.Flag.GotoRC
                    | ConsoleFun.Struct.Cache.Flag.SetColor;

            if ((ConsoleFun.Struct.Cache.Status & RequiredFlag) == RequiredFlag) {
                Line = new char[Options.Cols + 1];
                for (i = 0; i < Options.Cols; i += 1) {
                    Line[i] = ' ';
                }
                Line[Options.Cols] = '\0';

                ConsoleFun.Native.SetColor(Options.FG, Options.BG);

                ConsoleFun.Native.GotoRC(Options.Row, Options.Col);
                System.out.print(String.valueOf(Line));
                ConsoleFun.Native.GotoRC(Options.Row + Options.Rows - 1, Options.Col);
                System.out.print(String.valueOf(Line));

                for (i = 2; i < Options.Rows; i += 1) {
                    ConsoleFun.Native.GotoRC(Options.Row + i - 1, Options.Col);
                    System.out.print(" ");
                    ConsoleFun.Native.GotoRC(Options.Row + i - 1, Options.Col + Options.Cols - 1);
                    System.out.print(" ");
                }
            }
            return;
        } // EmptyRect

        public static void FilledRect(CFOpts Options) {
            CFOpts Temp;

            int RequiredFlag = ConsoleFun.Struct.Cache.Flag.Init;

            if ((ConsoleFun.Struct.Cache.Status & RequiredFlag) == RequiredFlag) {
                Temp = ConsoleFun.CloneOpts(Options);

                for (; Temp.Rows > 0;) {
                    ConsoleFun.Utils.EmptyRect(Temp);
                    Temp.Row += 1;
                    Temp.Col += 1;
                    Temp.Rows -= 2;
                    Temp.Cols -= 2;
                }
            }
            return;
        } // FilledRect

        public static char[] InputBox(CFOpts Options) {
            int i, j, k = -1, EOL[];
            Boolean JFlag = false;
            char Ch, Str[] = { '\0' };

            int RequiredFlag = ConsoleFun.Struct.Cache.Flag.Init | ConsoleFun.Struct.Cache.Flag.GetCh
                    | ConsoleFun.Struct.Cache.Flag.GotoRC;

            if ((ConsoleFun.Struct.Cache.Status & RequiredFlag) == RequiredFlag) {
                ConsoleFun.Utils.FilledRect(Options);

                EOL = new int[Options.Rows + 1];
                Str = new char[Options.Rows * Options.Cols + 1];

                for (i = 0; i < Options.Rows; i += 1) {
                    ConsoleFun.Native.GotoRC(Options.Row + i, Options.Col);

                    for (j = 0; j < Options.Cols; j += 1) {
                        if (JFlag) {
                            j = EOL[i];

                            ConsoleFun.Native.GotoRC(Options.Row + i, Options.Col + j);

                            if (j + 1 == Options.Cols) {
                                System.out.print(" \b");
                            }

                            JFlag = false;
                        }

                        ConsoleFun.Struct.KeyMap.Status = 0;
                        Ch = ConsoleFun.Native.GetCh();

                        if ((ConsoleFun.Struct.KeyMap.Status
                                & ConsoleFun.Struct.KeyMap.Flag.Esc) == ConsoleFun.Struct.KeyMap.Flag.Esc) {
                            j -= 1;
                        } else if (Ch == ConsoleFun.Struct.KeyMap.NL || Ch == ConsoleFun.Struct.KeyMap.CR) {
                            k += 1;
                            Str[k] = '\n';
                            j += 1;
                            break;
                        }
                        /*
                         * else if (Ch == '\0') { // Case not possible? }
                         */
                        else if (Ch == ConsoleFun.Struct.KeyMap.TAB) {
                            i = Options.Rows;
                            break;
                        } else if (Ch == ConsoleFun.Struct.KeyMap.BS || Ch == ConsoleFun.Struct.KeyMap.DEL) // \b or DEL
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
                            if (Ch >= ConsoleFun.Struct.KeyMap.FirstPrintable
                                    && Ch <= ConsoleFun.Struct.KeyMap.LastPrintable) {
                                k += 1;
                                Str[k] = Ch;
                                System.out.print(Ch);
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
            }

            return Str;
        } // InputBox

        public static void PrintBox(char Str[], CFOpts Options) {
            int i, j, k = 0;
            char Ch;

            int RequiredFlag = ConsoleFun.Struct.Cache.Flag.Init | ConsoleFun.Struct.Cache.Flag.GetCh
                    | ConsoleFun.Struct.Cache.Flag.GotoRC;

            if ((ConsoleFun.Struct.Cache.Status & RequiredFlag) == RequiredFlag) {
                ConsoleFun.Utils.FilledRect(Options);

                for (i = 0; i < Options.Rows; i += 1) {
                    ConsoleFun.Native.GotoRC(Options.Row + i, Options.Col);

                    for (j = 0; j < Options.Cols; j += 1) {
                        Ch = Str[k];

                        if (Ch == ConsoleFun.Struct.KeyMap.NL) {
                            k += 1;
                            break;
                        } else if (Ch == ConsoleFun.Struct.KeyMap.CR) {
                            i -= 1;
                            k += 1;
                            break;
                        } else if (Ch == '\0') {
                            i = Options.Row;
                            break;
                        } else if (Ch == ConsoleFun.Struct.KeyMap.TAB) {
                            System.out.print(" ");
                        } else if (Ch == ConsoleFun.Struct.KeyMap.BS || Ch == ConsoleFun.Struct.KeyMap.DEL) {
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
            }

            return;
        } // PrintBox
    } // Utils

    public static void Init(String relativePath) {
        ConsoleFun.NullOpts.BG = ConsoleFun.Struct.Color.Blue;
        ConsoleFun.NullOpts.FG = ConsoleFun.Struct.Color.Black;

        if ((ConsoleFun.Struct.Cache.Status & ConsoleFun.Struct.Cache.Flag.Init) != ConsoleFun.Struct.Cache.Flag.Init) {

            String Arch = System.getProperty("os.arch");
            String LibName = "ConsoleFunJNI";

            if (Arch.equals("x86")) {
                LibName = LibName + "32";
            } else if (Arch.equals("amd64")) {
                LibName = LibName + "64";
            }

            File Lib = new File(relativePath + "/Bin/" + System.mapLibraryName(LibName));

            System.load(Lib.getAbsolutePath());
            ConsoleFun.Struct.Cache.Status = ConsoleFun.Struct.Cache.Status | ConsoleFun.Struct.Cache.Flag.Init;
        }
        return;
    } // Init
}