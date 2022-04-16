#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string replaceSpace(string s)
    {
        int len = s.size();
        int fast = len - 1;
        int slow;
        for (int i = 0; i < len; i++)
        { //遇到一个空格填充2个位置
            if (s[i] == ' ')
            {
                s.push_back('0');
                s.push_back('0');
            }
        }
        slow = s.size() - 1;
        for (int i = 0; i < len; i++)
        {
            if (s[fast] == ' ')
            {
                s[slow--] = '0';
                s[slow--] = '2';
                s[slow--] = '%';
                fast--;
            }
            else
            {
                s[slow] = s[fast];
                fast--;
                slow--;
            }
        }
        return s;
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    string str = "We are happy.";
    s.replaceSpace(str);
}