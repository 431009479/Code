/*************************************************************************
	> File Name: 12.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月12日 星期五 17时34分47秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX 1000000
int prime[MAX + 5] = {0};
int f[MAX + 5] = {0};
int cnt[MAX + 5] = {0};

void init(){
    for(int i = 2; i<= MAX; i++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            f[i] = 2;
            cnt[i] = 1;
        }
        for(int j = 1; j <= prime[0]; j++){
            if(prime[j] * i > MAX) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0){
                f[i * prime[j]] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[i * prime[j]] = cnt[i] + 1;
                break;
            }else{
                f[i * prime[j]] = f[i] *f[prime[j]];
                cnt[i * prime[j]] = 1;
            }
        }
    }
}




int main(){

    init();
    long long f_max = 0, n = 1;
    while(1){
        if(n & 1){
            f_max = f[n] * f[(n + 1) >> 1];
        }else{
            f_max = f[n >> 1] * f[n + 1];
        }
        if(f_max > 500) break;
        n += 1;
    }
    printf("%lld\n", n * (n + 1) / 2);
    return 0;
}
