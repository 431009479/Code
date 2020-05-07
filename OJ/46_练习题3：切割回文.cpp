/*************************************************************************
	> File Name: 46_练习题3：切割回文.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月01日 星期五 18时26分42秒
 ************************************************************************/


#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define INF 0x3f3f3f3f
#define M 100

string str, str_t;

int n, dp[M + 5];
int main(){
    cin >> str;
    dp[0] = 0;
    for(int i = 0; str[i]; i++) dp[i + 1] = INF;
    for(int i = 1; i <= str.size(); i++){
        for(int j = 1; j <= i; j++){
            string s1 = str.substr(i - j, j);
            string s2 = s1;
            reverse(s1.begin(), s1.end());
            if(s1 != s2) continue;
            dp[i] = min(dp[i], dp[i - j] + 1);
        }
    }
    cout << dp[str.size()] - 1;
    return 0;
}

