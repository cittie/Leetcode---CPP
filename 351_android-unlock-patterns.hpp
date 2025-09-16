#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<bool>> visited(3, vector<bool>(3, false));
        int res = 0;
        for (int len = m; len <= n; ++len) {
            res += dfs(visited, 0, 0, len - 1);
            res += dfs(visited, 0, 2, len - 1);
            res += dfs(visited, 2, 0, len - 1);
            res += dfs(visited, 2, 2, len - 1);
            res += dfs(visited, 0, 1, len - 1);
            res += dfs(visited, 1, 0, len - 1);
            res += dfs(visited, 1, 2, len - 1);
            res += dfs(visited, 2, 1, len - 1);
            res += dfs(visited, 1, 1, len - 1);
        }
        return res;
    }
private:
    int dfs(vector<vector<bool>>& visited, int x, int y, int remain) {
        if (remain < 0) return 0;
        if (remain == 0) return 1;
        visited[x][y] = true;
        int res = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (!visited[i][j] && isValid(visited, x, y, i, j)) {
                    res += dfs(visited, i, j, remain - 1);
                }
            }
        }
        visited[x][y] = false;
        return res;
    }
    bool isValid(const vector<vector<bool>>& visited, int x1, int y1, int x2, int y2) {
        int mx = (x1 + x2) / 2, my = (y1 + y2) / 2;
        if ((abs(x1 - x2) == 2 && y1 == y2) || (abs(y1 - y2) == 2 && x1 == x2) || (abs(x1 - x2) == 2 && abs(y1 - y2) == 2)) {
            if (!visited[mx][my]) return false;
        }
        return true;
    }
};
