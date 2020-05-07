/*************************************************************************
	> File Name: 12.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月19日 星期三 12时02分45秒
 ************************************************************************/
 #include <stdio.h>
#include <stdlib.h>
#define M 400000
typedef struct Heap {
    long long  *data, size;
} Heap;

Heap *init(long long length_input) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->data = (long long *)malloc(sizeof(long long) * length_input);
    h->size = 0;
    return h;
}

void swap(long long *a, long long *b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
}

void push(Heap *h, long long value) {
    h->data[h->size] = value;
    long long current = h->size;
    long long father = (current - 1) / 2;
    while (h->data[current] > h->data[father]) {
        swap(&h->data[current], &h->data[father]);
        current = father;
        father = (current - 1) / 2;
    }
    h->size++;
}

void output(Heap *h, long long n) {
    for (long long i = 0; i < n; i++) {
        printf("%lld\n",  h->data[i]);
    }
}

long long top(Heap *h) {
    return h->data[0];
}

void update(Heap *h, long long pos, long long n) {
    long long lchild = 2 * pos + 1, rchild = 2 * pos + 2;
    long long max_value = pos;
    if (lchild <= n && h->data[lchild] > h->data[max_value]) {
        max_value = lchild;
    }
    if (rchild <= n && h->data[rchild] > h->data[max_value]) {
        max_value = rchild;
    }
    if (max_value != pos) {
        swap(&h->data[pos], &h->data[max_value]);
        update(h, max_value, n);
    }
}

void pop(Heap *h) {
    swap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    update(h, 0, h->size);
}

// 请在下面实现堆排序函数 heap_sort
void heap_sort(Heap * h){
    for(long long i = h->size- 1; i >= 1; i--){
	swap(&h->data[i] ,&h->data[0]);
        update(h, 0, i - 1);
    }
}

void clear(Heap *h) {
    free(h->data);
    free(h);
}
long long arr[M];
long long brr[M];
    Heap *heap = init(160000000000);
    
int main() {
    long long n;
    scanf("%lld", &n);
    for (long long i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &brr[i]);
    }
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n; j++){
            push(heap, arr[i] + brr[j]);
        }
    }
    heap_sort(heap);
    output(heap, n);
    clear(heap);
    return 0;
}
