#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char **argv)
{
    string str;
    cin >> str;
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        cout << str[i];
        if (((i + 1) % 8) == 0)
        {
            cout << endl;
        }
    }
    if ((len = (len % 8)) != 0)
    {
        for (int i = 0; i < (8 - len); i++)
            cout << '0';
        cout << endl;
    }
}