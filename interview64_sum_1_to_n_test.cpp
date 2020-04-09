#include <gtest/gtest.h>

#include "interview64_sum_1_to_n.hpp"

TEST(SolutionTest, sumNums)
{
    Solution* s = new Solution();

    ASSERT_TRUE(s != NULL);

    EXPECT_EQ(s->sumNums(0), 0);
    EXPECT_EQ(s->sumNums(1), 1);
    EXPECT_EQ(s->sumNums(100), 5050);
}