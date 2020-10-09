project('cpp-ngs-utils', 'cpp')

lib =library('mylib', 'src/cngs/vcf.h')
incdir = include_directories('src')

executable('program', 'main.cpp', link_with: lib, include_directories: incdir)
