//救赎金，字符组合
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
    bool canConstruct(string ransomNote, string magazine)
    {
        int hash[26] = {0};
        int mag_size = magazine.size();
        int ran_size = ransomNote.size();
        //创建hash表
        for (int i = 0; i < mag_size; i++)
        {
            hash[magazine[i] - 97]++;
        }
        //查找
        for (int i = 0; i < ran_size; i++)
        {
            if (hash[ransomNote[i] - 97] != 0)
            {
                hash[ransomNote[i] - 97]--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
int main(int argc, char **argv)
{
    Solution s;
    s.canConstruct("aa", "aab");
}
