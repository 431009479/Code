/*************************************************************************
	> File Name: 386.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月08日 星期三 19时39分41秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;


struct node{
    int num, val;
};

bool cmp(node a, node b){
    return a.val > b.val;
}

node wm[100005]; 
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> wm[i].val;
        wm[i].num = i + 1;
    }
    sort(wm, wm + n, cmp);
    for(int i = 0; i < m; i++){
        int t;
        int l = 0, r = n - 1, f = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(wm[mid].val == t){
                cout << wm[mid].num << '\n';
                f = 1;
                break;
            }if(wm[mid].val < t){
                l = mid + l;
            }else{
                r = mid + 1;
            }
        }
        if(f == 0){
            cout << 0 << '\n';
        }
    }


    return 0;
}
