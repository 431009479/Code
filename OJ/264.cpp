/*************************************************************************
	> File Name: 264.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月28日 星期二 15时33分47秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define M 100000

long long h[M + 5];
long long l[M + 5], r[M + 5];
int s[M + 5], top = -1;


int main(){
    int n;
     cin >> n;
    h[0] = h[n + 1] = -1;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    s[++top] = 0;
    for(int i = 1; i <= n; i++){
        while(h[i] <= h[s[top]]) top--;
        l[i] = s[top];
        s[++top] = i;
    }
    top = -1;
    s[++top] = 0;
    for(int i = n; i >= 1; i--){
        while(h[i] <= h[s[top]]) top--;
        r[i] = s[top];
        s[++top] = i;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, h[i] * (r[i] - l[i] - 1));
    }
    cout << ans;


    return 0;
}
