//新的想法是应该先找出因子，判断因子是否为质数，复杂度下降。
//中间由于遍历因子只需遍历sqrt（num）之前的数即可
//判断某个因子是否是质数也可以只判断比sqrt(num)小的即可
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool is_prime_number(int number)
{
    int num1 = (int)(sqrt(number));
    if (number == 1)
    {
        return false;
    }
    for (int i = 2; i <= num1; i++)
    {
        if ((number % i == 0))
            return false;
    }
    return true;
}
vector<int> find_elm(int number)
{
    vector<int> ret;
    //所有整数都有1这个因子
    ret.push_back(1);
    ret.push_back(number);
    int num1 = (int)(sqrt(number));
    int i = 0;
    //用于除到不能再除为止，即输出重复的因子。
    int temp = number;
    for (i = 2; i <= num1; i++)
    {
        while ((temp % i) == 0)
        {
            ret.push_back(i);
            temp = temp / i;
            ret.push_back(temp);
            if (temp == i)
                break;
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main()
{
    vector<int> factor;
    int num;
    cin >> num;
    factor = find_elm(num);
    int size = factor.size();
    int time = size + 1;
    for (int i = 0; i < size; i++)
    {
        if (is_prime_number(factor[i]))
            cout << factor[i] << " ";
    }
}