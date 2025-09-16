#include <gtest/gtest.h>
#include "477_total-hamming-distance.hpp"

TEST(Solution477Test, BasicExamples) {
    Solution s;
    std::vector<int> nums1 = {4, 14, 2};
    EXPECT_EQ(s.totalHammingDistance(nums1), 6);

    std::vector<int> nums2 = {1, 2, 3};
    EXPECT_EQ(s.totalHammingDistance(nums2), 4);
}

TEST(Solution477Test, EdgeCases) {
    Solution s;
    std::vector<int> nums = {0, 0, 0};
    EXPECT_EQ(s.totalHammingDistance(nums), 0);

    std::vector<int> nums2 = {0, 1};
    EXPECT_EQ(s.totalHammingDistance(nums2), 1);
}
