/**
 * @file dz_solve_1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-04-08
 *
 * @copyright Copyright (c) 2022
 *
 *
 */
#include <iostream>
using namespace std;
int main()
{
    string word;
    getline(cin, word);
    int pos_space = word.find_last_of(' ');
    if (pos_space == string::npos)
    {
        cout << word.length() << endl;
    }
    else
    {
        cout << word.length() - pos_space - 1 << endl;
    }
    return 0;
}