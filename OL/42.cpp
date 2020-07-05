/*************************************************************************
	> File Name: 42.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月13日 星期六 10时26分03秒
 ************************************************************************/

#include<iostream>
#include"./42.txt"
using namespace std;

int cmp(int n){
    return (n + 1) * n / 2;
}


int func(int l, int r, int x){
    int mid;
    while(l <= r){
        mid = (l + r) >> 1;
        int t = cmp(mid);
        if(t == x) return 1;
        if(t > x) r = mid- 1;
        else l = mid + 1;
    }
    return 0;
}



int sik(char *str){
    int sum = 0;
    for(int i = 0; str[i]; i++){
        sum += (str[i] - 'A' + 1);
    }
    return func(1, sum, sum);
}



int main(){
    int ans = 0;
    int n = sizeof(str) / 100;
    for(int i = 0; i < n; i++){
        if(sik(str[i])){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
