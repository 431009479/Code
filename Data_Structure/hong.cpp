/*************************************************************************
	> File Name: hong.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月16日 星期六 16时31分44秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define BLACK 1
#define DBLACK 2

typedef struct Node {
    int key;
    int color;//0 red 1 black 2 double black
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)//指针

__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->lchild = NIL->rchild = NIL;
    NIL->color = BLACK;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NIL;
    p->color = RED;//默认插入红色
    return p;
}

bool has_red_child(Node *root) {
    return root->lchild->color == 0 || root->rchild->color == 0;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

//root为祖父结点
Node *insert_maintain(Node *root) {
    if (!has_red_child(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
        root->color = RED;
        root->lchild->color = root->rchild->color = BLACK;
        return root;
    }
    if (root->lchild->color == RED) {
        if (!has_red_child(root->lchild)) return root;
        if (root->lchild->rchild->color == RED) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (!has_red_child(root->rchild)) return root;
        if (root->rchild->lchild->color == RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    root->color = RED;
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

Node *predeccessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;mZ

Node *eraser_maintian(Node *root) {
    if (root->lchild->color != DBLACK && 
        root->rchild->color != DBLACK) return root;
    if (has_red_child(root)) {//双重黑兄弟节点为红
        root->color = RED;
        if (root->lchild->color == RED) {
            root = right_rotate(root);
            root->rchild = eraser_maintian(root->rchild);
        } else {
            root = left_rotate(root);
            root->lchild = eraser_maintian(root->rchild);
        }
        root->color = BLACK;
        return root;
    } 
    if ((root->lchild->color == DBLACK && !has_red_child(root->rchild)) || 
        (root->rchild->color == DBLACK && !has_red_child(root->lchild)) {
        root->color += 1;//情况一
        root->lchild->color -= 1;
        root->rchild->color -= 1;
        return root;
    }
    if (root->lchild->color == BLACK) {
        if (root->rchild->rchild->color != RED) {//RL 
            root->rchild->color = RED
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = BLACK
        }
        root->rchild->color = root->color;
        root->color = BLACK;
        root->lchild->color -= 1;
        root->left_rotate(root);
        root->rchild->color = BLACK;
    } else {
        if (root->lchild->lchild->color != RED) {//LR
            root->lchild->color = RED
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = BLACK
        }
        root->lchild->color = root->color;
        root->color = BLACK;
        root->rchild->color -= 1;
        root->right_rotate(root);
        root->lchild->color = BLACK;       
    }
}

Node *__erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key > key) {
        root->lchild = __erase(root->lchild, key);
    } else if (root->key < key) {
        root->rchild = __erase(root->rchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            temp->color += root->color;
            free(root);
            return temp;
        } else {
            Node *temp = predeccessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    return eraser_maintian(root);
}

Node *erase(Node *root, int key) {
    root = __erase(root, key);
    root->color = BLACK;
    return root;
}

Node *__insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) {
        root->lchild = __insert(root->lchild, key);
    } else {
        root->rchild = __insert(root->rchild, key);
    }
    return insert_maintain(root);
}

//包装一层，防止根节点为红色
Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = BLACK;
    return root;
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    printf("(%d | %d, %d, %d)\n", 
        root->color, 
        root->key,
        root->lchild->key,
        root->rchild->key
    );
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 0: root = insert(root, val);break;
            case 1:break;
        }
        output(root);
    }
    return 0;
}

