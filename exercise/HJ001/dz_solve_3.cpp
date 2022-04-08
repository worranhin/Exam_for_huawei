/**
 * @file dz_solve_1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-04-08
 *
 * @copyright Copyright (c) 2022
 *
 * 不需要每次计算大小
 *
 */
#include <iostream>
using namespace std;
int main()
{
    string word;
    while (cin >> word)
    {
        if (cin.peek() == '\n')
        {
            break;
        }
    }
    cout << word.length() << endl;
    return 0;
}