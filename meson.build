project('cpp-ngs-utils', 'cpp', 
    version: '0.1',
    default_options: ['cpp_std=c++17'])

################################################
# subprojects
################################################
htslib = subproject('htslib')
htslib_dep = htslib.get_variable('htslib_dep')

lyra = subproject('lyra')
lyra_dep = lyra.get_variable('lyra_dep')

range_v3 = subproject('range-v3')
range_v3_dep = range_v3.get_variable('range_dep')

################################################
# cpp-ngs-utils library
################################################
cngs_src = [
    'src/cpp-ngs-utils/vcf.h',
    'src/cpp-ngs-utils/vcf.cpp'
]
cngs_lib = library('cngs',
    sources: cngs_src, 
    dependencies: [htslib_dep, range_v3_dep])

################################################
# includes
################################################
incdir = include_directories('src')
incdir_extern = include_directories('extern')

################################################
# tools
################################################
vcf_tool_src = [
    'src/tools/vcf/main.cpp'
]
vcf_tool = executable('vcf',
    sources: vcf_tool_src,
    link_with: cngs_lib,
    dependencies: [lyra_dep, htslib_dep],
    include_directories: incdir)

################################################
# tests
################################################
test_utils_src = [
    'src/tests/utils.h',
    'extern/tests/unit_test_framework.h'
]
test_utils_lib = library('test_utils_lib', sources: test_utils_src)
vcf_test = executable('vcf_test', 'src/tests/test_vcf.cpp',
    link_with:[test_utils_lib, cngs_lib], include_directories: [incdir, incdir_extern], dependencies: htslib_dep)

test('vcf_test', vcf_test)


