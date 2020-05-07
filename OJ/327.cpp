/*************************************************************************
	> File Name: 327.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月26日 星期日 19时19分43秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define M 20000
int fa[M + 5], val[M + 5];


void init(int n){
    for(int i = 1; i <= n; i++){
        fa[i] = i;
        val[i] = 0;
    }
    return 0;
}


int get(int x){
    if(x == fa[x]) return x;
    int root = get
}

int main(){
    int n, m;
    cin >> n >> m;
    init(n);
    for(int i = 0; i < m; i++){
        cin >> arr[i].x >> arr[i].y >> arr[i].c;
    }
    sort(arr, arr + m. cmp);
    arr[m].x = 


    return 0;
}
