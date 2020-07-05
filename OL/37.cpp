/*************************************************************************
	> File Name: 37.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月09日 星期二 15时35分24秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
#define M 1000000
int arr[M + 5];
int ans[M + 5];
void func(){
    for(int i = 2; i <= M; i++){
        if(!arr[i]) {
            ans[i] = 1;
            arr[++arr[0]] = i;
        }
        for(int j = 1; j <= arr[0]; j++){
            if(arr[j] * i > M) break;
            arr[i * arr[j]] = 1;
            if(i % arr[j] == 0) break;
        }
    }
}


int cmp(int n){
    int k = floor(log10(n)) + 1;
    int m = n;
    for(int i = 1; i <= k; i++){
        if(!ans[n])  return 0;
        n /= 10;
    }
    int h = (int)pow(10, floor(log10(m)));
    for(int i = 1; i <= k; i++){
        if(!ans[m]) return 0;
        m -= (m / h) * h;
        h /= 10;
    }
    return 1;
}


int sum = 0, n = 0;

int main(){
    func();
    for(int i = 10; i < M; i++){
        if(cmp(i)) n++, sum += i;
        if(n == 11) break;
    }
    cout << sum;
    return 0;
}
