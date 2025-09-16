#include <gtest/gtest.h>
#include "351_android-unlock-patterns.hpp"

TEST(Solution351Test, BasicExamples) {
    Solution s;
    EXPECT_EQ(s.numberOfPatterns(1, 1), 9);
    EXPECT_EQ(s.numberOfPatterns(2, 2), 56);
}

TEST(Solution351Test, RangeExamples) {
    Solution s;
    EXPECT_EQ(s.numberOfPatterns(1, 2), 65);
    EXPECT_EQ(s.numberOfPatterns(2, 3), 376);
}
