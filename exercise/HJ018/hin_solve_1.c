#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

#define N 20  // 存地址的数组

typedef enum ipType {A = 0, B, C, D, E, ERROR, PRIVATE} IpType;

/* 获取输入至 ip 和 mask 中，若没有输入返回 EOF */
int input_ip(char* ip, char* mask) {
    char s[40];
    if (scanf("%s", s) == EOF)
        return EOF;
    char* p = memchr(s, '~', 40);
    *p++ = '\0';
    strcpy(ip, s);
    strcpy(mask, p);

    return 0;
}

/* 解析地址，拆成四个数存入数组中；若格式不正确返回-1 */
int parse_ip(int* a, const char* pstr, int n) {
    char* s_start, *s_end;
    char* s_temp = calloc(n + 1, sizeof(pstr[0]));
    s_start = strcpy(s_temp, pstr);

    for (int i = 0; i < 3; i++) {
        s_end = strchr(s_start, '.');
        *s_end = '\0';
        if (strlen(s_start) == 0)
            return -1;
        a[i] = atoi(s_start);
        s_start = s_end + 1;
    }
    if (strlen(s_start) == 0)
        return -1;
    a[3] = atoi(s_start);

    free(s_temp);
    return 0;
}

int main(void) {
    unsigned int type_count[7] = {0};
    int x = 0;
    char s_ip[N], s_mask[N];

    while (input_ip(s_ip, s_mask) != EOF) {
        int ip_sec[4], mask_sec[4];

        // 解析 ip
        if (parse_ip(ip_sec, s_ip, N) == -1) {
            type_count[ERROR] += 1;
            continue;
        }

        // 判断 ip 合法性
        int ip_error = 0;
        for (int i = 0; i < 4; i++) {
            if (ip_sec[i] < 0 || ip_sec[i] > 255) {
                printf("ip 不合法\n");
                ip_error = 1;
                break;
            }
        }
        if (ip_error) {
            type_count[ERROR] += 1;
            continue;
        }

        // 检查是否 0.* 或 127.*
        if (ip_sec[0] == 0 || ip_sec[0] == 127)
            continue;

        // 解析 mask
        if (parse_ip(mask_sec, s_mask, N) == -1) {
            type_count[ERROR] += 1;
            continue;
        }

        // 检查掩码合法性
        int mask_error = 0;

        uint32_t u_mask = 0;    // 32位长掩码
        for (int i = 0; i < 4; i++) {
            u_mask <<= 8;
            u_mask |= mask_sec[i];    // 组合成 32 位数
        }
        // 判断掩码格式
        if (u_mask == 0xffffffff || u_mask == 0x00000000) {
            mask_error = 1;
        } else {
            int head_flag = 0;
            uint32_t test_mask = 1;

            for (int i = 0; i < 32; i++) {
                if ((head_flag == 0) && ((test_mask & u_mask) != 0))
                    head_flag = 1;
                else if ((head_flag == 1) && ((test_mask & u_mask) == 0)) {
                    mask_error = 1;
                    break;
                }
                test_mask <<= 1;
            }
        }
        if (mask_error) {
            type_count[ERROR] += 1;
            continue;
        }

        // 判断私有地址
        _Bool private_rule1 = ip_sec[0] == 10;    // 判断私网规则
        _Bool private_rule2 = (ip_sec[0] == 172) && (ip_sec[1] >= 16 &&
                              ip_sec[1] <= 31);
        _Bool private_rule3 = (ip_sec[0] == 192) && (ip_sec[1] == 168);
        if (private_rule1 || private_rule2 || private_rule3)
            type_count[PRIVATE] += 1;

        // 分类 A~E
        if (ip_sec[0] >= 1 && ip_sec[0] <= 126)
            type_count[A] += 1;
        else if (ip_sec[0] >= 128 && ip_sec[0] <= 191)
            type_count[B] += 1;
        else if (ip_sec[0] >= 192 && ip_sec[0] <= 223)
            type_count[C] += 1;
        else if (ip_sec[0] >= 224 && ip_sec[0] <= 239)
            type_count[D] += 1;
        else if (ip_sec[0] >= 240 && ip_sec[0] <= 255)
            type_count[E] += 1;
    }    // end input while

    // 输出
    printf("%d %d %d %d %d %d %d\n",
           type_count[0],
           type_count[1],
           type_count[2],
           type_count[3],
           type_count[4],
           type_count[5],
           type_count[6]);

    return 0;
}
