#include <iostream>

int main(void)
{
    using namespace std;
    unsigned int num;
    cin >> num;
    
    unsigned int mask = 1, count = 0;
    for(int i = 0; i < 32; i++){
        if(num & mask)
            count++;
        mask <<= 1;
    }
    cout << count << endl;
}