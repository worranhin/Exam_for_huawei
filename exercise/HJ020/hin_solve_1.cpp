#include <iostream>
#include <string>
using namespace std;

int main()
{
    string passwd;
    cin >> passwd;
    while(!cin.eof()) {        
        // 判断长度
        if(passwd.length() <= 8) {
            cout << "NG\n";
            cin >> passwd;
            continue;
        }
        
        // 判断组合
        bool combine_upper  = false, 
             combine_lower  = false, 
             combine_number = false, 
             combine_other  = false;
        int combine_types = 0;
        for(int i = 0; i < passwd.length(); i++) {
            char ch = passwd.at(i);
            if(ch >= 'A' && ch <= 'Z')
                combine_upper = true;
            else if(ch >= 'a' && ch <= 'z')
                combine_lower = true;
            else if(ch >= '0' && ch <= '9')
                combine_number = true;
            else
                combine_other = true;
        
            // TODO: 也许可以优化 //
            combine_types = 
                (int)combine_upper + (int)combine_lower + (int)combine_number + (int)combine_other;
            if(combine_types >= 3)
                break;
        }
        if(combine_types < 3) {
            cout << "NG\n";
            cin >> passwd;
            continue;
        }
        
        // 判断子串
        /*
        逐个扫描，先找到下一个相同的字符（在当前位置+3开始找），然后看二者的+1、+2 偏移是否相同，
        若相同则有大于2的子串，若没有则查找下一个相同字符。
        最差情况是 O(n2)
        */
        bool hasSubstr = false;
        for(int i = 0; i < passwd.length() - 2 && !hasSubstr; i++) {
            char ch11 = passwd.at(i);
            char ch12 = passwd.at(i + 1);
            char ch13 = passwd.at(i + 2);
            for(int j = i + 3; j < passwd.length() - 2; j++) {
                char ch21 = passwd.at(j);
                char ch22 = passwd.at(j + 1);
                char ch23 = passwd.at(j + 2);
                if(ch11 == ch21 && ch12 == ch22 && ch13 == ch23) {
                    hasSubstr = true;
                    break;
                }
            }
        }
        if(hasSubstr) {
            cout << "NG\n";
            cin >> passwd;
            continue;
        }
        
        cout << "OK\n";
        cin >> passwd;
    }

    return 0;
}
