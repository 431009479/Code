/*************************************************************************
	> File Name: 15.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月12日 星期五 18时35分23秒
 ************************************************************************/

#include<iostream>
using namespace std;



long long sum = 1, n = 40, m = 20;
int main(){
    while(n > 20){
        sum *= (n--);
        while(m && sum % m == 0){
            sum /= (m--);
        }
    }
    

    cout << sum << endl;
    return 0;
}
