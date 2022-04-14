#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int slow = 0;
        int len = s.size();
        int fast = s.size() - 1;
        int count = 0;
        int temp;
        string res;
        for (int i = 0; i < len; i++)
        {
            if (s[fast] != ' ')
            {
                fast--;
                count++;
                if (i != (len - 1))
                    continue;
            }
            temp = fast - 1;
            while (count)
            {
                res.push_back(s[++fast]);
                count--;
            }
            if (res.size() != len)
                res.push_back(' ');
            fast = temp;
        }
        return res;
    }
};
int main(int argc, char **argv)
{
    Solution s;
    string str = "the sky";
    s.reverseWords(str);
}