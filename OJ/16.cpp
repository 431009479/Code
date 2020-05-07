/*************************************************************************
	> File Name: 16.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月21日 星期五 21时36分45秒
 ************************************************************************/

#include<stdio.h>
//1 3 5 7 9
#define P(func, args...){\
    printf("%s = %d\n", #func, func(args));\
}
int binary_search1(int *data, int n, int x){
    int l = 0, r = n - 1, mid;
    while(l <= r){
        mid = (r + l) >> 1;
        if(data[mid] == x) return mid;
        if(data[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return - 1;
}
// 111110000
int binary_search2(int *data, int n, int x){
    int l = -1,  r = n -1, mid;
    while(l < r){
        mid = (l + r + 1) >> 1;
        if(data[mid] == x) l = mid;
        else r = mid - 1;
    }
    return l;
}
//0000011111
int binary_search3(int *data, int n, int x){
    int l = 0, r = n, mid;
    while(l < r){
        mid = (l + r) >> 1;
        if(data[mid] == x) r = mid;
        else l = mid + 1; 
    }
    return l == n ? -1 : l;
}



int main(){
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
    int arr3[10] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    P(binary_search1, arr1, 10, 7);
    P(binary_search2, arr2, 10, 1);
    P(binary_search3, arr3, 10, 1);

    return 0;

}
