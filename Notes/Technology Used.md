# Technology Used

## Compilers
- Emscripten (C / C++)

## Allocators
### Default
- dlmalloc (Emscripten etc.) (usage 16.9% Hilbig et al.)
- Go malloc (Golang) (usage 1.6% Hilbig et al.)
- AssemblyScript alloc (AssemblyScript) (usage 1.3% Hilbig et al.)

### Non-Default (38.6% Usage)
- eosio malloc (Emscripten etc.) (usage 32.7% Hilbig et al.)
- eosio simple_malloc (Emscripten etc.) (usage 4.3% Hilbig et al.)
- wee_alloc (Rust) (usage 0.7% Hilbig et al.)
- emmalloc (Emscripten)
- Boehm GC (Garbage Collector) (usage 0.7% Hilbig et al.)
- gperftools (Google)