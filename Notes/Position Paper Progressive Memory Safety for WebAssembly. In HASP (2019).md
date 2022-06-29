# Position Paper: Progressive Memory Safety for WebAssembly (2019)

## MS-WASM Design Goals
- Strong safety guarantees. MS-Wasm seeks to provide abstractions that can be used to enforce memory safety, i.e., spatial and temporal safety, and pointer integrity. At the same time, these abstractions should also be sufficient to support weaker piecemeal mitigation and detection mechanisms.
- Backwards compatibility. MS-Wasm must be a minimally invasive extension to Wasm. This includes making MS-Wasm backwards compatible with existing Wasm toolchains, and making all of its features opt-in. Thus, existing Wasm binaries should remain valid, with the same semantics as before. Likewise, existing source-toWasm compilers should continue to be valid.
- Leveraging hardware. MS-Wasm backends should be able to leverage whatever memory-safety hardware features are available on a given hardware platform. Thus, the design of MS-Wasm should be general enough to accommodate different detection and enforcement mechanisms, and not be specific to any particular hardware mechanism, e.g., memory tagging or MPX.
- Progressive enforcement. Enforcing full memory safety is the ideal, but doing this without sufficient hardware support is prohibitive in many use cases—and requiring it would discourage users from building and deploying their applications with MS-Wasm. Instead, MS-Wasm should accommodate different design points that trade off security and performance, and leave it to backends to choose the best combination of software and hardware mechanisms to implement the desired guarantees

## Future Goals
- Trace-based definition of relaxed memory-safety
- Semantics and soundness of MS-WASM
- Prototype implementation of short-term solution (Compiler that targets WASM)