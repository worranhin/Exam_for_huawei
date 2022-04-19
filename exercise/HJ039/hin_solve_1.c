#include <stdio.h>

int getIp(unsigned int* ip_ptr){
    for(int i = 0; i < 4; i++) {
        unsigned int temp;
        if(i < 3)
            scanf("%d.", &temp);
        else
            scanf("%d", &temp);
        
        if(temp > 255){
            return 1;
        }
        *ip_ptr <<= 8;
        *ip_ptr |= temp;
    }
    return 0;
}

int main(void) {
    unsigned long mask = 0, ip1 = 0, ip2 = 0, processIp1 = 0, processIp2 = 0;
    // 输入掩码
    if(getIp(&mask)){
        printf("1");
        return 0;
    }
    unsigned long testMask = 1;
    int flag = 0;
    for(int i = 0; i < 32; i++){
        unsigned long temp = testMask & mask;
        if(flag == 0 && temp != 0){
            flag = 1;
        }
        else if(flag == 1 && temp == 0){
            printf("1");
            return 0;
        }
        testMask <<= 1;
    }
    
    
    // 输入 ip
    if(getIp(&ip1)){
        printf("1");
        return 0;
    }
    if(getIp(&ip2)){
        printf("1");
        return 0;
    }
    
    // 检查并输出
    processIp1 = mask & ip1;
    processIp2 = mask & ip2;
    if(processIp1 == processIp2)
        printf("0");
    else
        printf("2");
        
    return 0;
}
