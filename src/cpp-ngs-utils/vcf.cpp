#include "vcf.h"

namespace cngs {
std::optional<VCF> VCF::create(std::string filePath) {
  // Check that the filePath exists!
  fs::path fp = fs::path(std::move(filePath));
  if (!fs::exists(fp)) {
    return std::nullopt;
  }
  return VCF(std::move(fp));
}

bool VCF::readVcf() {
  const char *filename = filePath.c_str();
  hts_fp =
      std::unique_ptr<htsFile, htsDtor>(bcf_open(filename, "r"), hts_close);
  if (hts_fp == NULL) {
    fprintf(stderr, "error opening %s\n", filename);
    return false;
  }
  bcf_header = std::unique_ptr<bcf_hdr_t, bcfHdrDtor>(
      bcf_hdr_read(hts_fp.get()), bcf_hdr_destroy);
  bcf_record = std::unique_ptr<bcf1_t, bcfRecordDtor>(bcf_init(), bcf_destroy);

  // Check empty header
  if (bcf_header == nullptr) {
    throw std::runtime_error("Unable to read header");
  }
  // Read Every Record
  while (bcf_read(hts_fp.get(), bcf_header.get(), bcf_record.get()) == 0) {
    numVariants++;
  }

  return true;
}

} // namespace cngs
