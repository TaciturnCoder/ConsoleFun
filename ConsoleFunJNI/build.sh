#!/bin/bash -x

# // Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
# //                                                                     //
# // Licensed under the Taciturn Coder License v0.0.1, the "License";    //
# // You may not use this file except in compliance with the License.    //
# // You may obtain a copy of the License at:                            //
# //         https://taciturncoder.github.io/License/v0-0-1              //
# //                                                                     //
# // See the License for the permissions and limitations.                //

FILE=ConsoleFunJNI

JDK="/mnt/z/Program Files/Java/jdk-16.0.2/include"
JDK_win32="/mnt/z/Program Files/Java/jdk-16.0.2/include/win32"
echo "Compile for Windows"
x86_64-w64-mingw32-gcc -fPIC -shared "-I$JDK" "-I$JDK_win32" -o "../$FILE.dll" "./$FILE.c"

JDK="/usr/lib/jvm/jdk-16.0.2/include"
JDK_linux="/usr/lib/jvm/jdk-16.0.2/include/linux"
echo "Compile for Linux"
gcc -fPIC -shared "-I$JDK" "-I$JDK_linux" -I"../" -o "../lib$FILE.so" "./$FILE.c"