/*************************************************************************
	> File Name: 394.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月02日 星期四 10时36分03秒
 ************************************************************************/

#include<iostream>
using namespace std;


int l1, n, m;
int num[50005] = {0};
int main(){
    cin >> l1 >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }
    num[n + 1] = l1;
    int l = 0, r = l1;
    while(l < r){
        int mid = (l + r + 1) / 2;
        int cnt = 0, lest = 0;
        for(int i = 1; i <= n + 1; i++){
            if(num[i] - lest < mid){
                cnt ++;
            }else{
                lest = num[i];
            }
        }
        if(cnt <= m){
            l = mid;
        }else r = mid - 1;
    }
    
    cout << l;
    return 0;
}
