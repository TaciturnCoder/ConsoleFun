
[//]: # ( Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   )
[//]: # (                                                                     )
[//]: # ( Licensed under the Taciturn Coder License v0.0.1, the "License";    )
[//]: # ( You may not use this file except in compliance with the License.    )
[//]: # ( You may obtain a copy of the License at:                            )
[//]: # (         https://taciturncoder.github.io/License/v0-0-1              )
[//]: # (                                                                     )
[//]: # ( See the License for the permissions and limitations.                )

# ConsoleFun
Console Manipulation Functions

For C under Windows (32-bit & 64-bit) and Linux (32-bit & 64-bit)

For Java (version 16 or higher) under JVM (64-bit only) using JNI (under Windows only)

## Source Code
Published at https://github.com/TaciturnCoder/ConsoleFun

# Installation Instructions
See folder `Tests/` for more information.

## Installation for C programs
Simply include header file `Headers/ConsoleFun.h` in your program.

For example,
```
#include "./ConsoleFun/Headers/ConsoleFun.h"
// Path is relative to where you install ConsoleFun
```

## Installation for java programs (using JNI)
Simply include package `ConsoleFunJNI` in your program.

For example,
```
import ConsoleFunJNI.ConsoleFun;
import ConsoleFunJNI.CFOpts;

// OR

import ConsoleFunJNI.*;
```

And then load library using,
```
ConsoleFun.LoadLib("./ConsoleFunJNI");
// Path is relative to where you install ConsoleFun
```

# Change Log
See [Changes.md](./Changes.md) for more information.

# License
Licensed under the Taciturn Coder License v0.0.1

See [License.md](./License.md) for more information.
