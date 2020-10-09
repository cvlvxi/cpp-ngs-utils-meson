project('cpp-ngs-utils', 'cpp', 
    version: '0.1',
    default_options: ['cpp_std=c++17'])

htslib = subproject('htslib')
lyra = subproject('lyra')

htslib_dep = htslib.get_variable('htslib_dep')
lyra_dep = lyra.get_variable('lyra_dep')

cngs_src = [
    'src/cpp-ngs-utils/vcf.h'
]

cngs_lib = library('cngs', 
    sources: cngs_src, 
    dependencies: htslib_dep)

incdir = include_directories('src')

vcf_tool_src = [
    'src/tools/vcf/main.cpp'
]

vcf_tool = executable('vcf', 
    sources: vcf_tool_src,
    dependencies: [lyra_dep, htslib_dep], 
    include_directories: incdir)




