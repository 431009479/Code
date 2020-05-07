/*************************************************************************
	> File Name: 502_求和1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月01日 星期五 20时05分44秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define INF 0x3f3f3f3f
#define M 1000000

struct node{
    int val, abs;
}arr[M + 5];

int cmp(node a, node b){
    return a.abs < b.abs; 
}

int main(){
    int n, m;
    int ans = INF;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i].val;
        arr[i].abs = abs(arr[i].val);
    }
    sort(arr, arr + n, cmp);
    for(int i = 1; i < n; i++){
        ans = min(ans, abs(arr[i].val - arr[i - 1].val));
    }
   cout << ans; 
    return 0;
}
