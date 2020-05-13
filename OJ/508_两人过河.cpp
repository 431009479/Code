/*************************************************************************
	> File Name: 508.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 19时07分43秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	
	int n, k, sum = 0;
	cin >> n;
	int a[1001];
	for(int i = 0 ; i < n; i++){
		cin >> a[i];
	} 
	sort(a, a + n);
	while(n){
		if(n == 1) {sum += a[0]; break;}
		if(n == 2) {sum += a[1]; break;}
		if(n == 3) {sum += a[0] + a[1] + a[2]; break;}
        //两种过河方法， 1、最快加次快； 2 、最慢加最快。
		sum +=  min(a[0] + 2 * a[1] + a[n - 1], 2 * a[0] + a[n - 1] + a[n - 2]);
		n -= 2;
	}
	cout << sum;
	return 0;
}
