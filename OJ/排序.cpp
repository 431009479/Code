/*************************************************************************
	> File Name: 排序.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月21日 星期五 20时53分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define swap(a, b){\
    __typeof(a) __p = a;\
    a = b; b = __p;\
}

#define TEST(arr, n, func, args...){\
    int *data = (int *)malloc(sizeof(int) * n);\
    memcpy(data, arr, sizeof(int) * n);\
    output(data, n);\
    printf("%s = ", #func);\
    func(args);\
    output(data, n);\
    free(data);\
}
void fun(int *data, int l, int r){
    if(r - l <= 1){
        if(r - l == 1 && data[l] > data[r]) {swap(data[l], data[r]);}
    return ;
    }
    int mid = (r + l) >> 1;
    fun(data, l, mid);
    fun(data, mid + 1, r);
    int p1 = l, p2 = mid + 1, k = 0;
    int *temp = (int *)malloc(sizeof(int) *(r - l + 1));
    while(p1 <= mid || p2 <= r){
        if(p2 > r ||(p1 <= mid && data[p1] <= data[p2]))
        temp[k++] = data[p1++];
        else temp[k++] = data[p2++];
    }
    memcpy(data + l, temp, sizeof(int) *(r - l + 1));
    free(temp);
}
void cmp(int *data, int l, int r){
    if(r < l) return ;
    int x = l, y = r, z = data[l];
    while(x < y){
        while(x < y && data[y] >= z) y--;
        if(x < y) data[x++] = data[y];
        while(x < y && data[x] <= z) x++;
        if(x < y) data[y--] = data[x];
    }
    data[x] = z;
    cmp(data, l, x - 1);
    cmp(data, x + 1, r);
}


void randint(int *arr, int n){
    while(n--)arr[n] = rand() % 100;
}


void output(int *data, int n){
    printf("[");
    for(int i = 0; i < n; i++){
        printf("%d ", data[i]);
    }
    printf("]\n");
}



int main(){
    srand(time(0));
    #define max_op 20
    int arr[max_op];
    randint(arr, max_op);
    TEST(arr, max_op, fun, data, 0, max_op - 1);
    TEST(arr, max_op, cmp, data, 0, max_op - 1);
    return 0;
}

