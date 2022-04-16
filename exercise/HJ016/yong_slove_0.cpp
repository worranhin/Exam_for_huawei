//使用二维矩阵，空间复杂度较大O(n*m)，时间复杂度为O(n*m),因为遍历了一个n*m的二维数组
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, m;
    cin >> N >> m;
    int price, happy, index;

    vector<vector<int>> data(m + 1, vector<int>(6, 0));
    for (int i = 1; i <= m; i++) //建立价格和满意度表，并把附件归到主件行,不是主件的行是空的，不影响结果
    {                            //此处从1开始是为了和下面实现dp遍历对应，dp的第一行作为初始化为0，第二行即i=1作为第一个物品的遍历
        cin >> price >> happy >> index;
        if (index == 0)
        {
            //说明是主件
            data[i][0] = price;
            data[i][1] = happy;
        }
        else if (data[index][2] == 0) //第一附件
        {
            data[index][2] = price;
            data[index][3] = happy;
        }
        else //第二附件
        {
            data[index][4] = price;
            data[index][5] = happy;
        }
    }
    //递推实现
    vector<vector<int>> dp(m + 1, vector<int>(N + 1, 0));
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            int mainprice = data[i][0];
            int mainhappy = data[i][1];
            int attachprice1 = data[i][2];
            int attachhappy1 = data[i][3];
            int attachprice2 = data[i][4];
            int attachhappy2 = data[i][5];
            //细心细心，需要注意是在哪个情况下拿与不拿，不拿是保持哪个结果
            //因为这里一个物品中还附带了附件，所以在j没有大于主件+附件时保持和第一个if同样的结果，dp[i][j]
            if (j < mainprice)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - mainprice] + mainprice * mainhappy);
            if (j < (mainprice + attachprice1))
                dp[i][j] = dp[i][j];
            //此处关键是max中dp[i][j]
            else
                dp[i][j] = max(dp[i][j],
                               dp[i - 1][j - mainprice - attachprice1] + mainprice * mainhappy + attachprice1 * attachhappy1);
            if (j < (mainprice + attachprice2))
                dp[i][j] = dp[i][j];
            //此处关键是max中dp[i][j]
            else
                dp[i][j] = max(dp[i][j],
                               dp[i - 1][j - mainprice - attachprice2] + mainprice * mainhappy + attachprice2 * attachhappy2);
            if (j < (mainprice + attachprice1 + attachprice2))
                dp[i][j] = dp[i][j];
            else
                dp[i][j] = max(dp[i][j],
                               dp[i - 1][j - mainprice - attachprice1 - attachprice2] + mainprice * mainhappy + attachprice1 * attachhappy1 + attachprice2 * attachhappy2);
        }
    }
    cout << dp[m][N];
    return 0;
}