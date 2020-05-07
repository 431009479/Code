/*************************************************************************
	> File Name: 392.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月22日 星期三 18时49分52秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;



long long A, B, num[100005];


int func(int mid){
    int cnt = 1, now = 0;
    for(int i = 1; i < n; i++){
        if(num[i] - num[now] >= mid){
            cnt++;
            now = i;
        }
    }
    retunr cnt;
}


int main(){
    cin >> A >> B;
    for(int i = 0; i < A; i++){
        cin >> num[i];
    }

    sort(num[i], num[i] + A);
    int l = 0, r = num[A - 1] - num[0];
    while(l != r){
        int mid = (l + r + 1) / 2;
        if(func(mid) > B){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}
