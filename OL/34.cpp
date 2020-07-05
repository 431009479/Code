/*************************************************************************
	> File Name: 34.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月08日 星期一 11时41分55秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define M 230000 // 最多六位数， 每一位是9

int cmp(int n){
    if(n == 0) return 1; //0的阶乘是1
    if(n == 1) return 1;
    return n * cmp(n - 1);
}


int func(int n){
    int m = n , k = 0;

    while(m){
        k += cmp(m % 10);
        m /= 10;
    }
    return k == n;
}

long long sum = 0;
int main(){
    
    for(int i = 3; i < M; i++){
        if(func(i)) sum += i;
    }
    cout << sum;
    return 0;
}
