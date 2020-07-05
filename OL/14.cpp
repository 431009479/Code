/*************************************************************************
	> File Name: 14.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月08日 星期一 20时01分18秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define M 1000000
int arr[M + 5];

long long func(long long n){
    if(n == 1) return 1;
    if(n < M && arr[n]) return arr[n];
    int ret;
    if(n & 1){
        ret = func(3 * n + 1) + 1;
    }else{
        ret = func(n >> 1) + 1;
    }
    if(n < M) arr[n] = ret;
    return ret;
}



int main(){
    int sum = 0, ans = 0;    
    for(int i = 1; i < M; i++){
        int tem = func(i);
        if(tem > sum){
            sum = tem;
            ans = i;
        }
    }
    printf("%d %d\n", sum , ans);
    return 0;
}
