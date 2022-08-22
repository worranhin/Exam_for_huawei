#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
 
int main(){
    string str_in, str_out;
    cin >> str_in;
    int len = str_in.length();  // 字符串长度
    
    // 记录次数
    int map[26] = {0};  // 出现次数表
    for(int i = 0; i < len; i++) {
        char ch = str_in[i];
        map[ch - 'a'] += 1;
    }
    
    // 找最小次数
    int min = 100;
    for(int i = 0; i < 26; i++) {
        if(map[i] != 0 && map[i] < min)
            min = map[i];
    }
    
    // 输出
    for(int i = 0; i < len; i++) {
        char ch = str_in[i];
        int appear = map[ch - 'a'];
        if(appear == min)
            continue;
        str_out.push_back(ch);
    }
    
    cout << str_out << endl;

    return 0;
}
