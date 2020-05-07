/*************************************************************************
	> File Name: 45.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月30日 星期四 20时20分06秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 1000
int dp[N + 5][N + 5];

string s1, s2;

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
