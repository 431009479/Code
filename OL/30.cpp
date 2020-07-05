/*************************************************************************
	> File Name: 30.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月08日 星期一 11时29分50秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
#define M 1000000

long long sum = 0;

int func(int n){
    int m = n, k = 0;
    while(m){
        k += pow(m % 10, 5);
        m /= 10;
    }
    return n == k;
}



int main(){
    for(int i = 2; i < 1000000; i++){
        if(func(i)) sum += i;
    }
    cout << sum << endl;
    return 0;
}
