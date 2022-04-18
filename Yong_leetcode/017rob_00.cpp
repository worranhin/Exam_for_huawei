//问题：打家劫舍，给定数组任取一个数，取完后相邻两个数不能再取
//思路：典型的动态规划问题，取与不取，是怎么转移的，考虑取第i个数，那么转态是从dp[i-2]，转移过来的
//      因为dp[i]存的是前i个的最优取法。
//      确定初始状态（dp0和dp1，dp1需要取数组中前两个元素的较大值）并考虑特殊情况（数组只有1个或者两个元素时）
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <queue>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> dp(len, 0);
        if (len == 1)
            return nums[0];
        if (len < 2)
            return max(nums[0], nums[1]);
        //初始状态
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[len - 1];
    }
};