/*************************************************************************
	> File Name: 390.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月08日 星期三 20时27分14秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;


int n, m, k;
int mmap[100005];
int ans[100005];

int fun(int mid){
    int k = 0;
    for(int i = 0; i < n; i++){
        k += ans[i] / mid;
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
