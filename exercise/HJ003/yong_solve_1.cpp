#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// unsigned short mid_find(vector<unsigned short> vec, unsigned short num, unsigned short mid, unsigned short *begin, unsigned short *end)
// {
//     //下标，
//     int len = *end;
//     int ret;
//     for (int i = 0; i < len; i++)
//     {
//         if ((vec[mid] == num) || (mid == *begin) || (mid == *end))
//             break;
//         else
//         {
//             if (num <= vec[mid])
//             {
//                 *end = mid;
//             }
//             else
//             {
//                 *begin = mid;
//             }
//         }
//         if (vec[mid] == num)
//             ret++;
//     }
//     return ret;
// }
int main(int argc, char *argv[])
{
    int N = 0;
    vector<unsigned short> vec;
    unsigned short int tem = 0;
    // unsigned short mid, begin, end;
    // begin = 0;
    //最后一个元素下标
    cin >> N;
    while (N && (N >= 1) && (N <= 1000))
    {
        unsigned int ret;
        cin >> tem;
        vec.push_back(tem);
        N--;
    }
    unsigned short end = vec.size();
    sort(vec.begin(), vec.end());
    tem = -1;
    for (int i = 0; i < end; i++)
    {
        if (tem != vec[i])
        {
            cout << vec[i] << endl;
        }
        else
        {
            continue;
        }
        tem = vec[i];
    }
}
// while (!N && (N >= 1) && (N <= 1000))
// {
//     unsigned int ret;
//     mid = (begin + end) / 2;
//     cin >> tem;
//     ret = mid_find(vec, tem, mid, &begin, &end);
//     //需要在下标ret后插入

// }
