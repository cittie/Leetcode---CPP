#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm> // 用于 std::sort

#include "interview17_letter-combinations-of-a-phone-number.hpp"

TEST(SolutionTest, letterCombinations) {
    Solution* s = new Solution();
    ASSERT_TRUE(s != nullptr); // 确保对象创建成功

    // 1. 测试空输入
    std::string digits1 = "";
    std::vector<std::string> result1 = s->letterCombinations(digits1);
    EXPECT_TRUE(result1.empty()); // 期望结果为空向量

    // 2. 测试单个数字 '2'
    std::string digits2 = "2";
    std::vector<std::string> result2 = s->letterCombinations(digits2);
    std::vector<std::string> expected2 = {"a", "b", "c"};
    // 对结果和预期值排序以便比较（如果顺序不重要）
    std::sort(result2.begin(), result2.end());
    std::sort(expected2.begin(), expected2.end());
    EXPECT_EQ(result2, expected2);

    // 3. 测试两个数字 "23"
    std::string digits3 = "23";
    std::vector<std::string> result3 = s->letterCombinations(digits3);
    std::vector<std::string> expected3 = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    std::sort(result3.begin(), result3.end());
    std::sort(expected3.begin(), expected3.end());
    EXPECT_EQ(result3, expected3);

    // 4. 测试包含数字'7'或'9'（它们对应4个字母）
    std::string digits4 = "79";
    std::vector<std::string> result4 = s->letterCombinations(digits4);
    // '7' -> "pqrs", '9' -> "wxyz"
    // 组合数量应为 4 * 4 = 16
    EXPECT_EQ(result4.size(), 16);
    // 检查一些特定组合是否存在（可选，更全面的检查是比对所有预期值）
    EXPECT_NE(std::find(result4.begin(), result4.end(), "pw"), result4.end());
    EXPECT_NE(std::find(result4.begin(), result4.end(), "rz"), result4.end());

    // 5. 测试较长的输入 "234"
    std::string digits5 = "234";
    std::vector<std::string> result5 = s->letterCombinations(digits5);
    // '2'->3 letters, '3'->3, '4'->3, total 3 * 3 * 3=27 combinations
    EXPECT_EQ(result5.size(), 27);
    // 检查是否包含一些预期的组合
    EXPECT_NE(std::find(result5.begin(), result5.end(), "adg"), result5.end());
    EXPECT_NE(std::find(result5.begin(), result5.end(), "cfi"), result5.end());

    delete s; // 释放内存
}