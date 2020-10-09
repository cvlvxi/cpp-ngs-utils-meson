project('cpp-ngs-utils', 'cpp', default_options: ['cpp_std=c++17'])

lib = library('mylib', 'src/cngs/vcf.h')
incdir = include_directories('src')


executable('program', 'main.cpp', link_with: lib, include_directories: incdir)
