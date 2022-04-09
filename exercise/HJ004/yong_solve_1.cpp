#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char **argv)
{
    char c;
    int count;
    while ((c = getchar()) != '\n')
    {
        cout << c;
        count++;
        if ((count % 8) == 0)
        {
            cout << endl;
        }
    }
    int res;
    res = count % 8;
    if (res != 0)
    {
        int len = 8 - res;
        while (len--)
            cout << '0';
        cout << endl;
    }
}