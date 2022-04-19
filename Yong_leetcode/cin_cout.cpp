#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string str;
    getline(cin, str);     //获取一行，不会被空格打断,存入str
    istringstream is(str); //将str放入string输入流中is中，后面可以从流中获取数据，相当于缓存
    cout << str << endl;
    string temp;
    vector<string> sub;
    while (getline(is, temp, ' ')) //从string输入流中读取数据到string temp中，以空格作为分割一次读取。读到为空就返回空，跳出while
    {
        sub.push_back(temp);
    }
    for (int i = 0; i < sub.size(); i++)
    {
        cout << sub[i] << endl;
    }
}