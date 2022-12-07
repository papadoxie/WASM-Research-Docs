## Module

Compiled WebAssembly binaries, known as modules, can be found on disk as
`WebAssembly (wasm) binary module version 0x1 (MVP)`

Filetype information can be found inside the binary itself
![[Pasted image 20221207181356.png]]
WebAssembly binaries start with 4 magic bytes \\x00asm followed by a 32-bit little-endian version number (https://www.pnfsoftware.com/reversing-wasm.pdf)

## Sections

![[Pasted image 20221207182237.png]]


## Browser vs WASI Modules

Compiling a program for a Browser or Native OS with Emscripten both generate a .wasm Module but there are some differences in the Module. 

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