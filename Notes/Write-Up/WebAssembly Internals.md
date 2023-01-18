
## Introduction

This write-up details everything I know about WebAssembly including specification, exploitation, and issues that arise while working with WebAssembly.

## Table of Contents
- #### [[Background]]
- #### [[Environments]]
- #### [[Compilation]]
- #### [[Debugging]]




## Preliminary Testing

Before moving on to the formal categorization of vulnerable binaries and methodical exploitation, I tried testing some binaries I prepared myself.

Below is an example of C code used to prepare a testing binary.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <emscripten.h>

int main(void)
{
    char hello[] = "Hello World\n";
    char *str = malloc(255);
    strcpy(str, "This is a test string");
    char buf[10];
    scanf("%s", buf); // Buffer Overflow
    printf("%s\n", buf);
    printf(hello);  // Format String
    printf("\n");
    printf("%s\n", str); // Buffer Overflow
    return 0;
}
```


