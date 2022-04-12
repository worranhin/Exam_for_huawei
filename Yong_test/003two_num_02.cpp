//自己使用有序的键值且允许key值重复的multimap实现的，相当于对key进行了排序
//通过key获取第一个nums后，使用start指针将其删除
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
        multimap<int, int> num_map;
        int i = 0;
        int index = 0;
        for (auto n : nums)
        {
            // map是以键排序的
            pair<int, int> p(n, i++);
            num_map.insert(p);
        }

        multimap<int, int>::iterator start = num_map.begin();
        for (auto mp : num_map)
        {
            int sub_tar = target - mp.first;
            index = mp.second;
            num_map.erase(start);
            auto m = num_map.find(sub_tar);
            if (m != num_map.end())
            {
                res.push_back(m->second);
                res.push_back(index);
                break;
            }
            start++;
        }
        return res;
    }
};
int main(int argc, char **argv)
{
    Solution s;
    vector<int> test = {3, 3};
    int target = 6;
    auto res = s.twoSum(test, target);
    for (auto i : res)
    {
        cout << i << endl;
    }
}
