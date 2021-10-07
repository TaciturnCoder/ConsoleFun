#!/bin/bash -x


# // Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   //
# //                                                                     //
# // Licensed under the Taciturn Coder License v0.0.1, the "License";    //
# // You may not use this file except in compliance with the License.    //
# // You may obtain a copy of the License at:                            //
# //         https://taciturncoder.github.io/License/v0-0-1              //
# //                                                                     //
# // See the License for the permissions and limitations.                //


FILE=ConsoleFun

echo "Compile for Windows"
x86_64-w64-mingw32-gcc -I"../" -o "./$FILE""_test.exe" "./$FILE""_test.c"

echo "Compile for Linux"
gcc -I"../" -o "./$FILE""_test.out" "./$FILE""_test.c"