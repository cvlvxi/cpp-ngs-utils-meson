benchmark_programs = [
    ['benchmark_ranges_v3', ['subprojects/benchmark_ranges_v3.cpp'], [gbenchmark_dep, range_v3_dep]]
]

foreach p : benchmark_programs
    exe = executable(p[0],
                sources: p[1],
                link_with:[test_utils_lib, cngs_lib],
                include_directories: [incdir, incdir_extern],
                dependencies: p[2])
endforeach
