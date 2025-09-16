#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(const vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int bit = 0; bit < 32; ++bit) {
            int count = 0;
            for (int num : nums) {
                if ((num >> bit) & 1) ++count;
            }
            res += count * (n - count);
        }
        return res;
    }
};
