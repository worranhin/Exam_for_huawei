/**
 * @file dz_solve_1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-04-08
 *
 * @copyright Copyright (c) 2022
 *
 * 不需要string,直接计算长度
 *
 */
#include <stdio.h>
using namespace std;
int main()
{
    int len = 0;
    char ch;
    while ((ch = getchar()) != '\n')
    {
        if (ch == ' ')
        {
            len = 0;
            continue;
        }
        len++;
    }
    printf("%d\n", len);
    return 0;
}