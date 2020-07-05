/*************************************************************************
	> File Name: 36.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月08日 星期一 12时34分31秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define M 1000000

int sum = 0;


int func(int n, int t){
    int m = n, k = 0;
    while(m){
        k = k * t + m % t;
        m /= t;
    }
    return k == n;
}



int main(){
    for(int i = 1; i <= M; i++){
        if(func(i, 2) && func(i, 10)){
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}
