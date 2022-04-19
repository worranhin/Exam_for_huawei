#include <stdio.h>

int main(void)
{
    char stack[30]; // 用堆栈来存字符
    int head = -1;
    
    char ch;
    while(scanf("%c", &ch) != EOF){
        if(ch == '\n')
            break;
        stack[++head] = ch;
    }
    
    while(head >= 0)
        printf("%c", stack[head--]);
}
