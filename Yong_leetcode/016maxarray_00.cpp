//最大子数组，动态规划问题
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <queue>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len,0);
        dp[0] = nums[0];
        int maxsum = nums[0];
        for(int i = 1;i < len;i++)
        {
            dp[i] = max(nums[i],dp[i-1]+nums[i]); 
            maxsum = max(dp[i],maxsum);
        }
        return maxsum;
    }
};