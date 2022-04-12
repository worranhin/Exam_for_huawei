//超时版本
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        int len = nums.size();
        unordered_map<int, int> num_map;
        int i = 0;
        for (auto n : nums)
        {
            // map是以键排序的
            pair<int, int> p(n, i++);
            num_map.insert(p);
        }

        for (int i = 0; i < len; i++)
        {
            num_map.erase(num_map.find(nums[i]));
            int sub_tar = target - nums[i];
            auto m = num_map.find(sub_tar);
            if (m != num_map.end())
            {
                res.push_back(m->second);
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};
int main(int argc, char **argv)
{
    Solution s;
    vector<int> test = {3, 2, 4};
    int target = 6;
    auto res = s.twoSum(test, target);
    for (auto i : res)
    {
        cout << i << endl;
    }
}