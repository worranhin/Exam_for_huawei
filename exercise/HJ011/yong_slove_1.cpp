//反转数字并输出
#include <string>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string str;
    str = to_string(n);
    int len = str.size();
    for (int i = len - 1; i >= 0; i--)
    {
        cout << str[i];
    }
    return 0;
}