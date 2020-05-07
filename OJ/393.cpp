/*************************************************************************
	> File Name: 393.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月02日 星期四 10时12分13秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include <cstdio>
#include <cmath>
using namespace std;


int n, k;
double num[10005], mmax;

int check(double len){
    int m = 0;
    for(int i  = 0; i < n; i++){
        m += num[i] / len;
    }
    return m;
}


double func(){
    double l = 0, r = mmax;
    while(fabs(l - r) > 0.00001){
        double mid = (l + r) / 2;
        int temp = check(mid);
        if(temp >= k){
            l = mid;
        }else{
            r = mid;
        }
    }
    return r;
}



int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        mmax = max(mmax, num[i]);
    }
    double ans = func();
    printf("%d.%d%d", int(ans), int(ans * 10) % 10, int(ans * 100) % 10);
    return 0;
}
