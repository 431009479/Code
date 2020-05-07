/*************************************************************************
	> File Name: 997.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月25日 星期三 19时43分34秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int t, n, h, r, qiu[1005][3];
int low[1005], low_s, up[1005], arr[1005][1005], check[1005];

int func(int n){
    if(up[n]) return 1;
    for(int i = 1; i <= n; i++){
        if(arr[n][i] && check[i] == 0){
            check[i] = 1;
            if(func(i)) return 1;
        }
    }
    return 0;
}

int main(){
    cin >> t;
    while(t--){
        memset(low, 0, 1005 * 4);
        memset(up, 0, 1005 * 4);
        memset(arr, 0, 1005 * 1005 * 4);
        memset(low, 0, 1005 * 4);
        low_s = 0;
        cin >> n >> h >> r;
        for(int i = 1; i <= n; i++){
            cin >> qiu[i][0] >> qiu[i][1] >> qiu[i][2];
            if(qiu[i][2] <= r){
                low[low_s] = i;
                low_s++;
            }
            if(qiu[i][2] + r >= h){
                up[i] = 1;
            }
            for(int j = 1;  j < i; j++){
                int t0 = qiu[i][0] - qiu[j][0];
                int t1 = qiu[i][1] - qiu[j][1];
                int t2 = qiu[i][2] - qiu[j][2];
                if(sqrt(((double)t0 * t0) + (t1 * t1) +( t2 * t2)) <= 2 * r){
                    arr[i][j] = arr[j][i] = 1;
                }
            }
        }
        int flag = 0;
        for(int i = 0; i< low_s; i++){
            if(check[low[i]] == 0){
                check[low[i]] = 1;
                if(func(low[i])) {
                    cout << "Yes" <<'\n';
                    flag = 1; break;
                }
            }
        }
        if(flag == 0) 
        cout << "No" << '\n';
    }

    return 0;
}
