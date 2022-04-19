//求集合的所有子集
//思路：使用回溯，在处理结果集时不是满足什么条件才加入到结果集中，每次一进入回溯函数就加入结果集。
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int> &nums, int startindex)
    {
        res.push_back(path); //每次进入回溯函数就加入结果集
        if (startindex >= nums.size())
        {
            return;
        }
        for (int i = startindex; i < nums.size(); i++)
        {
            //处理节点数据
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        //关键就是终止条件之前结果集处理那里，每次一进回溯函数就得存结果，因为每个结果都是子集。
        backtracking(nums, 0);
        return res;
    }
};