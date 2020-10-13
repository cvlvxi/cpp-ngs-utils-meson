cngs_src = [
    'vcf.h',
    'vcf.cpp',
    'region.h',
    'samplesheet.h',
    'samplesheet.cpp'
]
cngs_lib = library('cngs',
    sources: cngs_src,
    dependencies: [
        htslib_dep,
        range_v3_dep,
        fmt_dep,
        absl_strings_dep])