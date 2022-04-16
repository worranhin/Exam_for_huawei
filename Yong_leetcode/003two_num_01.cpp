//高效哈希表版本，慢慢往后添加，每次添加进来的作为本次target相减的数
//前面加进来的数会被后面作为找的目标，等价与前面去找后面，但是这样只需一次循环就可以解决。
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
        unordered_map<int, int> hash;
        int i = 1;
        // 0为在数组中的索引
        hash[nums[0]] = 0;
        while (i < nums.size())
        {
            auto m = hash.find(target - nums[i]);
            if (m != hash.end())
            {
                return {m->second, i};
            }
            hash[nums[i]] = i;
            ++i;
        }
        return {};
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
    // map<int, int> test1;
    // test1[1] = 1;
    // test1[0] = 0;
    // test1[2] = 2;
    // for (map<int, int>::iterator it = test1.begin(); it != test1.end(); it++)
    // {
    //     cout << it->first << endl;
    // }
    unordered_map<int, int> test2;
    test2[1] = 1;
    test2[0] = 0;
    test2[2] = 2;
    test2[50] = 50;
    for (unordered_map<int, int>::iterator it = test2.begin(); it != test2.end(); it++)
    {
        cout << it->first << it->second << endl;
    }
}