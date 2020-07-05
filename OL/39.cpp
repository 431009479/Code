/*************************************************************************
	> File Name: 39.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月12日 星期五 22时32分28秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX 1000
int cnt[MAX + 5] = {0};

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    for(int n = 1; n <= 32; n++){
        for(int m = n + 1; m <= 32; m++){
            if(gcd(n, m) - 1) continue;
            int a = 2 * m * n;
            int b = m * m - n * n;
            int c = m * m + n * n;
            for(int p = a + b + c; p <= 1000; p += (a + b + c)){
                cnt[p] += 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < MAX; i++){
        if(cnt[i] > cnt[ans]) ans = i;
    }
    cout << ans;
    return 0;
}
