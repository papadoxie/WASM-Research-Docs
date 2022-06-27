# Security Terminology

## Memory Safety
- Spatial Safety: Prevents out-of-bounds reads and writes
- Temporal Safety: Prevents exploitation of use-after-free.
- Pointer Integrity: Prevents pointers from being manufactured from non-pointer values (e.g., casting an integer to a pointer), and also makes it impossible to corrupt a pointer in memory to create a different valid pointer