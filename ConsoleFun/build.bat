
REM // Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
REM //                                                                     //
REM // Licensed under the Taciturn Coder License v0.0.1, the "License";    //
REM // You may not use this file except in compliance with the License.    //
REM // You may obtain a copy of the License at:                            //
REM //         https://taciturncoder.github.io/License/v0-0-1              //
REM //                                                                     //
REM // See the License for the permissions and limitations.                //

echo "Generating JNI header file"

javac cfopts.java
javac -cp "../" ConsoleFun.java

javac -cp "../" -h "./" ConsoleFun.java
