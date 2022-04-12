//使用map容器，实现键值映射，且允许有重复的key-val；可用于有查找重复的
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(int argc, char **argv)
{
    string str;
    char c;
    int len;
    getline(cin, str);
    cin >> c;
    int count = 0;
    multimap<char, int> mult_map;
    int index = 0;
    for (auto c : str)
    {
        //可重复映射，方便用于计数
        pair<char, int> p(c, index++);
        mult_map.insert(p);
    }
    if (c >= 97)
    {
        count = mult_map.count(c) + mult_map.count(c - 32);
    }
    else if (c >= 65 && c <= 90)
    {
        count = mult_map.count(c) + mult_map.count(c + 32);
    }
    else
    {
        count = mult_map.count(c);
    }
    cout << count << endl;
}