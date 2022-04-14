//使用双指针法进行，两边往中间收缩
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {

            // 排序之后如果第一个元素已经大于零，那么不可能凑成三元组
            if (nums[i] > 0)
            {
                return result;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            { //三元组元素a去重
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left)
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                    while (left < right && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                }
                else //找到了
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    //必须得先去重再同时移动左右指针,为什么必须是这个顺序，先判断left不行吗，细节就是数组可能会越界，在没有判断right>left就去使用索引可能会越界
                    while (right > left && nums[left] == nums[left + 1])
                        left++;
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    //下面是错误做法，会越界
                    // while (nums[left] == nums[left + 1] && right > left)
                    //     left++;
                    // while (nums[right] == nums[right - 1] && right > left)
                    //     right--;
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    vector<int> test = {-1, 0, 1, 2, -1, -4};
    auto res = s.threeSum(test);
}