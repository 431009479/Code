/*************************************************************************
	> File Name: 271.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月28日 星期二 14时23分27秒
 ************************************************************************/


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define MAX_N 300000
int arr[MAX_N + 5];
int q[MAX_N + 5], head, tail;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    head = tail = 0;
    for (int i = 0; i < n; i++) {
        while (tail - head && arr[i] < arr[q[tail - 1]]) tail--;
        q[tail++] = i;
        cout <<"q[tail] = "<< tail - 1 <<" " << q[tail - 1];
        if (i + 1 < k) continue;
        if (i - q[head] == k) head++;
        i + 1 == k || cout << " ";
        cout << "head =" << head << ", tail =" << tail << endl;
        cout << arr[q[head]];
    }
    cout << endl;
    head = tail = 0;
    for (int i = 0; i < n; i++) {
        while (tail - head && arr[i] > arr[q[tail - 1]]) tail--;
        q[tail++] = i;
        if (i + 1 < k) continue;
        if (i - q[head] == k) head++;
        i + 1 == k || cout << " ";
        cout << arr[q[head]];
    }
    cout << endl;
    return 0;
}
