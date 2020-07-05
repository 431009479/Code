/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月08日 星期一 09时39分13秒
 ************************************************************************/

#include<iostream>
using namespace std;


int func(int n){
    int m = n, k = 0;
    while(m){
        k = k * 10 + m % 10;
        m /= 10;
    }

    return k == n ? 1 : 0;
}





int sum = 0;
int main(){
    for(int i = 100; i < 1000; i++){
        for(int j = 100; j < 1000; j++){
            if(func (i * j)){
               sum =  max(sum, i * j);
            }
        }
    }
    cout << sum;
    return 0;
}
