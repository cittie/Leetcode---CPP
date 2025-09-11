#include <gtest/gtest.h>

#include "75_sort-colors.hpp"

TEST(SolutionTest, sortColors)
{
    Solution* s = new Solution();

    ASSERT_TRUE(s != NULL);

    // Test case 1: [2,0,2,1,1,0] -> [0,0,1,1,2,2]
    vector<int> nums1 = {2,0,2,1,1,0};
    s->sortColors(nums1);
    vector<int> expected1 = {0,0,1,1,2,2};
    EXPECT_EQ(nums1, expected1);

    // Test case 2: [2,0,1] -> [0,1,2]
    vector<int> nums2 = {2,0,1};
    s->sortColors(nums2);
    vector<int> expected2 = {0,1,2};
    EXPECT_EQ(nums2, expected2);

    // Test case 3: [0] -> [0]
    vector<int> nums3 = {0};
    s->sortColors(nums3);
    vector<int> expected3 = {0};
    EXPECT_EQ(nums3, expected3);

    // Test case 4: [1] -> [1]
    vector<int> nums4 = {1};
    s->sortColors(nums4);
    vector<int> expected4 = {1};
    EXPECT_EQ(nums4, expected4);

    // Test case 5: [2] -> [2]
    vector<int> nums5 = {2};
    s->sortColors(nums5);
    vector<int> expected5 = {2};
    EXPECT_EQ(nums5, expected5);

    // Test case 6: [1,2,0] -> [0,1,2]
    vector<int> nums6 = {1,2,0};
    s->sortColors(nums6);
    vector<int> expected6 = {0,1,2};
    EXPECT_EQ(nums6, expected6);

    delete s;
}
