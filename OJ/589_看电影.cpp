/*************************************************************************
	> File Name: 589_看电影.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 18时43分11秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;


int gcd(int a, int b){
    if(b == 0) return a;
    return  gcd(b, a % b);
}

int main(){
    int n, k, id;
    cin >> n >> k >> id;
    if(k == n) {cout << "1/1"; return 0;}
    if(k == 0 && n != 0) {cout << "0/1"; return 0;}
    int a =gcd(n, k);
    cout << k / a <<"/" << n / a;
    return 0;
}
