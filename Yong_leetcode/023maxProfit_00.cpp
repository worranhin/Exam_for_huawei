//股票买卖问题，前缀最小值和收益最大
//思路：动态 规划，使用数组记录前i天价格的最低值，同时使用一个变量迭代 全局最大收益，初始化问题
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxval; //记录价格最低
        int len = prices.size();
        vector<int> dp(len, 0); //记录此前的股票最低价格的状态
        //初始条件
        if (prices.size() < 2)
            return 0;
        dp[0] = prices[0];
        dp[1] = min(prices[0], prices[1]);
        maxval = (prices[1] - prices[0]) > 0 ? (prices[1] - prices[0]) : 0;
        for (int i = 2; i < prices.size(); i++)
        {
            dp[i] = min(dp[i - 1], prices[i]);
            maxval = (prices[i] - dp[i] > maxval) ? prices[i] - dp[i] : maxval;
        }
        return maxval;
    }
};