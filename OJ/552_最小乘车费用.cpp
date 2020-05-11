/*************************************************************************
	> File Name: 552_最小乘车费用.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月08日 星期五 23时21分42秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define Max 1000000
int arr[11], dp[105], n;


int main(){
    int i, j;
    for(int i = 1; i <= 10; i++){
        cin >> arr[i];
    }
        cin >> n;

    for(int i = 1; i <= n; i++){
        dp[i] = Max;
    }
    
    arr[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 10 && j <= i; j++){
            dp[i] = min(dp[i], dp[i - j] + arr[j]);
        }
    }
        cout << dp[n];
    return 0;
}
