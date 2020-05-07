/*************************************************************************
	> File Name: 堆.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月18日 星期二 15时37分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Heap{
    int *data;
    int length, size;
}Heap;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

Heap *init( int n){
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->data = (int *)malloc(sizeof(int) * (n + 1));
    h->length = 0;
    h->size = n;
    return h;
}

int push(Heap *h, int val){
    if(h == NULL) return 0;
    if(h->size == h->length) return 0;
    h->length++;
    h->data[(h->length)] = val;
    int ind = h->length, fal = ind / 2;
    while(fal != 0 && h->data[ind] > h->data[fal]){
        swap(&(h->data[ind]), &(h->data[fal]));
        ind = fal;
        fal = ind / 2;
    }
    return 1;
}

int empty(Heap *h){
    return h->length == 0;
}

int pop(Heap *h){
    if(h == NULL) return 0;
    if(empty(h)) return 0;
    h->data[1] = h->data[h->length--];
    int ind = 1;
    while((ind << 1) <= h->length){
        int temp = ind, l = ind * 2, r = ind * 2 + 1;
        if( h->data[l] > h->data[temp]) temp = l;
        if(r <= h->length && h->data[r] > h->data[temp]) temp = r;
        if(temp == ind) break;
        swap(&(h->data[temp]),&(h->data[ind]));
        ind = temp;
    }
    return 1;
}

int top(Heap *h){
    return h->data[1];
}

void clear(Heap *h){
    if(h == NULL) return;
    free(h->data);
    free(h);
    return;
}

int main(){
    srand(time(0));
    #define max_op 20
    int op, val;
    Heap *h = init(max_op);
    for(int i = 0; i < max_op; i++){
        int val = rand() %100;
        push(h, val);
        printf("insert %d to queue\n", val);
        
    }
    for(int i = 0; i < max_op; i++){
        printf("%d ", top(h));
        pop(h);
    }
    printf("\n");
    clear(h);
    return 0;
}
