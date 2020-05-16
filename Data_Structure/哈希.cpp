/*************************************************************************
	> File Name: 哈希.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月16日 星期六 19时21分47秒
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}


int main(){
    unordered_map<double, int> h;
    h[2.3] = 123;
    h[345.6] = 123456;
    cout << h[2.3] << endl;
    cout << h[345.6] << endl;


    return 0;
}
