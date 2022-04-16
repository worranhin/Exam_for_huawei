//使用哈希表进行查找，使用set实现
//主要是去重比较麻烦，到达一个元素先无法判断是否重复，只有移动到下一个元素才需要判断和上一个元素是否重复
//关键点是每个i下的循环set都会重置
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[j], c = -(a + b)
        for (int i = 0; i < nums.size(); i++)
        {
            // 排序之后如果第一个元素已经大于零，那么不可能凑成三元组
            if (nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            { //三元组元素a去重
                continue;
            }
            unordered_set<int> set;
            for (int j = i + 1; j < nums.size(); j++)
            {
                // j>i+2是允许了b和c有重复的数值，同时避免了b往set中重复添加了c已经擦除的元素。
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2])
                { // 三元组元素b去重  个人认为这是c去重
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if (set.find(c) != set.end())
                {
                    result.push_back({nums[i], nums[j], c});
                    //避免了重复输出，比如{-1,0,1,1}是避免输出两次{-1,0,1}
                    set.erase(c); // 三元组元素c去重
                }
                else
                {
                    //找不到目标值时，将nums[j]作为b/c加入到set中,像当输入{-3,0,1,3}时，会将0和1加入到set中
                    //后面找到合适的b能匹配c时，将c擦除.
                    set.insert(nums[j]);
                }
            }
        }
        return result;
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    vector<int> test = {-1, 0, 1, 2, 3};
    s.threeSum(test);
}