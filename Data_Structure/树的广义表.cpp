/*************************************************************************
	> File Name: 树的广义表.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 20时08分21秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
    // 构建结点
typedef struct Node{
    char data;
    struct Node *lchild, *rchild;
}Node;
    //构建树
typedef struct Tree{
    Node *root;
    int n;
}Tree;
    //构建栈
typedef struct Stack{
    Node **data;
    int top, size;
}Stack;
    //创建结点
Node *getNweNode(char val){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild =NULL;
    return p;
}
    //创建树
Tree *getNewTree(){
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree ->root = NULL;
    tree->n = 0;
    return tree;
}
   //创建栈
Stack *init_stack(int n){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (Node**)malloc(sizeof(Node *) * n);
    s->top = -1;
    s->size = n;
    return s;
}
  //判空
int empty(Stack *s) {
    return s->top == -1;
}

   //取栈成员
Node *top(Stack *s) {
    return s->data[s->top];
}
    //压栈
int push(Stack *s, Node *val) {
    if(s == NULL) return 0;
    if(s->top == s->size - 1) return 0;
    s->data[++(s->top)] = val;
    return 1;
}
  //弹栈
int pop(Stack *s) {
    if(empty(s)) return 0;
    s->top -= 1;
    return 1;
}

  // 声明
void clear_Stack(Stack *s);
  //主要算法
Node *build(char *str, int *node_num){
    Node *temp = NULL , *p = NULL;
    Stack *s = init_stack(strlen(str));
    int flag = 0;
    while(str[0]){
        switch(str[0]){
            case '(':
                   push(s,temp);
                   flag = 0;
                   temp = NULL;
                   break;

            case ')':
                p = top(s);
                pop(s);
                break;

            case ',':
                flag = 1;
                temp = NULL;
                break;

            case ' ':
                break;

            default:
                temp = getNweNode(str[0]);
                 if(!empty(s) && flag == 0){
                    top(s)->lchild = temp;
                 }else if(!empty(s) && flag){
                    top(s)->rchild = temp;
            }
            ++(*node_num);
            break;

        }
        ++str;
    }
    clear_Stack(s);
    if(temp && !p) p = temp;
    return p;
}
 // 中序
void in_orderNodew(Node *node) {
    if(node == NULL) return;
    in_orderNodew(node->lchild);
    printf("%c ", node->data);
    in_orderNodew(node->rchild);
    return ;
}


void in_order(Tree *tree) {
    printf("in_order : ");
    in_orderNodew(tree->root);
    return ;
}
   // 先序
void per_orderNodew(Node *node) {
    if(node == NULL) return;
    printf("%c ", node->data);
    per_orderNodew(node->lchild);
    per_orderNodew(node->rchild);
    return ;
}

void per_order(Tree *tree) {
    printf("per_order : ");
    per_orderNodew(tree->root);
    return ;
}
   //后序
void post_orderNodew(Node *node) {
    if(node == NULL) return;
    post_orderNodew(node->lchild);
    post_orderNodew(node->rchild);
    printf("%c ", node->data);
    return ;
}


void post_order(Tree *tree) {
    printf("post_order : ");
    post_orderNodew(tree->root);
    return ;
}

    //销毁
void clear_node(Node *node){
    if(node == NULL) return ;
    clear_node(node->lchild);
    clear_node(node->rchild);
    free(node);
    return ;
}

void clear_Tree(Tree *tree){
    if(tree == NULL) return;
    clear_node(tree->root);
    free(tree);
    return ;
}

void clear_Stack(Stack *s){
    if(s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

int main(){
    char str[100];
    scanf("%[^\n]s",str);
    int node_num = 0;
    Tree *tree = getNewTree();
    tree ->root = build(str, &node_num);
    tree ->n = node_num;
    per_order(tree), printf("\n");
    in_order(tree),printf("\n");
    post_order(tree), printf("\n");
    clear_Tree(tree);
    return 0;
}


