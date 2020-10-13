#include <cpp-ngs-utils/samplesheet.h>
#include <filesystem>
#include <tests/unit_test_framework.h>
#include <tests/utils.h>

const std::filesystem::path samplesheet = Tests::getFixture("samplesheets/SampleSheet.csv");

using namespace cngs;

TEST(load_samplesheet) {
    SampleSheet::create(samplesheet.c_str());
    ASSERT_TRUE(true);
}

TEST_MAIN()