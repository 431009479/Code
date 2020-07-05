/*************************************************************************
	> File Name: 32.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月09日 星期二 08时59分21秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
long long sum;


int ans[100000] = {0};
int arr[10] = {1};

int cmp(int n){
    while(n){
        if(arr[n % 10]) return 0;
        arr[n % 10] = 1;
        n /= 10;
    }
    return 1;
}

int Floot(int n){
    return floor(log10(n)) + 1;
}

void ARR(){
    for(int i = 0; i < 10; i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    return ;
}

int func(int x, int y){
    if(Floot(x) + Floot(y) + Floot(x * y) != 9) 
        return 0;
    int flat = 1;
    flat = flat && cmp(x);
    flat = flat && cmp(y);
    flat = flat && cmp(x * y);
    ARR();
    return flat;
}

int main(){
    for(int i = 1; i < 100; i++){ // i 的上限是二位数
        for(int j = i + 1; j < 10000; j++){ // j 的上限是四位数
            if(func(i, j) && ans[i * j] == 0){
                ans[i * j] = 1;
                sum += i * j;
            }
        }
    }
    
    cout << sum;
    return 0;
}
