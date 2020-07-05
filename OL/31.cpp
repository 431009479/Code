/*************************************************************************
	> File Name: 31.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月08日 星期一 22时25分35秒
 ************************************************************************/

#include<iostream>
using namespace std;

int w[9] = {0, 1, 2, 5, 10, 20, 50, 100, 200};
int dp[10][205];


int main(){
    dp[0][0] = 1; //用0种货币拼0元，
    for(int i = 1; i <= 8; i++){
            dp[i][0] = 1; //用货币拼0元
        for(int j = 1; j <= 200; j++){
            if(j < w[i]) dp[i][j] = dp[i - 1][j];
            else{
                dp[i][j] = dp[i - 1][j] + dp[i][j - w[i]];
            }
        }
    }
    cout << dp[8][200] << endl;
    return 0;
}
