/*************************************************************************
	> File Name: 栈.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月13日 星期四 20时14分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int *data;
    int top, size;
}
Stack *init (int n){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) *n);
    s->top = -1;
    s->size = n;
    return s;
}

int empty (Stack *s){
    return s->top == -1;
}
int top(Stack *s){
    return s->data[s->top];
}
void fun(Stack *s){
    int *k;
    int n = s->size;
    s->size *= 2;
    while(n){
        k =(int *) realloc(sizeof(int) *(s-> data, s->size + n))
        if(k) break;
        n /= 2;}
        if(p == NULL) return 0;
        s->size += n;
        s_>data = p;
        return 1;
}
int push(Stack *s, int val){
    if(s == NULL) return 0;
    if(s->top + 1 == s ->size)
       if(!fun(s)) return 0;
    s->data[++s->top] = val;
    return 1;
}
int pop(Stack *q){
    if(s == NULL) return 0;
    if(empty(s)) return 0;
    s->top--;
    return 1;
}
void output(Stack *s){
    printf("Stack(%d) = [", s->top + 1);
    
    for(int i = 0; i <= s->top; i++){
        i != 0 && printf(" ");
        printf("%d",q->data[i]);
    }
    printf("]\n");
    return ;
}

void clear(Stack *s){
    if(s== NULL) return ;
    free(s->data);
    free(s);
    return ;
}
int main(){
    srand(time(0));
    #define max_op 20
    Stack *s = init(max_op);
    int val, op;
    for(int i = 0; i < max_op; i++){
    op = rand() % 4 ;
    val = rand() % 100;
        switch(op){
            case 0:
            case 1:
            case 2:{printf("push %d to Stack = %d\n", val, push(s, val));
            }break;
            case 3: {
                int tmp = top(s);
                printf("pop %d from Stack = %d\n",tmp, pop(s));
            }break;
        }
        output(s);
        printf("\n");
    }
    clear(s);
    return 0;
}
