# Everything Old is New Again: Binary Security of WebAssembly (2020)

## Contributions
- An in-depth security analysis of WebAssembly’s linear memory and its use by programs compiled from languages such as C, C++, and Rust, which common memory protections are missing from WebAssembly, and how this can make some code less secure than when compiled to a native binary (Section 3).
- A set of attack primitives, derived from our analysis and generalized from previous work, along with a discussion of mitigations that the WebAssembly ecosystem does, or does not, provide (Section 4).
- A set of example vulnerable applications and end-to-end exploits, which show the consequences of our attacks on three different WebAssembly platforms (Section 5).
- Empirical evidence that both data and control-flow attacks are likely to be feasible, measured on WebAssembly binaries from real-world web applications and compiled from large C and C++ programs (Section 6).
- A discussion of possible mitigations to harden WebAssembly binaries against the described attacks (Section 7). We make our attack primitives, end-to-end exploits, and analysis tool publicly available to aid in this process.