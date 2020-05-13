/*************************************************************************
	> File Name: 509_智力大冲浪.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 21时02分40秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int t, q;
};

int m, n;
int  ans[1000000] = {1};
node arr[505];

int cmp(node a, node b){
    if(a.q == b.q) return a.t < b.t;
    return a.q > b.q;
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i].t;
    }
    for(int i = 0; i < n; i++){
        cin >> arr[i].q;
    }
    sort(arr, arr + n, cmp);
    
    for(int i = 0; i < n; i++){
        for(int j = arr[i].t; j >= 0; j--){
                if(ans[j] == 0){
                    ans[j] = 1;
                    break;
            }
            if(j == 0) m -= arr[i].q;
        }
    }

        cout << m;
    return 0;
}
