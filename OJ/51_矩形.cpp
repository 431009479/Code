/*************************************************************************
	> File Name: 51_矩形.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月12日 星期二 18时08分19秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define Max_N 1000
int f[Max_N + 5];
int a[Max_N + 5];//向下数，
int s[Max_N + 5], top = -1;

int main(){
    int n, m,val, ans = 0;
    cin >> n >> m;
    a[m + 1] = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> val;
            if(val == 1) a[j] += 1;
            else a[j] = 0;
        }
        top = -1;
        s[++top] = m + 1;
        for(int j = m; j >= 1; j--){
            while(a[s[top]] >= a[j]) top--;
            f[j] = (s[top] - j) * a[j] + f[s[top]];
            f[i] %= 100007;
            s[++top] = j;
            ans += f[j];
            ans %= 100007;
        }
    }               
    cout << ans;
    return 0;
}
