
#include <cpp-ngs-utils/region.h>
#include <tests/unit_test_framework.h>
#include <tests/utils.h>

using namespace cngs;
namespace fs = std::filesystem;

TEST(test_region) {
    Region::test();
    ASSERT_TRUE(true)
}

TEST_MAIN()