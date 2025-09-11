#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    // 数字到字母的映射表（索引0~9对应数字0~9）
    const string letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7（4个字母）
        "tuv", // 8
        "wxyz" // 9（4个字母）
    };

    vector<string> result; // 存储所有组合结果
    string current;        // 当前构建的组合字符串

    // 回溯函数
    void backtrack(const string& digits, int index) {
        // 终止条件：已处理完所有数字
        if (index == digits.size()) {
            result.push_back(current); // 保存当前组合
            return;
        }
        
        char digit = digits[index];      // 当前处理的数字字符
        int num = digit - '0';           // 转为数字索引
        string letters = letterMap[num]; // 获取对应的字母串
        
        // 遍历当前数字的所有可能字母
        for (int i = 0; i < letters.size(); ++i) {
            current.push_back(letters[i]);   // 选择当前字母
            backtrack(digits, index + 1);     // 递归处理下一个数字
            current.pop_back();               // 回溯：撤销选择
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        result.clear(); 
        current.clear();
        if (digits.empty()) return result; // 处理空输入
        
        backtrack(digits, 0); // 从第0位数字开始回溯
        return result;
    }
};