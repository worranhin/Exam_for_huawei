//统计不同字符的个数，哈希set
#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    string str;
    set<char> c_set;
    getline(cin, str);
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        c_set.insert(str[i]);
    }
    cout << c_set.size() << endl;
    return 0;
}