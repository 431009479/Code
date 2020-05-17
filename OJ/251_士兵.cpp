/*************************************************************************
	> File Name: 251_士兵.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月17日 星期日 20时51分23秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define Max_n 10000 
int x[Max_n + 5];
int y[Max_n + 5];
int w[Max_n + 5];
int n;

int main(){

    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    sort(y, y + n);
    sort(x , x + n);
    for(int i = 0; i < n; i ++) w[i] = x[i] - i;
    sort(w, w + n);
    int sum = 0, cy = y[n / 2], cw = w[n / 2];
    for(int i = 0; i < n; i++){
        sum += abs(y[i] - cy);
        sum += abs(w[i] - cw);
    }
    cout << sum << endl;
    return 0;
}
