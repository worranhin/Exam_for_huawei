#include <stdio.h>
#include <stdlib.h>

typedef struct data {
    int index;
    int value;
} Data;

/* 用于 qsort 的比较函数 */
int compar(const Data* a, const Data* b){
    int x, y;
    x = a->index;
    y = b->index;
    if(x > y) return 1;
    if(x < y) return -1;
    return 0;
}

int main(void) {
    // 初始化
    int n;
    scanf("%d", &n);
    Data data[n];
    for (int i = 0; i < n; i++) {
        Data temp = {-1, -1};
        data[i] = temp;
    }

    // 输入并处理键值对，存入哈希表
    for (int i = 0; i < n; i++) {
        int index, value;
        scanf("%d %d", &index, &value);
        int tabi = index % n;
        while(1){
            if(data[tabi].index == index){
                data[tabi].value += value;
                break;
            } else if(data[tabi].index == -1){
                data[tabi].index = index;
                data[tabi].value = value;
                break;
            }
            tabi = (tabi + 1) % n;
        }
    }
    qsort(data, n, sizeof(data[0]), compar);    // 依据index排序

    // 输出
    for (int i = 0; i < n; i++) {
        if (data[i].index != -1) {
            printf("%d %d\n", data[i].index, data[i].value);
        }
    }

    return 0;
}
