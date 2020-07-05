/*************************************************************************
	> File Name: 9.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月12日 星期五 16时26分54秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int ans;
    for(int i = 1; i <= 33; i++){
        for(int j = i + 1; i * i + j * j < 1000; j++){
            if(gcd(i, j) - 1) continue;
            int a = 2 * i * j;
            int b = j * j - i * i;
            int c = j * j + i * i;
            if(1000 % (a + b + c) == 0){
                int k = 1000 / (a + b + c);
                ans = a * b * c * pow(k, 3);
                cout << ans << '\n';
                return 0;
            }
        }
    }
    return 0;
}
