//爬楼梯，动态规划解法，1，m为一次可以爬的阶数。
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
    int climbStairs(int n)
    {
        // dp[i]记录第i阶楼梯有最多几种爬到的方法d[i] = dp[i-1] + dp[i-m],此处m为2
        int m = 2;
        if (n < m)
            return 1;
        vector<int> dp(n + 1, 0);
        //初始化dp[0] = 0,其实dp[0]没有意义，第0阶就是原地，不用爬就到了
        for (int i = 1; i < m; i++)
        {
            dp[i] = 1;
        }
        dp[m] = 2; //初始化
        for (int i = m + 1; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - m];
        }
        return dp[n];
    }
};