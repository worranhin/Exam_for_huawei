#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    char c;
    int len;
    while ((c = getchar()) != '\n')
    {
        if (c == ' ')
        {
            str.clear();
        }
        else
        {
            str = str + c;
        }
    }
    len = str.length();
    cout << len;
}