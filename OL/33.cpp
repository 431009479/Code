/*************************************************************************
	> File Name: 33.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月09日 星期二 14时25分10秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;




int func(int x, int y){
    

    int x1, x2, y1, y2;
    x1 = x / 10; x2 = x % 10;
    y1 = y / 10; y2 = y % 10;
    if (!(x1 && x2 && y1 &&y2)) return false;
    if (x1 == y1 && x2 * y == y2 * x) return true;
    if (x1 == y2 && x2 * y == y1 * x) return true;
    if (x2 == y2 && x1 * y == y1 * x) return true;
    if (x2 == y1 && x1 * y == y2 * x) return true;
    return false;
}


int main(){
    int x = 1, y = 1, c;
    for(int i = 10; i < 100; i++){
        for(int j = i + 1; j < 100; j++){
            if(!func(i, j)) continue;
            cout << i << " " << j << endl;
            x *= i, y *= j;
            c = __gcd(x, y);
            x /= c, y /= c;
        }
    }

    cout << y << '\n';
    return 0;
}
