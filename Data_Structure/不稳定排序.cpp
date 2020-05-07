/*************************************************************************
	> File Name: 不稳定排序.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月20日 星期四 18时15分32秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
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
void select_sort(int *data, int n){
    for(int i = 0; i < n- 1; i++){
        int ind = i;
        for(int j = i + 1; j < n; j++){
            if(data[ind] > data[j]) ind = j;
        }
        swap(data[ind], data[i]);
    }
}
void quick_sort(int *data, int l, int r){
    while(l < r){
        int x = l, y = r, z = data[(l + r) >> 1];
        do{
            while(x < y && data[x] < z) x++;
            while(x < y && data[y] >= z) y--;
            if(x <= y){
                swap(data[x], data[y]);
                x++, y--;
            }
        }while(x <= y);
        quick_sort(data, x ,r);
        r = y;
    }
}


/*void quick_sort(int *data, int l, int r){
    if(r < l) return ;
    int x = l, y = r, z = data[l];
    while(x <= y){
        while(x <= y && data[y] >= z) y--;
        if(x < y) data[x++] = data[y];
        while(x <= y && data[x] <= z) x++;
        if(x < y) data[y--] = data[x];
       // if(x <= y) {swap(data[x], data[y]); x++, y--;}
    }
    data[x] = z;
     quick_sort(data, l, x);
    quick_sort(data, x + 1, r);
    return ;
}*/

void output(int *data, int n){
    printf("[");
    for(int i = 0; i < n; i++){
        printf("%d ", data[i]);
    }
    printf("]\n");
}


void randint(int *arr, int n){
    while(n--) arr[n] = rand() % 100;
}
int main(){
    srand(time(0));
    #define max_op 20
    int arr[max_op];
    randint(arr, max_op);
    TEST(arr, max_op, select_sort, data, max_op);

    TEST(arr, max_op,quick_sort, data, 0, max_op -1);


    return 0;
}
