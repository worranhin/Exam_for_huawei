//碎石头，本质就是背包问题，下面使用了一维（O（n））和二维（O（n*m））dp解决问题，分别是下面两个函数
//并实现了找出第一次满足的一个取法。
//打印了每次中间结果和某个物品是否被选择的表格，方便debug

//容易出错的点，在for循环中背包容量可以等于物品重量（j>= stones[i]）
//并且石头下标和二维dp[][]表的下标相差1，因为第一行用于初始化了，全为0,
// i = 1 才表示第一个物体所在行，所以在后面的表达式stones[i-1]是为了和物品数组的下标对上

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Solution
{
public:
    //背包问题求解，希望两堆石头大小尽可能接近，以对半分为目标，最后即使分不到对半也是最好的情况了
    int lastStoneWeightII_one(vector<int> &stones)
    {
        int len = stones.size();
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += stones[i];
        }
        int target = sum / 2;
        vector<int> dp(15001, 0);
        for (int i = 0; i < len; i++)
        {
            for (int j = target; j >= stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return (sum - dp[target] - dp[target]);
    }
    int lastStoneWeightII_two(vector<int> &stones)
    {
        int len = stones.size();
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += stones[i];
        }
        int target = sum / 2;
        vector<vector<int>> dp(31, vector<int>(15001, 0));
        vector<vector<bool>> choose(31, vector<bool>(15001, false));
        //用于记录满足第一次满足目标的i，用于回溯回去找所拿的物品
        int take_i;
        for (int i = 1; i <= len; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                if (j >= stones[i - 1])
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
                    choose[i][j] = true;
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
            if (dp[i][target] == target)
            {
                take_i = i;
                break;
            }
        }
        for (int i = 0; i <= 6; i++)
        {
            for (int j = 0; j <= 11; j++)
            {
                cout << dp[i][j] << '\t';
            }
            cout << endl;
        }
        cout << "----------------------------------------------" << endl;
        for (int i = 0; i <= 6; i++)
        {
            for (int j = 0; j <= 11; j++)
            {
                cout << choose[i][j] << '\t';
            }
            cout << endl;
        }

        ////////////////////////////////////////////////////////////////////////////
        vector<int> path;
        //输出路径
        int j = 11;
        for (int i = take_i; i > 0; i--)
        {
            if (choose[i][j]) //是否把第i块石头放入容量为j的背包中
            {
                j = j - stones[i - 1];
                path.push_back(stones[i - 1]);
            }
        }
        cout << "path:";
        for (auto p : path)
        {
            cout << p << "\t";
        }
        cout << endl;
        ////////////////////////////////////////////////////////////////////////////
        cout << sum - dp[take_i][target] - dp[take_i][target] << endl;
        cout << dp[take_i][target] << endl;
        return sum - dp[take_i][target] - dp[take_i][target];
    }
};
int main()
{
    Solution s;
    vector<int> test = {2, 7, 4, 1, 8, 1};
    s.lastStoneWeightII_two(test);
}