
## Introduction

This write-up details the methodology, steps taken, findings, and discoveries made during the course of the WebAssembly binary security research project.


## WebAssembly

WebAssembly is a bytecode language (like Java or Python bytecode) with a low-level memory model without garbage collection. It can be thought of as an assembly language for the web just like x86-64 is an assembly language for native hardware.

Similar to native assembly, programs written in languages like C, C++, and Rust can be compiled into WebAssembly

When a WebAssembly binary is loaded on a web browser, there are 4 main concepts to be aware of ([https://developer.mozilla.org/en-US/docs/WebAssembly/Concepts](https://developer.mozilla.org/en-US/docs/WebAssembly/Concepts))

- Module: Modules represent a WebAssembly binary that has been compiled by the browser into machine code. Modules declare imports and exports
- Memory: A resizable array of bytes that contains the linear address space used by WebAssembly instructions. This contains the program stack and the heap.
- Table: A resizable typed array containing references to variables and functions. WebAssembly stores function pointers separately for safety reasons.
- Instance: A Module paired with a state including its Memory, Table, and the set of imported values.

### Memory 
[https://developer.mozilla.org/en-US/docs/WebAssembly/Using_the_JavaScript_API#memory](https://developer.mozilla.org/en-US/docs/WebAssembly/Using_the_JavaScript_API#memory)

Each WASM module has its own sandboxed memory space which can be created manually in JavaScript using the WebAssembly.Memory() object constructor


## Emscripten ([https://emscripten.org/](https://emscripten.org/))

Emscripten is a compiler toolchain that compiles C and C++ code to WebAssembly. It uses Clang and LLVM to generate WebAssembly bytecode and JavaScript “glue code”.

The JavaScript code is used to implement C standard library functions for the WebAssembly environment (browser, Wasmer, etc.)

  
## Building and Running
[https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm](https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm)

To run the code we need a test server. The simplest way is to use a python server
`python3 -m http.server 8080`


## Important directives and definitions 

Emscripten optimizes away all functions other than main() as dead code.

The `EMSCRIPTEN_KEEPALIVE` definition is used to tell the compiler not to optimize away custom functions. This is important for testing vulnerabilities such as control flow.
 
`ccall() `is used to call custom C and C++ functions outside of the main program loop. These functions can be called from HTML forms and JavaScript code. To use ccall() we have to provide the following compilation flag.

`-s "EXPORTED_RUNTIME_METHODS=['ccall']"`

This is important for testing vulnerabilities such as control flow.



## Testing Setup

#### Manjaro (Arch Linux) Virtual Machine:
- **RAM:** 2 GiB
- **Processors:** 2
- **Storage:** 50 GiB

Emscripten toolchain set up: [https://emscripten.org/docs/getting_started/downloads.html](https://emscripten.org/docs/getting_started/downloads.html)

```bash
git clone [https://github.com/emscripten-core/emsdk.git](https://github.com/emscripten-core/emsdk.git)

cd emsdk

./emsdk install latest

./emsdk activate latest

echo "source $(PWD)/emsdk_env.sh" > ~/.bashrc
```
  

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


## WebAssembly Package Manager (WAPM)

WAPM is a package manager that makes it easier to manage the Wasmer Runtime

## WebAssembly Systems Interface (WASI)


## Compiling for a Browser

We can compile this code for a browser using Emscripten. We will also enable debug symbols and provide the path where they will be placed. The debug path should be the root of our python server.
```bash
emcc hello.c -o bin/hello.html -g -fdebug-compilation-dir='..'
```

Host it on a python server
```bash
python3 -m http.server 8008 > /dev/null 2> /dev/null&
```


Now we can run it like a normal webpage on Chrome.

Using Chrome DevTools we can view the WAT representation and the C source. We can also set breakpoints and watch variables. Most importantly we can view the whole linear address space allocated for our WASM binary.

![](https://lh6.googleusercontent.com/OjR6fqSb8OcPSHElGWCyxZQgmj-gx8CqkHFYZZ322Jse2qqq2RaGBE5mhpADR8rRR0Q0UdCRgOr8V2OBljiHCtFXe_5yip6rDspq3R0VTeIi9hiG6wx4ykRZOozjazeFBzr0NxPpjwmNDr7xWkc1oku-iNO0iS2LaMMT22uld3CS6N40-MMdiQ0vnoNzhg)

![](https://lh4.googleusercontent.com/qb37_yUSw6fGZdj9zzZ0DRnCNdUKjl88X0Wn7oFSszfl-vzSTXUmqevOxdOwad0V__AK1Ezz3nWjbcXvgXnEL01Jf_jGw73Jm6QEIpTGcEcuIZjlCUP0C0sfI3E7URP0uupOX699x4jNzSF_dl_mc1yI9mbH5M-IViATQinGb1HIv5MspuaqVLJXu7z4Ww)

  

## Compiling a Standalone Module

We have used both Clang and Emscripten during testing

### Emscripten

```bash
emcc hello.c -o bin/hello.wasm -g
```

```Makefile
CFLAGS = -g -I$(shell wasmer config --includedir)
LDFLAGS = -Wl,-rpath,$(shell wasmer config --libdir)
LDLIBS = $(shell wasmer config --libs)

all: load load.o wasm_module
load: load.o

.PHONY: clean
.SILENT: clean
clean:
	rm -vf load.o load bin/imgRead.*

wasm_module: bin/imgRead.wasm
bin/imgRead.wasm: imgRead.c
	emcc imgRead.c -o bin/imgRead.wasm -g
```

### Clang

## Binaries

### Browser vs WASI Modules

Compiling a program for a Browser or WASI both generate a .wasm Module but there are some differences in the Module. 
![[Pasted image 20221124050929.png]]
Diffing indicates this difference but doesnt generate a comparison
Bindiff also does not work because the assembly is non-native

Diffing the WAT representation of the Modules shows us the difference
The most apparent difference is in the imports
![[Pasted image 20221124051404.png]]

But a more interesting difference is in the offsets
![[Pasted image 20221124051624.png]]
This means it might not be possible to use the same exploit between Modules of the same program

Diffing 2 Modules compiled from the same source and targeting the same platform yields no differences
![[Pasted image 20221124052004.png]]
This rules out the possibility of the differences being results of unexpected compiler behaviour