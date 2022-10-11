# Security Chasms of WASM (2018)

## Contributions
- A basic introduction to WebAssembly and the security risks that a developer may take on by using it
- Assessment of Emscriptens implementation of compiler-and-linker-level exploit mitigations as well as the internal hardening of its libc implementation, and how its augmentation of WASM introduces new attack vectors and methods of exploitation
- Examples of memory corruption exploits in the Wasm environment
- A basic outline of best practices and security considerations for developers wishing to integrate WebAssembly into their product

### Keywords 
- WebAssembly
- Security
- Emscripten
- Compiler
- Linker
- Mitigations
- Memory Corruption

### Further Research
- Emscriptens Heap Implementation (dlmalloc variation)
- Timing and side channel attacks
- Threads, race conditions, etc.