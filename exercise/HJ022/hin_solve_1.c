#include <stdio.h>

int maxDrink(unsigned int n) {
    if(n == 1)
        return 0;
    else if(n == 2 || n == 3)
        return 1;
    else
        return 1 + maxDrink(n - 2);
}

int main(void) {
    // 变量定义
    unsigned int n, m;
    
    scanf("%d", &n);    // 获取输入
    while(n != 0){
        m = maxDrink(n);    // 计算
        printf("%d\n", m);    // 输出
        scanf("%d", &n);
    }
}
