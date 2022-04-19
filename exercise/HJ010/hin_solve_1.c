#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool record[128] = {0};
    int amount = 0;
    char ch;
    
    while(scanf("%c", &ch) != EOF){
        if(ch == '\n')
            break;
        if(!record[ch]){
            amount++;
            record[ch] = 1;
        }
    }
    
    printf("%d", amount);
}
