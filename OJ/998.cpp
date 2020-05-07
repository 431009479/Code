/*************************************************************************
	> File Name: 998.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月25日 星期三 19时11分12秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#include<cmath>
#include<cstring>
int add(int num1, int num2){
    if(num2 == 0)
        return num1;
    int sum = num1 ^ num2;
    int carry = (num1 & num2) << 1;
    return add(sum, carry);
}

int substract(int num1, int num2){
    int subtractor = add(~num2, 1);// 先求减数的补码（取反加一）
    int result = add(num1, subtractor); // add()即上述加法运算　　
    return result ;
}

int divide(int a,int b) {   
    int dividend = a > 0 ? a : add(~a, 1);    
    int divisor = b > 0 ? a : add(~b, 1);    
    int quotient = 0;// 商    
    int remainder = 0;// 余数    
    for(int i = 31; i >= 0; i--) {
        if((dividend >> i) >= divisor) {            
            quotient = add(quotient, 1 << i);            
            printf("%d\n", quotient);
            dividend = substract(dividend, divisor << i);        
        }    
    }    
    if((a ^ b) < 0){
        quotient = add(~quotient, 1);    
    }    
    remainder = b > 0 ? dividend : add(~dividend, 1);    
    return quotient;
}

int main() {
    int  a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", divide(a, b));
}
