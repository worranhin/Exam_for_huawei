//机器人找路径，动态规划，
//思路：确定每个格子有多少个走法。
//重点是初始化和状态转移式子。
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // dp[m][n]代表走到mn格有多少走法
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //初始化
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
