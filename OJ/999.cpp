#include<iostream>
using namespace std;


long long  n, m, num[1000005], mmax, sum;


long long fun(long long mid){
    long long k = 0, now = 0;
    for(int i = 0; i < n; i++){
        if(k + num[i] ==  mid){
            now++;
            k = 0;
        }else if(k + num[i] > mid){
            now++;
            k = num[i];
        }else{
            k += ans[i];
        }
    }
    if(k > 0) now++;
    return now;
}

long long func(){
    long long l = mmax, r = sum;
    while(l != r){
        long long mid = (l + r) / 2;
        if(fun(mid) > m){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    return l;
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        sum += num[i];
        mmax = max(mmax, num[i]);
    }
    cout << func();

    
    return 0;
}
