#pragma once

#include <string>
#include <filesystem>
#include <optional>
#include <fstream>
#include <htslib/vcf.h>
#include <iostream>

namespace fs = std::filesystem;

namespace cngs
{
    class VCF
    {
    public:
        fs::path filePath;
        int numVariants = 0;
        static std::optional<VCF> create(std::string filePath);
        bool readVcf();


    private:
        /**
         * htslib related items are hidden as private. 
         * For raw pointers from htslib let's wrap them in unique_ptr and specify
         * a custom deletor. See unique_ptr: https://en.cppreference.com/w/cpp/memory/unique_ptr
         * Note: (Function Pointer Signature) for htsFile cleanup method 
         *  * Example: int (*)(htsFile *) for hts_close: Takes raw htsFile ptr and cleans up
         */
        using htsDtor = int (*)(htsFile *);
        using bcfHdrDtor = void (*)(bcf_hdr_t *);
        using bcfRecordDtor = void (*)(bcf1_t *);

        std::unique_ptr<htsFile, htsDtor> hts_fp;
        std::unique_ptr<bcf_hdr_t, bcfHdrDtor> bcf_header;
        std::unique_ptr<bcf1_t, bcfRecordDtor> bcf_record;

        VCF(fs::path filePath) : filePath(std::move(filePath)),
                                 hts_fp(nullptr, hts_close),
                                 bcf_header(nullptr, bcf_hdr_destroy),
                                 bcf_record(nullptr, bcf_destroy){};
    };
} // namespace cngs