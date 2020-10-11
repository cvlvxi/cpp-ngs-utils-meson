tool_programs  = [
    ['vcf', ['vcf.cpp'], [htslib_dep, lyra_dep]],
]

foreach p : tool_programs
    exe = executable(p[0],
                sources: p[1],
                link_with:[cngs_lib],
                include_directories: [incdir],
                dependencies: p[2])
endforeach
