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

JDK_win_home="/mnt/z/Program Files/Java/jdk-16.0.2/include"
JDK_win32="/mnt/z/Program Files/Java/jdk-16.0.2/include/win32"
echo "Compile for Windows"
i686-w64-mingw32-gcc -fPIC -m32 -shared "-I$JDK_win_home" "-I$JDK_win32" -o "./Bin/$FILE""32.dll" "./$FILE.c"
x86_64-w64-mingw32-gcc -fPIC -m64 -shared "-I$JDK_win_home" "-I$JDK_win32" -o "./Bin/$FILE""64.dll" "./$FILE.c"

JDK_linux_home="/usr/lib/jvm/jdk-16.0.2/include"
JDK_linux="/usr/lib/jvm/jdk-16.0.2/include/linux"
echo "Compile for Linux"
gcc -fPIC -m32 -shared "-I$JDK_linux_home" "-I$JDK_linux" -o "./Bin/lib$FILE""32.so" "./$FILE.c"
gcc -fPIC -shared "-I$JDK_linux_home" "-I$JDK_linux" -o "./Bin/lib$FILE""64.so" "./$FILE.c"
