//求集合中k个数的组合和为某个值的集合，从1-9选取，不能重复使用
//思路：回溯+剪枝
//回溯 就是一层for循环中调用回溯函数，关键是剪枝，考虑到在剩余选取的数小于需求数目时就终止，i <= (9+path.size()-k+1)，加一是因为i从1开始
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(int k, int target, int sum, int startindex)
    {
        //终止条件
        if (k == path.size())
        {
            if (sum == target)
                result.push_back(path);
            return;
        }
        //循环
        for (int i = startindex; i <= 9 && i <= (9 + path.size() - k + 1) && sum < target; i++)
        {
            //处理节点
            path.push_back(i);
            sum += i;
            //回调
            backtracking(k, target, sum, i + 1);
            //回溯
            sum -= i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        int sum = 0;
        backtracking(k, n, sum, 1);
        return result;
    }
};