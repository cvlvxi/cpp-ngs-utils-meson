#include "cpp-ngs-utils/vcf.h"
#include <iostream>
#include <lyra/lyra.hpp>

using namespace cngs;

int main(int argc, const char **argv) {
  std::string vcfFile;
  bool get_help = false;

  lyra::cli cli;
  cli.add_argument(lyra::help(get_help))
      .add_argument(lyra::opt(vcfFile, "vcfFile")
                        .name("-v")
                        .name("--vcfFile")
                        .required()
                        .help("Path to VCF File"));

  // Parse the program arguments.
  auto result = cli.parse({argc, argv});

  if (get_help) {
    std::cout << cli;
    return 0;
  }

  // Check that the arguments where valid.
  if (!result) {
    std::cerr << "Error in command line: " << result.errorMessage()
              << std::endl;
    return 1;
  }

  std::cout << "Reading from VCF File: " << vcfFile << "\n";

  std::optional<VCF> v = VCF::create(vcfFile.c_str());
  v->readVcf();

  std::cout << "Num Variants: " << v->numVariants << "\n";

  return 0;
}