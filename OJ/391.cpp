/*************************************************************************
	> File Name: 391.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月09日 星期四 09时07分33秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;


long long n, m, sum, max_s;
long long ans[1000005];

long long fun(long long mid){
    long long k = 0, now = 0;
    for(int i = 0; i < n; i++){
        if(k + ans[i] == mid){
            now++;
            k = 0;
        }else if(k + ans[i] > mid){
            now++;
            k = ans[i];
        }else{
            k += ans[i];
        }
    }
    if(k > 0) now++;
    return now;
}



int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> ans[i];
        sum += ans[i];
        max_s = max(max_s, ans[i]);
    }
    long long l = max_s, r = sum, mid;
    while(l != r){
        mid = (l + r ) / 2;
        if(fun(mid) > m){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    cout << l;
    return 0;
}

