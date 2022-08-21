/* 暴力解法 */
#include<iostream>
#include<string>
using namespace std;

int main(){
    string passwd, passwd_after;
    cin >> passwd;
    
    for(int i = 0; i < passwd.length(); i++) {
        char ch = passwd.at(i);
        char ch_after;
        
        if(ch == '1') {
            ch_after = '1';
        } else if(ch >= 'a' && ch <= 'c') {
            ch_after = '2';
        } else if(ch >= 'd' && ch <= 'f') {
            ch_after = '3';
        } else if(ch >= 'g' && ch <= 'i') {
            ch_after = '4';
        } else if(ch >= 'j' && ch <= 'l') {
            ch_after = '5';
        } else if(ch >= 'm' && ch <= 'o') {
            ch_after = '6';
        } else if(ch >= 'p' && ch <= 's') {
            ch_after = '7';
        } else if(ch >= 't' && ch <= 'v') {
            ch_after = '8';
        } else if(ch >= 'w' && ch <= 'z') {
            ch_after = '9';
        } else if(ch == '0') {
            ch_after = '0';
        } else if(ch >= 'A' && ch < 'Z') {
            ch_after = (char)(ch + 0x20 + 1);
        } else if(ch == 'Z') {
            ch_after = 'a';
        } else {
            ch_after = ch;
        }
        
        passwd_after.push_back(ch_after);
        
    }
    cout << passwd_after <<endl;
    
    return 0;
}
