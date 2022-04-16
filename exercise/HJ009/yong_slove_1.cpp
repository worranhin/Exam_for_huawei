//哈希映射去重复数字并逆序输出
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string num;
    string res;
    //创建哈希数组
    char hash[10] = {0};
    num = to_string(n);
    int len = num.size();
    for (int i = len - 1; i >= 0; i--)
    {
        if (hash[num[i] - 48] != 1)
        {
            res += num[i];
            hash[num[i] - 48] = 1;
        }
    }
    n = stoi(res);
    cout << n << endl;
    return 0;
}