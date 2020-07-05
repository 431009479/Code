/*************************************************************************
	> File Name: 44.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月12日 星期五 09时34分29秒
 ************************************************************************/
#include<iostream>
#include <stdio.h>
#include <inttypes.h>
using namespace std;
typedef long long int1;

int1 pentagonal(int1 n) {
    return n * (3 * n - 1) / 2;
}

int1 is_Pentagonal(int1 x, int1 n) {
    int1 head = 1, tail = n, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (pentagonal(mid) == x) return 1;
        else if (pentagonal(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int main() {
    int1 i = 1, j = 1, ans = INT32_MAX;
    while (pentagonal(j + 1) - pentagonal(j) < ans) {
        j += 1;
        i = j - 1;
        for (int i = j - 1; i >= 1 && pentagonal(j) - pentagonal(i) < ans; i--) {
            if (!is_Pentagonal(pentagonal(j) + pentagonal(i), 2 * j)) continue;
            if (!is_Pentagonal(pentagonal(j) - pentagonal(i), 2 * i)) continue;
            printf("%lld->%lld\n", pentagonal(j), pentagonal(i));
            ans = pentagonal(j) - pentagonal(i);
        }
    }
    cout << ans << '\n';
    return 0;
}
