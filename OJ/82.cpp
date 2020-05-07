/*************************************************************************
	> File Name: 82.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月02日 星期四 09时47分14秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;


long long n, m, num[1000005], mmax;

long long func(){
    long long  l = 0, r = mmax;
    while(l != r){
        long long mid = (l + r + 1) / 2, all = 0;
        for(int i = 0; i < n; i++){
            if(num[i] > mid)
            all += num[i] - mid;
        }
        if(all >= m){
            l = mid;
        }else r = mid - 1;
    }
    return l;
}



int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> num[i];
       mmax =  max(mmax, num[i]);
    }
    cout << func();
    return 0;
}
