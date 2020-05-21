/*************************************************************************
	> File Name: 570_排队.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月21日 星期四 00时46分45秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

struct node{
    long long num, cnt;
};


long long n, num[80005], ans[80005] = {0}, all = 0;

int main(){
    cin >> n;
    for(long long i = 0; i < n; i++){
        cin >> num[i];
    }
    stack<node> sta;
    sta.push({2100000000, -1});
    for(long long i = n - 1; i >= 0; i--){
        while(sta.top().num < num[i]){
            node temp = sta.top();
            sta.pop();
            ans[i]++;
            ans[i] += ans[temp.cnt];
        }
        all += ans[i];
        sta.push({num[i], i});
    }
    cout << all<< endl;

    return 0;
}
