/*************************************************************************
	> File Name: 343_最长公共上升子序列.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月03日 星期日 10时12分01秒
 ************************************************************************/

#include<iostream>
using namespace std;


#define N 3000

long long n,  a[N + 5], b[N + 5], dp[N + 5][N + 5], sum;


int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++){
        long long maxv = -2000000;
        for(int j = 1; j <= n; j ++){
            dp[i][j] = dp[i - 1][j];
            if(a[i] == b[j]){maxv = max(maxv, dp[i][j]);
             if(a[i]> b[j]) dp[i][j] =max( maxv,dp[i - 1][j] + 1);
                }

            }
    
        }
    for(int i = 1; i <= n; i++){
        sum = max(sum, dp[n][i]);
    }

    cout << sum;

    return 0;
}
