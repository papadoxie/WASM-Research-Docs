There are multiple projects working on compilation of WebAssembly. Some of the notable ones include:
- WASIC
- Emscripten
- Clang
- 
## WASIC
https://docs.wasmer.io/ecosystem/wasienv/compile-c-c++-to-wasm-wasi

Simple C Compiler for the WebAssembly System Interface (WASI).

Supports:
- GNU/Make (wasimake)
- ./configure files (wasiconfigure)
- CMake (wasicmake)
- C++ Compilation (wasic++)

## Emscripten ([https://emscripten.org/](https://emscripten.org/))

Emscripten is a compiler toolchain that compiles C and C++ code to WebAssembly. It uses Clang and LLVM to generate WebAssembly bytecode and JavaScript “glue code”.

The JavaScript code is used to implement C standard library functions for the WebAssembly environment (browser, Wasmer, etc.)

#### Emscripten toolchain set up: 
[https://emscripten.org/docs/getting_started/downloads.html](https://emscripten.org/docs/getting_started/downloads.html)

```bash
git clone [https://github.com/emscripten-core/emsdk.git](https://github.com/emscripten-core/emsdk.git)

cd emsdk

./emsdk install latest

./emsdk activate latest

echo "source $(PWD)/emsdk_env.sh" > ~/.bashrc
```

### Building and Running
[https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm](https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm)

To run the code we need a test server. The simplest way is to use a python server
`python3 -m http.server 8080`

### Important directives and definitions 

Emscripten optimizes away all functions other than main() as dead code.

The `EMSCRIPTEN_KEEPALIVE` definition is used to tell the compiler not to optimize away custom functions. This is important for testing vulnerabilities such as control flow.
 
`ccall() `is used to call custom C and C++ functions outside of the main program loop. These functions can be called from HTML forms and JavaScript code. To use ccall() we have to provide the following compilation flag.

`-s "EXPORTED_RUNTIME_METHODS=['ccall']"`

This is also important for testing vulnerabilities such as control flow.