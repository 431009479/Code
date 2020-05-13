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
    return a.y < b.y;
}


int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i].y >> arr[i].c;
    }
    sort(arr, arr + n, cmp);
    int sum = 0;
    for(int i = 0; i < n - 1; i++){
        sum += arr[i].y;
    }

    cout << sum - arr[n - 1].c;
    return 0;
}
