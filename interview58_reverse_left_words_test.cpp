#include <gtest/gtest.h>

#include "interview58_reverse_left_words.hpp"

TEST(SolutionTest, reverseLeftWords)
{
    Solution* s = new Solution();

    ASSERT_TRUE(s != NULL);

    EXPECT_EQ(s->reverseLeftWords("abcdefg", 2), "cdefgab");
    EXPECT_EQ(s->reverseLeftWords("lrloseumgh", 6), "umghlrlose");
    EXPECT_EQ(s->reverseLeftWords("100",3), "100");
}