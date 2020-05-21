/*************************************************************************
	> File Name: 599_两数之和1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月20日 星期三 21时38分54秒
 ************************************************************************/

#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;


struct node{
    int x, val;
};
node arr[1000005];
long long n, t;



int cmp(node a,node b){
    return a.val < b.val;
}

int main(){
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        cin >> arr[i].val;
        arr[i].x = i;
    }
    sort(arr, arr + n, cmp);
    int l = 0, r = n - 1;
    while(l < r){
        long long sum = arr[l].val + arr[r].val;
        if(sum == t){
            cout << arr[l].x << " "<< arr[r].x;
            return 0;
        }else if(sum > t) r--;
        else l++;
    }
    return 0;
}
