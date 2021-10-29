
[//]: # ( Copyright 2021 Dwij Bavisi <dwijbavisi@gmail.com>                   )
[//]: # (                                                                     )
[//]: # ( Licensed under the Taciturn Coder License v0.0.1, the "License";    )
[//]: # ( You may not use this file except in compliance with the License.    )
[//]: # ( You may obtain a copy of the License at:                            )
[//]: # (         https://taciturncoder.github.io/License/v0-0-1              )
[//]: # (                                                                     )
[//]: # ( See the License for the permissions and limitations.                )

# ConsoleFun
Cross-platform Console Manipulation Functions,

Currently only for C and Java (using JNI) under Windows (32Bit and 64Bit) and Linux (64Bit only).

# Installation Instructions

## Installation for C programs
Simply include header file `./ConsoleFun/Headers/ConsoleFun.h` in your program.

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
ConsoleFun.LoadLib("./ConsoleFun/ConsoleFunJNI");
// Path is relative to where you install ConsoleFun
```

# Change Log
See [Changes.md](./Changes.md) for more information.

# License
Licensed under the Taciturn Coder License v0.0.1

See [License.md](./License.md) for more information.
