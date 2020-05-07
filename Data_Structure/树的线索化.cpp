/*************************************************************************
	> File Name: 树的线索化.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 19时03分04秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 0
#define T 1


typedef struct Node{
    int data;
    struct Node *l, *r;
    int ltag, rtag;
}Node;

Node *getNewNode(int val){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data =val;
    p->l = p->r = NULL;
    p->ltag = p->rtag = N;
    return p;
}

Node *insert(Node *root, int val){
    if(root == NULL) return getNewNode(val);
    if(root ->data == val) return root;
    if(val < root ->data)root->l = insert(root->l, val);

    return root;
}

void build_thread(Node *root){
    if(root == NULL) return ;
    static Node *per = NULL;
    build_thread(root->l);
    if(root ->l ==NULL){
        root->l = per;
        root->ltag = T;
    }
    if()
}

Node *most_left(Node *p){
    while(p && p->ltag == N && p->l != NULL) p = p->l;
    return p;
}
void output(Node *root){
    
}
void in_order(Node *root){
    
}



void clear(Node *root){
    if(root == NULL) return ;
    if(root->ltag == N)clear(root->l);
    free(node->r);
    free(root);
}

void clear_Tree(Tree *tree){
    if(tree == NULL) return;
    clear_Node(tree->root);
    free(tree);
    return ;
}

int main(){
    srand(time(0));
    #define max_op 20
    Node *root = NULL;
    for(int i = 0; i < max_op; i++){
        int val = rand() % 100;
        root = insert(root, val);
    }
    build_thre(root);
    clear(root);
    return 0;
}
