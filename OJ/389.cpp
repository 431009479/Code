/*************************************************************************
	> File Name: 389.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月08日 星期三 20时52分43秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;


int n, m, k;
int ans[100005];

int fun(int mid){
    int k = 1, now = 0;
    for(int i = 1; i < n; i++){
        if(ans[i] - ans[now] >= mid){
            k++;
            now = i;
        }
    }
    return k;
}



int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> ans[i];
    }
    sort(ans, ans + n);
    int l = 0, r = ans[n - 1], mid;
    while(l != r){
        mid = (l + r + 1) / 2;
        if(fun(mid) >= m){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}

