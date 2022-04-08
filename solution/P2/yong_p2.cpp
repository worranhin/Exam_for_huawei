#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    char c;
    int len;
    int count = 0;
    getline(cin, str);
    cin >> c;
    len = str.length();
    if (c == ' ')
    {
        for (int i = 0; i < len; i++)
        {
            if (str[i] == ' ')
                count++;
        }
    }
    else if ((c >= 48) && (c <= 57))
    {
        for (int i = 0; i < len; i++)
        {
            if (c == str[i])
                count++;
        }
    }
    else
    {

        if (c >= 97)
        {
            for (int i = 0; i < len; i++)
            {
                if ((c == str[i]) || (c == (str[i] + 32)))
                    count++;
            }
        }
        else
        {
            for (int i = 0; i < len; i++)
            {
                if ((c == str[i]) || (c == (str[i] - 32)))
                    count++;
            }
        }
    }

    cout << count << endl;
}