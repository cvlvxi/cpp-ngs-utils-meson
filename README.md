# C++ NGS Utils Playground
- `Just a playground do not use this`
- For C++17 (hopefully C++20 at some point) Next Generation Sequencing Utilities
- Build with `Meson Build` + `Ninja`

Installing:

```
pip install meson
pip install ninja
```

## Meson Configure build

### GCC-10

```
CC=gcc-10 CXX=g++-10 meson build/gcc 
```

### Clang

```
CC=clang CXX=clang++ meson build/clang
```

### Git 

To use a different git binary instead of the default setup `export PATH=/path/to/new/git:$PATH`

# Setup

- Simple wrapper for running meson build / test / benchmark

```
./setup gcc 
./setup clang
./setup gcc test
./setup clang test
./setup gcc benchmark
./setup clang benchmark
```

- This will copy the compile_commands to the root directory (for clangd) 
- Adding test/benchmark will run the tests/benchmarks respectfully



## Vscode
- Install clangd extension
- `.vscode/settings.json`
- Recommend not having the C/C++ extension installed
- Otherwise disable it

```
    "C_Cpp.autocomplete": "Disabled",
    "C_Cpp.formatting": "Disabled",
    "C_Cpp.errorSquiggles": "Disabled",
    "C_Cpp.intelliSenseEngine": "Disabled",
    //"clangd.path": "/path/to/clangd",
    "clangd.arguments": ["-log=verbose", "-pretty", "--background-index"]
```

- Note: `I've had a lot of issues with getting this working. Use Clion preferrably`

## Clion

- Ensure that setup is run before opening project 
- This will look for the compile_commands.json symlink the root folder 