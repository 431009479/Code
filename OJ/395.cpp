/*************************************************************************
	> File Name: 395.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月09日 星期四 09时35分15秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;


long long n, m,sum, max_s, l, r;
long long ans[505][2], num[505];

long long fun(long long mid){
    long long k = 0, now = 0;
    for(int i = 0; i < n; i++){
        if(k + num[i] == mid){
            now++;
            k = 0;
        }else if(k + num[i] > mid){
            now++;
            k = num[i];
        }else{
            k += num[i];
        }
    }
    if(k > 0) now++;
    return now;
}



int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        sum += num[i];
    }
     r = sum;
    int mid;
    while(l != r){
        mid = (l + r ) / 2;
        if(fun(mid) > m){
            l = mid + 1;
        }else{
            r = mid;
        }
        
    }
    ans[m][1] = n;
    int now = num[n - 1], j = m;
    for(int i = n - 2; i >= 0; i--){
        if(now + num[i] > l){
            ans[j][0] = i + 2;
            j--;
            now = num[i];
            ans[j][i] = i + 1;
        }else if(now + num[i] == l){
            ans[j][0] = i + 1;
            j--;
            i--;
            now = num[i];
            ans[j][1] = i + 1;
        }else{
            now += num[i];
        }
    }
    ans[1][0] = 1;
    for(int i = 1; i <= m; i++){
        cout << ans[i][0] << " " << ans[i][1] <<'\n';
    }
    return 0;
}

