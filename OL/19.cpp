/*************************************************************************
	> File Name: 19.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月15日 星期一 18时31分07秒
 ************************************************************************/

#include<iostream>
using namespace std;

 
int WhichDay(int y, int m, int d){
    if (m == 1 || m == 2) {
        --y; m += 12;
    }

    int w;
    w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    return w;
}

int main() {
    int sunday = 0;
    for (int y = 1901; y < 2001; ++y) {
        for (int m = 1; m <= 12; ++m) {
            if (WhichDay(y, m, 1) == 6)
                    ++sunday;
        }
    }
    printf("%d\n", sunday);
    return 0;

}
