/*************************************************************************
	> File Name: 14.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月21日 星期五 19时52分26秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define  swap(a, b){\
    a ^= b; b ^= a; a ^= b;\
}
#define TEST(arr, n, func, args...){\
    int *data = (int *) malloc(sizeof(int) * n);\
    memcpy(data, arr, sizeof(int) *n);\
    printf("%s = ", #func);\
    output(data, n);\
    func(args);\
    output(data, n);\
    free(data);    }

void insert(int *data, int n){
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0 && data[j] < data[j -1]; j--){
            swap(data[j], data[j -1]);
        }
    }
    return ;
}
void bubble_sort(int *data, int n){
    int k;
    for(int i = 1; i < n; i++){
        k = 0;
        for(int j = 0; j < n - i; j++){
            if(data[j] > data[j + 1]){
                k = 1;
                swap(data[j], data[j + 1]);
            }
        }if(k == 0) break;
    }
    return ;
}


void merge_sort(int *data, int l, int r){
    if(r - l <= 1){
        if(r - l == 1 && data[l] > data[r]){
            swap(data[l], data[r]);
        }
        return ;
    }
    int mid = (l + r) >> 1;
    merge_sort(data, l, mid);
    merge_sort(data, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while(p1 <= mid || p2 <= r){
        if(p2 > r || (p1 <= mid && data[p1] <= data[p2]))
            temp[k++] = data[p1++];
        else temp[k++] = data[p2++];
    }
    memcpy(data + l, temp, sizeof(int) *(r - l + 1));
    free(temp);
    return;

}
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
    TEST(arr, max_op, insert, data, max_op);
    TEST(arr, max_op, bubble_sort, data, max_op);
    TEST(arr, max_op, merge_sort, data, 0, max_op - 1);
    return 0;
}
