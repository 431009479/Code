/*************************************************************************
	> File Name: 505_最大整数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 18时56分08秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int cop(string a, string b){
	return  (a + b) > (b + a); 
}
int main(){
	int n;
	cin >> n;
	string str[100000];
	for(int i = 0; i < n; i++)
			cin >> str[i];
	sort(str, str + n, cop);
	for(int i = 0; i < n; i++)
			cout << str[i];
	return 0;
}
