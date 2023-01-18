## WebAssembly

WebAssembly is a bytecode language (like Java or Python bytecode) with a low-level memory model without garbage collection. It can be thought of as an assembly language for the web just like x86-64 is an assembly language for native hardware.

Similar to native assembly, programs written in languages like C, C++, and Rust can be compiled into WebAssembly

When a WebAssembly binary is run, there are 4 main concepts to be aware of ([https://developer.mozilla.org/en-US/docs/WebAssembly/Concepts](https://developer.mozilla.org/en-US/docs/WebAssembly/Concepts))

- Module: Modules represent a WebAssembly binary that has been compiled by the runtime into machine code. Modules declare imports and exports
- Memory: A resizable array of bytes that contains the linear address space used by WebAssembly instructions. This contains the program stack and the heap.
- Table: A resizable typed array containing references to variables and functions. WebAssembly stores function pointers separately for safety reasons.
- Instance: A Module paired with a state including its Memory, Table, and the set of imported values.

### Memory 
[https://developer.mozilla.org/en-US/docs/WebAssembly/Using_the_JavaScript_API#memory](https://developer.mozilla.org/en-US/docs/WebAssembly/Using_the_JavaScript_API#memory)

Each WASM module has its own sandboxed memory space which can be created manually in JavaScript using the WebAssembly.Memory() object constructor


[[Introduction|Previous]]  
[[Environments|Next]]
