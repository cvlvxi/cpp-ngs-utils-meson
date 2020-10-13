test_utils_src = [
    'utils.h',
    '../../extern/tests/unit_test_framework.h'
]
test_utils_lib = library('test_utils_lib', sources: test_utils_src)

test_programs = [
    ['test_vcf', ['test_vcf.cpp'], [htslib_dep]],
    ['test_region', ['test_region.cpp'], [range_v3_dep]],
    ['test_samplesheet', ['test_samplesheet.cpp'], [absl_strings_dep]]
]

foreach p : test_programs
    exe = executable(p[0],
                sources: p[1],
                link_with:[test_utils_lib, cngs_lib],
                include_directories: [incdir, incdir_extern],
                dependencies: p[2] + [fmt_dep])
    test(p[0], exe)
endforeach