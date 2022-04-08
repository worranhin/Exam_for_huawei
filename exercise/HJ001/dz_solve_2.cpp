/**
 * @file dz_solve_1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-04-08
 *
 * @copyright Copyright (c) 2022
 *
 * 从输入优化入手,想借助cin的缓冲区,要是能遇到换行符退出就好了
 *
 */
#include <iostream>
using namespace std;
int main()
{
    string word;
    int len = 0;
    while (cin >> word)
    {
        len = word.length();
        if (cin.peek() == '\n')
        {
            break;
        }
    }
    cout << len << endl;
    return 0;
}