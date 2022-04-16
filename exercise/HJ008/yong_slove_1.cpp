//哈希映射，合并相同键值项
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    multimap<int, int> mmp;
    pair<int, int> p;
    string temp;

    while (n--)
    {
        getline(cin, temp, ' ');
        p.first = stoi(temp);
        getline(cin, temp);
        p.second = stoi(temp);

        auto m = mmp.find(p.first);
        if (m != mmp.end())
        {
            //相加
            m->second = m->second + p.second;
        }
        else
        {
            mmp.insert(p);
        }
        int len = mmp.size();
    }
    for (auto k : mmp)
    {
        cout << k.first << ' ' << k.second << endl;
    }
    return 0;
}