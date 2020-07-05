/*************************************************************************
	> File Name: 5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月08日 星期一 12时56分18秒
 ************************************************************************/

#include<iostream>
using namespace std;


int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}


int sum = 2520;

int main(){
    for(int i = 10; i <= 20; i++){
        if(sum % i == 0) continue;
       sum *= i / gcd(sum , i);
    }

    cout << sum << endl;
    return 0;
}
