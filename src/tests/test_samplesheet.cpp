#include "fmt/core.h"
#include <cpp-ngs-utils/samplesheet.h>
#include <filesystem>
#include <tests/unit_test_framework.h>
#include <tests/utils.h>

const std::filesystem::path samplesheet = Tests::getFixture("samplesheets/SampleSheet.csv");


using namespace cngs;

TEST(load_samplesheet_blank) {
    ASSERT_TRUE(SampleSheet::create("DOESNT EXIST") == std::nullopt);
}

TEST(load_ss_not_blank) {
    fmt::print("Reading file: {}\n", samplesheet.c_str());
    auto s = SampleSheet::create(samplesheet.c_str());
    ASSERT_TRUE(s != std::nullopt);
}
TEST_MAIN()