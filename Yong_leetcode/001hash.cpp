#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int hash_array[1000];
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> res;
        //建立哈希表
        for (int i = 0; i < len1; i++)
        {
            hash_array[nums1[i]] = 1;
        }
        //查找
        for (int i = 0; i < len2; i++)
        {
            if (hash_array[nums2[i]] == 1)
            {
                res.push_back(nums2[i]);
                hash_array[nums2[i]] = 0;
            }
        }
        return res;
    }
};
int main()
{
    vector<int> nums1 = {4, 7, 9, 7, 6, 7};
    vector<int> nums2 = {5, 0, 0, 6, 1, 6, 2, 2, 4};
    Solution s;
    vector<int> res = s.intersection(nums1, nums2);
    for (auto i : res)
    {
        cout << i << endl;
    }
}