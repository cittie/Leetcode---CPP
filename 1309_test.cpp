#include <gtest/gtest.h>

#include "1309_decrypt-string-from-alphabet-to-integer-mapping.hpp"

TEST(SolutionTest, freqAlphabets)
{
    Solution* s = new Solution();

    ASSERT_TRUE(s != NULL);

    EXPECT_EQ(s->freqAlphabets("10#11#12"), "jkab");
    EXPECT_EQ(s->freqAlphabets("1326#"), "acz");
    EXPECT_EQ(s->freqAlphabets("25#"), "y");
    EXPECT_EQ(s->freqAlphabets("12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"), "abcdefghijklmnopqrstuvwxyz");
}