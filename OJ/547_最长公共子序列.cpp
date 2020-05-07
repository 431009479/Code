/*************************************************************************
	> File Name: 547_最长公共子序列.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月01日 星期五 15时22分58秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

#define N 5000
string s1, s2;
int dp[N + 5][N + 5];

int main(){
    cin >> s1 >> s2;
    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            if(s1[i - 1] - s2[j - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            else dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }
    cout << dp[s1.size()][s2.size()];
    return 0;
}

