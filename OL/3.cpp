/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月08日 星期一 09时34分27秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 600851475143LL


long long  i = 2, ans, M = N;
int main(){
    while ( i * i <= M){
        if(M % i == 0) ans = i;
        
        while(M % i == 0){
            M /= i;
        }
        i++;
    }
    if(M > 1) ans = M;
    cout << ans;
    return 0;
}
