
#include <cpp-ngs-utils/vcf.h>
#include <filesystem>
#include <optional>
#include <tests/unit_test_framework.h>
#include <tests/utils.h>

using namespace cngs;
namespace fs = std::filesystem;

// Move the fs::path returned from getFixture good_vcf so it doesn't get
// destroyed
const fs::path goodVcf = Tests::getFixture("vcfs/allele_depth_test.vcf");

TEST(test_construction) {
    std::optional<VCF> v = VCF::create(goodVcf.c_str());
    ASSERT_TRUE(v.has_value())
}

TEST(test_construction_invalid_filepath) {
    std::optional<VCF> v = VCF::create("allele_depth_test");
    ASSERT_FALSE(v.has_value());
}

TEST(test_vcf_read_lines) {
    std::optional<VCF> v = VCF::create(goodVcf.c_str());
    // Optional use pointer syntax
    ASSERT_TRUE(v->readVcf());
    ASSERT_TRUE(v->numVariants == 3);
}

TEST_MAIN()