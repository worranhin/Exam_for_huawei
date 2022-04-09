//超时版本
//新的想法是应该先找出因子，判断因子是否为质数，复杂度下降。
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
//找小于某个数的所有质数算法
vector<int> prime_number(int num)
{
    vector<int> result;
    int j;
    for (int i = 2; i <= num; i++)
    {
        for (j = 2; j <= i; j++)
        {
            if (i % j == 0)
                break;
        }
        if (j == i)
            result.push_back(i);
    }
    return result;
}
int main()
{
    vector<int> vec_ret;
    int num;
    cin >> num;

    vec_ret = prime_number(num);
    //商

    int size = vec_ret.size();
    // int count = 0;
    int i = 0;
    //因为是num的因子，因子不可能超过time,只需循环最多time次,这是用于找所有因子
    // int time = (int)sqrt(num);
    while (i < size)
    {
        if ((num % vec_ret[i]) == 0)
        {
            //商
            num = num / vec_ret[i];
            cout << vec_ret[i] << " ";
        }
        else
        {
            i++;
        }
    }
}