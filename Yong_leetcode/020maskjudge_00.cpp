#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool is_mask(string ip)
{
    istringstream iss(ip);
    string seg;
    unsigned int int_ip;
    int i = 3;
    while (getline(iss, seg, '.'))
    {
        unsigned int temp = stoi(seg);
        int_ip += temp << (i * 8);
        i--;
    }
    //排除全0或全1
    if (int_ip == 0xffffffff || int_ip == 0)
        return false;
    //掩码,从左往右最后一个1的下标应该等于从右往左最后一个0的下标

    unsigned int mask0 = 0x00000001;
    unsigned int mask1 = 0x80000000;
    int count0 = 0;
    int count1 = 0;
    while (!(mask0 & int_ip))
    {
        mask0 = mask0 << 1;
        count0++;
    }
    while (mask1 & int_ip)
    {
        mask1 = mask1 >> 1;
        count1++;
    }
    if (count1 + count0 == 32)
        return true;
    else
        return false;
}
int main()
{
    bool ret;
    string ip = "255.0.0.0";
    ret = is_mask(ip);
    cout << "zanting";
    return 0;
}