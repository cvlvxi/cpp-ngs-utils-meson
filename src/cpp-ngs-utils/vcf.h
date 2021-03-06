#pragma once

#include <filesystem>
#include <fstream>
#include <htslib/vcf.h>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

namespace fs = std::filesystem;

namespace cngs {
    class VCF {
    public:
        int numVariants = 0;
        std::vector<std::string> samples;

        static std::optional<VCF> create(std::string_view fp);
        bool readVcf();

    private:
        /**
   * htslib related items are hidden as private.
   * For raw pointers from htslib let's wrap them in unique_ptr and specify
   * a custom deletor.
   * See unique_ptr: https://en.cppreference.com/w/cpp/memory/unique_ptr
   * Note: Function Pointer Signature for htsFile cleanup method
   *  i.e. int (*)(htsFile *) for hts_close
   */
        using htsDtor = int (*)(htsFile *);
        using bcfHdrDtor = void (*)(bcf_hdr_t *);
        using bcfRecordDtor = void (*)(bcf1_t *);

        fs::path filePath;
        std::unique_ptr<htsFile, htsDtor> hts_fp;
        std::unique_ptr<bcf_hdr_t, bcfHdrDtor> bcf_header;
        std::unique_ptr<bcf1_t, bcfRecordDtor> bcf_record;

        VCF(fs::path filePath)
            : filePath(std::move(filePath)), hts_fp(nullptr, hts_close),
              bcf_header(nullptr, bcf_hdr_destroy),
              bcf_record(nullptr, bcf_destroy){};
    };
}// namespace cngs