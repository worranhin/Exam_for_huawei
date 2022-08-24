#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    // 输入
    int N;  // 同学总数
    cin >> N;
    
    vector<int> height(N);  // 同学身高
    for(int i = 0; i < N; i++) {
        cin >> height[i];
    }
    
    vector<int> higher(N);
    vector<int> lower(N);
    
    // 找高子左边的人数
    higher[0] = 1;
    for(int i = 1; i < N; i++) {
        int max = 1;
        int j = i - 1;
        while(j > -1) {
            if(height[i] > height[j] && higher[j] + 1 > max)
                max = higher[j] + 1;
            j--;
        }
        
        higher[i] = max;     
    }
    
    // 找高子右边人数
    lower[N-1] = 1;
    for(int i = N - 2; i > -1; i--) {
        int max = 1;
        int j = i + 1;
        while(j < N) {
            if(height[i] > height[j] && lower[j] + 1 > max)
                max = lower[j] + 1;
            j++;
        }
        lower[i] = max;
    }
    
    // 汇总
    int max = 0;
    for(int i = 0; i < N; i++) {
        int x = higher[i] + lower[i] - 1;
        max = x > max ? x : max;
    }
    
    cout << N - max << endl;    
    
    return 0;
}
