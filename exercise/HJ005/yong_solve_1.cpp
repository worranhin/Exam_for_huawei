#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//字符转数字
unsigned char chartonum(char c)
{
    unsigned char num;
    //小写a-f
    if (c >= 97)
    {
        num = c - 87;
    }
    else if ((c >= 65) && (c <= 70))
    {
        num = c - 55;
    }
    else //数字
    {
        num = c - 48;
    }
    return num;
}

int main(int argc, char **argv)
{
    char str[11];
    int i = 0;
    int sum = 0;

    while ((str[i] = getchar()) && (i < 10))
    {
        if (str[i] == '\n')
        {
            break;
        }
        i++;
    }
    //处理数据转换
    int ret;
    int j = 2;
    for (int len = i - 2; len > 0; len--)
    {
        ret = chartonum(str[j]);
        sum += (ret << ((len - 1) * 4));
        j++;
    }
    cout << sum << endl;
}
