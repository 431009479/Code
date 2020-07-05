/*************************************************************************
	> File Name: 26.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月13日 星期六 11时18分05秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
#define M 1000


int arr[M + 5] = {0};

int get(int d){
    int r = 1, t = 0;
    while(r){
        r *= 10;
        r %= d;
        t += 1;
        if(arr[r]) return t - arr[r];
        arr[r] = t;
    }
    return 0;
}    


int main(){
    int ans = 0, d = 0;
    for(int i = 2; i < M; i++){
        memset(arr, 0, sizeof(arr));
        int t = get(i);
        if(t > ans){
            d = i;
            ans = t;
        }
    }
    cout << d << " " << ans << endl;

    return 0;
}
