#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool isHappy(int n)
    {
        vector<int> nums;
        int sum = 0;
        // sum的最大范围不会超过800多，极端为每个位为9.
        int hash_arry[2000] = {0};
        while (1)
        {
            while ((n / 10) != 0)
            {
                nums.push_back(n % 10);
                n = n / 10;
            }
            nums.push_back(n);
            for (auto i : nums)
            {
                sum += (i * i);
            }
            if (sum == 1)
            {
                return true;
            }
            else
            {
                if (hash_arry[sum] != 1)
                    hash_arry[sum] = 1;
                else //说明出现了循环了
                {
                    return false;
                }
            }
            n = sum;
        }
    }
};
int main()
{
    Solution s;
    s.isHappy(19);
}