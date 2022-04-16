//计算整数转换为二进制字符串，其中会有多少个1
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    int count = 0;
    int n;
    while ((n / 2) != 0)
    {
        if (n % 2 == 1)
            count++;
        n = n / 2;
        if (n == 1)
        {
            count++;
        }
    }
    cout << count;
}