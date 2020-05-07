/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月17日 星期一 13时33分07秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Queue{
    int *data;
    int head, tail, size, cnt;
}Queue;

Queue *init(int n){
    Queue *q = (Queue *)malloc(sizeof (Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->head = 0; 
    q->tail = 0;
    q->cnt = 0;
    q->size = n;
    return q;
}

int empty(Queue *q){
    return q->cnt == 0;
}
int front(Queue * q){
    return q->data[q->head];
}
int push(Queue *q, int val){
    if(q==NULL) return 0;
    if(q->cnt == q->size) return 0;
    q->data[q->tail++] = val;
    if(q->tail == q->size) q->tail -= q->size;
    q->cnt++;
    return 1;
 }

int pop(Queue *q){
    if(q == NULL) return 0;
    if(empty(q)) return 0;
    q->head ++;
    if(q->head == q->size) q->head -= q->size;
    q->cnt--;

    return 1;
 }
void output(Queue * q){
    printf("Queue(%d) = [", q->cnt);
    for(int i = q->head, j = 0; j < q->cnt ;j++){
        i != j && printf(" ,");
        printf("%d", q->data[i + j] % q->size);
    }
    printf("]\n");
}

void clear(Queue * queue){
    free(queue ->data);
    free(queue);
    return;
}




int main(){
        srand(time(0));
    #define max_op 20
    int val, op;
    Queue *q = init(max_op);
    for(int i = 0; i < max_op * 2; i++){
        op = rand() % 4;
        val = rand() % 100;
        switch(op){
            case 0:
            case 1:
            case 2:{
                printf("push %d to Queue = %d\n",val, push(q, val));
            }break;
            case 3:{
                printf("pop %d to Queue = %d\n", pop(q));
            }break;
        }
        output(q);
        printf("\n");
    }
    clear(q);
    return 0;
}
