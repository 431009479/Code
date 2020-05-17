/*************************************************************************
	> File Name: 245_货仓选址.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月17日 星期日 19时17分54秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


int main(){
    int n;
    cin >> n;
    int arr[100005];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr,arr + n);
    int pos = arr[n / 2];
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += abs(arr[i] - pos);
    }

    cout << sum;
    return 0;
}
