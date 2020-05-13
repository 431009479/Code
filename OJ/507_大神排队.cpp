/*************************************************************************
	> File Name: 507_大神排队.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 18时57分15秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int y, c;
};


int n;
node arr[50005];

int cmp(node a, node b){
    if(a.y + a.c == b.y + b.c)return a.y < b.y;
    return a.y + a.c < b.y + b.c;
}


int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i].y >> arr[i].c;
    }
    sort(arr, arr + n, cmp);
    int sum = 0, ans = -99999999;
    for(int i = 0; i < n; i++){
        ans = max(ans, sum - arr[i].c);
        sum += arr[i].y;
    }

    cout << ans;
    return 0;
}
