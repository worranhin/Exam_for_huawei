#include <stdio.h>

int main(void){
    char in_str[101];
    scanf("%s", &in_str);
    
    unsigned short int index = 0;
    char out_str[9];
    while(in_str[index] != '\0'){
        out_str[index % 8] = in_str[index];
        if(index % 8 == 7){
            printf("%s\n", out_str);
        }
        ++index;
    }
    while(index % 8 != 0){
        out_str[index % 8] = '0';
        if(index % 8 == 7){
            printf("%s\n", out_str);
        }
        ++index;
    }
    
    return 0;    
}
