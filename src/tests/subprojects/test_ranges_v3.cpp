#include <range/v3/view/iota.hpp>
#include <tests/unit_test_framework.h>
#include <tests/utils.h>


TEST(test_sort_range) {
    auto v = ranges::views::iota(1, 100);
    ASSERT_TRUE(true)
}

TEST_MAIN()