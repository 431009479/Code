/*************************************************************************
	> File Name: 8.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月08日 星期一 16时25分27秒
 ************************************************************************/

#include<iostream>
#include"8.h"
using namespace std;


int main(){
    long long sum = 0, p = 1, z = 0;
    for(int i = 0; i < 1000; i++){
        arr[i] -= '0';
        if(arr[i]) {
            p *= arr[i];
        }else{
            z++;
        }
        
        if(i < 13) continue;
        if(arr[i - 13]) {
            p /= arr[i - 13];
        }else {
            z--;
        }
        if(z == 0 && p > sum){
            sum = p;
        }
    }
    cout << sum;
    return 0;
}

