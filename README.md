# Configure build

## GCC-10

```
CC=gcc-10 CXX=g++-10 meson build/gcc 
```

## Clang

```
CC=clang CXX=clang++ meson build/clang
```

# Vscode
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

# Setup

```
./setup gcc 
./setup clang
```

- This will copy the compile_commands to the root directory (for clangd) 

