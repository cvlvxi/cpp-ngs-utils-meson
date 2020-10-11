project('cpp-ngs-utils', 'cpp', 
    version: '0.1',
    default_options: ['cpp_std=c++17'])

# includes
incdir = include_directories('src')
incdir_extern = include_directories('extern')

# subprojects
subdir('extern')

# cpp-ngs-utils library
subdir('src/cpp-ngs-utils')

# tools
subdir('src/tools')

# tests
subdir('src/tests')

# benchmarks
subdir('src/benchmarks')