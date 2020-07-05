/*************************************************************************
	> File Name: 45.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月12日 星期五 16时03分18秒
 ************************************************************************/

#include<iostream>
using namespace std;

long long P(long long n){
    return n * (2 * n - 1);
}

long long  K(long long n){
    return n * (3 * n - 1) / 2;
}



 int func(int l, int r, long long x){

     int mid;
    while(l <= r){
        mid = (l + r) >> 1;
         int t = K(mid);
        if(t == x) return 1;
        if(t > x) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}


int main(){
     int n = 144;
    while(func( n / 2, 2 * n, P(n)) == 0) n++;
    
    cout << P(n) << endl;
    return 0;
}
