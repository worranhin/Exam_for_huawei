#include <stdio.h>

int main(void) {
    //初始化
    unsigned int tab[128];  // 创建一个字符存储出现次数的表
    for(int i = 0; i < 128; i++)  // 对表初始化
        tab[i] = 0;
    // 输入
    char ch = 0;
    while((ch = getchar()) != '\n') {
        tab[ch]++;  // 表中对应字符出现次数 +1
    }
    // 输出
    ch = getchar();
    if(ch >= 0x41 && ch < (0x41 + 26))    // ch 是大写字母
        printf("%d", tab[ch] + tab[ch + 32]);
    else if(ch >= 0x61 && ch < (0x61 + 26))   // ch 是小写字母
        printf("%d", tab[ch] + tab[ch - 32]);
    else
        printf("%d", tab[ch]);
}
