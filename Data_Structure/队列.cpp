/*************************************************************************
	> File Name:循环队列.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月13日 星期四 18时07分52秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Queue{
    int *data;
    int head, tail, size, k;
}Queue;

Queue *init(int n){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->size = n;
    q->head = 0;
    q->tail = 0;
    q->k = 0;
    return q;
}

int empty(Queue *q){
    return q->k == 0;
}

int frout(Queue *q){
    return q->data[q->head];
}

int expand(Queue *q){
    int ex_size = q->size;
    int *p;
    while(ex_size){
        p = (int *)malloc(sizeof(int) *(q->size + ex_size));
        if(p)break;
        ex_size /= 2;
    }
    if(p ==NULL) return 0;
    for(int i = q->head, j = 0; j < q->k; j++){
       p[j] = q->data[(i + j) % q->size];
    }
    q->size += ex_size;
    q->head = 0;
    q->tail = q->k;
    free(q->data);
    q->data = p;
    return 1;
}

int push(Queue *q, int val){
    if(q == NULL) return 0;
    if(q ->k == q->size){
        if(!expand(q))return 0;
            printf("expand successflu size = %d\n", q->size);
    }
        if(q->tail==q->size) q->tail -= q->size;
        q->data[q->tail++] = val;
        q->k++;
    return 1;
}

int pop(Queue *q){
    if(q == NULL) return 0;
    if(empty(q)) return 0;
    q->head++;
    if(q->head == q->size) q->head -=q->size;
    q->k--;
    return 1;
}

void output(Queue *q){
    printf("Queue(%d) = [", q->k);
    for(int i = q -> head, j = 0; j < q->k; j++){
        j && printf(", ");
        printf("%d", q->data[(i + j) % q->size]);
    }
    printf("]\n");
}
void clear(Queue *q){
    if(q == NULL) return ;
    free(q-> data);
    free(q);
    return ;
}

int main(){
    srand(time(0));
    #define max_op 20
    Queue *q = init(1);
    int op, val;
    for(int i = 0; i < max_op; i++){
        op = rand() % 4;
        val = rand() % 100;
        switch(op){
            case 0:
            case 1:
            case 2:{
                printf("push %d to Queue = %d\n",val, push(q, val));
            }break;
            case 3:{
                printf("pop %d to Queue = %d\n",frout(q), pop(q));
            }break;
        }
        output(q);
        printf("\n");
    }
        clear(q);
    return 0;
}

