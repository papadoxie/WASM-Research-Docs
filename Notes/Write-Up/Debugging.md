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
