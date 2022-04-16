#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        int len = s.size();
        stack<char> c_stack;
        if (len % 2 != 0)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < len; i++)
            {
                if (s[i] == '(')
                {
                    c_stack.push(')');
                }
                else if (s[i] == '[')
                {
                    c_stack.push(']');
                }

                else if (s[i] == '{')
                {
                    c_stack.push('}');
                }
                else //出现了有括号匹配到就判断是否满足栈顶，不满足说明不匹配，同时判断栈非空是防止第一个就是有括号导致的不匹配
                {
                    if (!c_stack.empty() && s[i] == c_stack.top())
                    {
                        c_stack.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        //最后栈为空才是完全匹配的
        if (c_stack.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string str = "(){}[]";
    bool res = s.isValid(str);
    cout << res << endl;
}