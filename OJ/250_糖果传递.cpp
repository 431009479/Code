/*************************************************************************
	> File Name: 250_糖果传递.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月17日 星期日 20时11分26秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define Max_n 1000005
long long s[Max_n];
long long arr[Max_n];
long long g[Max_n];
long long n, sum, c;

int main(){
    cin >> n;
    for(long long i = 1; i <= n; i++){
        cin >> arr[i];
        s[i] = s[i - 1] +  arr[i];
        sum += arr[i];

    }
    c =  sum / n;
    for(long long i = 1; i <= n; i++){
        g[i] = s[i] - i * c;
    }

    sort(g + 1, g + 1 + n);
    c = g[n / 2];
    long long ans = 0;
    for(long long i = 1; i <= n; i++){
        ans += abs(g[i] - c);
    }

    cout << ans;
    return 0;
}
