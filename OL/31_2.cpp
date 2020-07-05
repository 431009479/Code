/*************************************************************************
	> File Name: 31_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月08日 星期一 22时46分20秒
 ************************************************************************/

#include<iostream>
using namespace std;

int w[9] = {0, 1, 2, 5, 10, 20, 50, 100, 200};

int dp[205];

int main(){
    dp[0] = 1;
    for(int i = 1; i <= 8; i++){
        for(int j = w[i]; j <= 200; j++){
            dp[j] += dp[j - w[i]];
        }
    }
    cout << dp[200] << endl;
    return 0;
}
