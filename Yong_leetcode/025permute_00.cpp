//集合的全排列（有序）
//思路：每次都从数组中的第一个元素开始遍历，使用过的标记为true，使用一个vector<bool> used的数组进行标记，为true表示此元素被用过，
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
    vector<vector<int>> res;

    void backtracking(vector<int> &nums, vector<bool> &used)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            //处理节点数据
            if (used[i] == true)
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            //回调函数
            backtracking(nums, used);
            //回溯
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
};