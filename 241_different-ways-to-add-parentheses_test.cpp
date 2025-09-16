#include <gtest/gtest.h>
#include "241_different-ways-to-add-parentheses.hpp"

TEST(Solution241Test, BasicExamples) {
    Solution s;
    std::vector<int> result1 = s.diffWaysToCompute("2-1-1");
    std::vector<int> expected1 = {0, 2};
    std::sort(result1.begin(), result1.end());
    std::sort(expected1.begin(), expected1.end());
    EXPECT_EQ(result1, expected1);

    std::vector<int> result2 = s.diffWaysToCompute("2*3-4*5");
    std::vector<int> expected2 = {-34, -14, -10, -10, 10};
    std::sort(result2.begin(), result2.end());
    std::sort(expected2.begin(), expected2.end());
    EXPECT_EQ(result2, expected2);
}

TEST(Solution241Test, SingleNumber) {
    Solution s;
    std::vector<int> result = s.diffWaysToCompute("123");
    std::vector<int> expected = {123};
    EXPECT_EQ(result, expected);
}
