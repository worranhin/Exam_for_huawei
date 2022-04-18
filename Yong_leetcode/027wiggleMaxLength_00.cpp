#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        //应该是贪心的想法，或者其实就是找完递增找递减，不符合直接跳过，首尾需要单独处理
        //一个大于后面就必须是小于，一个小于后面就必须是大于
        //满足上面情况的计数++,其他情况continue
        int res = 0;
        int len = nums.size();
        int index = 0;
        bool pos_flag = false;
        bool neg_flag = false;
        if (len < 3)
        {
            if ((len == 1) || ((len == 2) && (nums[0] == nums[1])))
                return 1;
            else
                return 2;
        }
        while (nums[index] == nums[index + 1])
        {
            index++;
        }
        res++;
        for (int i = index; i < len - 1; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                if (!pos_flag)
                {
                    res++;
                    pos_flag = true;
                    neg_flag = false;
                }
            }
            if (nums[i] > nums[i + 1])
            {
                if (!neg_flag)
                {
                    res++;
                    neg_flag = true;
                    pos_flag = false;
                }
            }
        }
        //结尾单独处理
        if (nums[len - 1] != nums[len - 2])
        {
            if (!pos_flag && nums[len - 1] > nums[len - 2])
                res++;
            if (!neg_flag && nums[len - 1] < nums[len - 2])
                res++;
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> test = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    s.wiggleMaxLength(test);
}