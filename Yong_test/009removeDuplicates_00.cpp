//使用栈删除相邻重复的字符，最后的结果必须没有重复的
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string s)
    {
        int len = s.size();
        stack<char> c_stack;
        //记录删除了几个元素，后续方便出栈确定s的长度，也记录在count中
        int count = 0;
        if (len > 1)
        {
            c_stack.push(s[0]);
            for (int i = 1; i < len; i++)
            {
                if (!c_stack.empty())
                {
                    if (s[i] == c_stack.top())
                    {
                        if (s[i] == c_stack.top())
                        {
                            c_stack.pop();
                            count++;
                        }
                    }
                    else
                    {
                        c_stack.push(s[i]);
                    }
                }
                else
                {
                    c_stack.push(s[i]);
                }
            }
        }
        // count*2是因为每次pop一次跳过了相邻的两个字符
        count = len - count * 2;
        s.resize(count);
        for (int i = count - 1; i >= 0; i--)
        {
            s[i] = c_stack.top();
            c_stack.pop();
        }
        return s;
    }
};
int main()
{
    Solution s;
    string str = "aacc";
    s.removeDuplicates(str);
    vector<string> tokens = {"a", "b"};
    cout << tokens[0][0] + 1 << endl;
}