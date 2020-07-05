/*************************************************************************
	> File Name: 46.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月13日 星期六 09时50分04秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define M 1000000
int arr[M + 5];
int f[M + 5];
void func(){
    for(int i = 2; i <= M; i++){
        if(!arr[i]){
            arr[++arr[0]] = i;
            f[i] = 1;
        }
        for(int j = 1; j <= arr[0]; j++){
            if(arr[j] * i > M) break;
            arr[arr[j] * i] = 1;
            if(i % arr[j] == 0) break;
        }
    }
}

int soet(int n){
    return 2 * n * n ;
}

int cmp(int l, int r, int x){
    int mid;
    while(l <= r){
        mid = (l + r) >> 1;
        int t = soet(mid);
        if(t == x) return 1;
        if(t > x) r = mid -1;
        else l = mid + 1;
    }
    return 0;
}


int main(){
    func();
    int ans = 0;
    for(int i = 9; i < M; i += 2){
        if(f[i])continue;
        int flag = 1;
        for(int j = 1; j <= arr[0] && arr[j] < i; j++){
            if(cmp(1, i - arr[j], i -arr[j])){
                flag = 0;
                break;
            }
        }
        if(!flag) continue;
        ans = i;
        break;
    }
    cout << ans << endl;
    return 0;
}
