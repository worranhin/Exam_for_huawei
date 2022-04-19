//数组（有重复的数据）的全排列（有序）
//思路：每次都从数组中的第一个元素开始遍历，使用过的标记为true，使用一个vector<bool> used的数组进行标记，为true表示此元素被用过。
//去重需要先排序，再在for循环中判断是否与同一层的节点取了不同索引但数字相同的数字
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, vector<bool> &used)
    {
        // 此时说明找到了一组
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            // used[i - 1] == true，说明同一树枝nums[i - 1]使用过，此处同一树枝是指一条路径中
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
            {
                continue; //关键是排序后才能这么判断，相等的判断才能传递下来,即重复的数字在同一层，一个节点下的一层。
            }
            if (used[i] == false)
            {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // 排序
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};