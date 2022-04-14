//使用栈实现逆波兰式计算
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        //思路：将数字压栈，直到遇到第一个符号，开始出栈计算，并将结果压栈；不是符号就将str转化为int压栈
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if (tokens[i] == "+")
                    st.push(num2 + num1);
                if (tokens[i] == "-")
                    st.push(num2 - num1);
                if (tokens[i] == "*")
                    st.push(num2 * num1);
                if (tokens[i] == "/")
                    st.push(num2 / num1);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        int result = st.top();
        st.pop(); // 把栈里最后一个元素弹出（其实不弹出也没事）
        return result;
    }
};
