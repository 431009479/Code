/*************************************************************************
	> File Name: 563_拔河比赛.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月19日 星期二 00时32分44秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 500
#define max_m 500000
int f[max_m + 5];
int val[max_n + 5];

int S, sum, n, ans;
int main(){
    f[0] = 1;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> val[i];
        S += val[i];
    }
    sum = S / 2;
    for(int i = 1; i <= n; i++){
        for(int j = sum; j >= 0; j--){
            if(j >= val[i]) f[j] |= f[j - val[i]];
        }
    }
    for(int i = 0; i <= sum; i++){
        if(f[i]) ans = i;
    }

    cout << ans <<" "<< S - ans;

    return 0;
}

