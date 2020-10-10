project('cpp-ngs-utils', 'cpp', 
    version: '0.1',
    default_options: ['cpp_std=c++17'])

################################################
# subprojects
################################################
# Hts lib
htslib = subproject('htslib')
htslib_dep = htslib.get_variable('htslib_dep')

# Lyra
lyra = subproject('lyra')
lyra_dep = lyra.get_variable('lyra_dep')

# Range_v3
range_v3 = subproject('range-v3')
range_v3_dep = range_v3.get_variable('range_dep')

# Abseil
abseil = subproject('abseil')
absl_debugging_dep = abseil.get_variable('absl_debugging_dep')
absl_hash_dep = abseil.get_variable('absl_hash_dep')
absl_numeric_dep = abseil.get_variable('absl_numeric_dep')
absl_strings_dep = abseil.get_variable('absl_strings_dep')
absl_random_dep = abseil.get_variable('absl_random_dep')
absl_time_dep = abseil.get_variable('absl_time_dep')
absl_types_dep = abseil.get_variable('absl_types_dep')
absl_synchronization_dep = abseil.get_variable('absl_synchronization_dep')
absl_flags_dep = abseil.get_variable('absl_flags_dep')
absl_container_dep = abseil.get_variable('absl_container_dep')
absl_status_dep = abseil.get_variable('absl_status_dep')

# Google Benchmark
gbenchmark = subproject('google-benchmark')
gbenchmark_dep = gbenchmark.get_variable('google_benchmark_dep')
gbenchmark_main_dep = gbenchmark.get_variable('google_benchmark_main_dep')

################################################
# cpp-ngs-utils library
################################################
cngs_src = [
    'src/cpp-ngs-utils/vcf.h',
    'src/cpp-ngs-utils/vcf.cpp',
    'src/cpp-ngs-utils/region.h'
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

test_programs = [
    ['test_vcf', ['src/tests/test_vcf.cpp'], [htslib_dep]],
    ['test_region', ['src/tests/test_region.cpp'], [range_v3_dep]],
    ['test_ranges_v3', ['src/tests/subprojects/test_ranges_v3.cpp'], [range_v3_dep]],
    ['test_abseil', ['src/tests/subprojects/test_abseil.cpp'], [range_v3_dep]]
]

foreach p : test_programs
    exe = executable(p[0],
                sources: p[1],
                link_with:[test_utils_lib, cngs_lib],
                include_directories: [incdir, incdir_extern],
                dependencies: p[2])
    test(p[0], exe)
endforeach



################################################
# benchmarks
################################################
benchmark_programs = [
    ['benchmark_ranges_v3', ['src/benchmarks/subprojects/benchmark_ranges_v3.cpp'], [gbenchmark_dep, range_v3_dep]]
]

foreach p : benchmark_programs
    exe = executable(p[0],
                sources: p[1],
                link_with:[test_utils_lib, cngs_lib],
                include_directories: [incdir, incdir_extern],
                dependencies: p[2])
endforeach
