/*************************************************************************
	> File Name: 50_扔鸡蛋.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月12日 星期二 18时54分28秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define Max_n 32
#define Max_m 65536
long long  dp[Max_n + 5][Max_m + 5];

int main(){
    long long n, m ;
    cin >> n >> m;
    if(n == 1){
        cout << m << endl;
        return 0;
    }
    for(long long k = 1; k <= Max_m; k++) dp[1][k] = k;
    for(long long i = 2; i <= n; i++){
        for(long long k = 1; k <= Max_m; k++){
            dp[i][k] = dp[i - 1][k - 1] + dp[i][k - 1] + 1;
        }
    }
    long long p = 1;
    while(dp[n][p] < m) p++;
        cout << p << endl;
    return 0;
} 
