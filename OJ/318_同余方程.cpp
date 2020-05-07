/*************************************************************************
	> File Name: 318_同余方程.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月03日 星期日 00时59分01秒
 ************************************************************************/

#include<iostream>
using namespace std;

long long ex_gcd(long long a, long long b, long long &x, long long &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    long long ret = ex_gcd(b, a % b, y, x);
     y -= a / b * x;
    return ret;
}


int main(){
    long long a, b, x, y;
    cin >> a >> b;

    ex_gcd(a, b, x, y);
    cout << (x % b + b) % b;
    return 0;
}
