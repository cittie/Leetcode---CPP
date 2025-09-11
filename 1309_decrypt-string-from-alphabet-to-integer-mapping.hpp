#include <string>
using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        string result;

        for (int i = 0; i < s.length(); ++i) {
            int num = s[i] - '0';
            if (i + 2 < s.length() && (s[i + 2] == '#')) {
                num = num * 10 + (s[i + 1] - '0');
                i += 2;
            }

            result.push_back('a' + num - 1);
        }

        return result;
    }
};