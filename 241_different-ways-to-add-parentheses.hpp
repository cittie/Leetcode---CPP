#pragma once
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(const string& input) {
        vector<int> res;
        for (int i = 0; i < input.size(); ++i) {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') res.push_back(l + r);
                        else if (c == '-') res.push_back(l - r);
                        else if (c == '*') res.push_back(l * r);
                    }
                }
            }
        }
        if (res.empty()) {
            res.push_back(stoi(input));
        }
        return res;
    }
};
