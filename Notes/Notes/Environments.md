## WebAssembly System Interface (WASI)
https://github.com/bytecodealliance/wasmtime/blob/main/docs/WASI-overview.md

A standard runtime for WebAssembly. Supports running WebAssembly binaries on web browsers as well as other environments such as Node.js, Wasmer and Wasmtime

### Features
- Sandboxed sysroot
- WASI libc
	- MUSL libc 
	- libpreopen
	- syscall wrappers (Abstraction Layer over both native OS and JS runtimes)
- WASI API

### Support

WASI supports running WebAssembly on
- Native OS
- Bare Metal
- Web Polyfill
- Inside Host Applications


[[Background|Previous]]  
[[Compilation|Next]]