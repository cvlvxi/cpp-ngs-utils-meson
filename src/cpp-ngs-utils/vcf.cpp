#include "vcf.h"
#include <range/v3/algorithm/count.hpp> // specific includes
#include <vector>

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

  /* TESTING RANGE_V3 DELETE ME*/
  std::vector<int> v{6, 2, 3, 4, 5, 6};
  // note the count return is a numeric type
  // like int or long -- auto below make sure
  // it matches the implementation
  auto c = ranges::count(v, 6);
  std::cout << "vector:   " << c << '\n';

  std::array<int, 6> a{6, 2, 3, 4, 5, 6};
  c = ranges::count(a, 6);
  std::cout << "array:    " << c << '\n';
  /* DELETE ME */

  return true;
}

} // namespace cngs
