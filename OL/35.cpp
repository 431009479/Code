/*************************************************************************
	> File Name: 35.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月09日 星期二 14时57分38秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
#define M 1000000
int ans[M + 5];
int arr[M + 5];
void func(){
    for(int i = 2; i <= M; i++){
        if(!arr[i]){
            ans[i] = 1;
            arr[++arr[0]] = i;
        }
        for(int j = 1; j <= arr[0]; j++){
            if(arr[j] * i > M) break;
            arr[arr[j] * i] = 1;
            if(i % arr[j] == 0) break;
        }
    }
}

int cmp(int n){
    int k = floor(log10(n)) + 1;
    for(int i = 1; i <= k; i++){
        if(!ans[n]) return 0;
        int t = n % 10;
        n = n / 10 + t * pow(10, k - 1);
    }
    return 1;
}



int main(){
    int sum = 13;
    func();
    for(int i = 100; i <= M; i++){
        if(cmp(i)) sum++;
    }
    cout << sum << endl;
    return 0;
}
