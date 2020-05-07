/*************************************************************************
	> File Name: 553_单词的划分.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月01日 星期五 18时04分14秒
 ************************************************************************/

#include<iostream>
#include<set>
using namespace std;
#define INF 0x3f3f3f3f
#define M 100

string str, str_t;
set<string> arr;

int n, dp[M + 5];
int main(){
    cin >> str >> n;
    for(int i = 0; i < n; i++){
        cin >> str_t;
        arr.insert(str_t);
    }
    dp[0] = 0;
    for(int i = 0; str[i]; i++) dp[i + 1] = INF;
    for(int i = 1; i <= str.size(); i++){
        for(int j = 1; j <= i; j++){
            string s = str.substr(i - j, j);
            if(arr.find(s) == arr.end()) continue;
            dp[i] = min(dp[i], dp[i - j] + 1);
        }
    }
    cout << dp[str.size()];
    return 0;
}
