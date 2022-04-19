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
    int deleteAndEarn(vector<int> &nums)
    {
//由于数据范围不是很大，可以使用数组直接映射
//并使用另一个数组统计个数
//每个对应位置乘积获得每个数获得的点数值
//此时就是一个动态 规划问题，可以任意选取一个整数,相邻的数就选不了的问题
//借用rob代码即可
#define len 10001
        int size = nums.size();
        vector<int> count(len, 0);
        //存放对应数字存放点数的数组
        vector<int> val(len, 0);
        for (int i = 0; i < size; i++)
        {
            ++count[nums[i]];
        }
        for (int i = 0; i < len; i++)
        {
            val[i] = i * count[i];
        }
        return rob(val);
    }
};