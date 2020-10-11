vcf_tool_src = [
    'vcf/main.cpp'
]
vcf_tool = executable('vcf',
    sources: vcf_tool_src,
    link_with: cngs_lib,
    dependencies: [lyra_dep, htslib_dep],
    include_directories: incdir)