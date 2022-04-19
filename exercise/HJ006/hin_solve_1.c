/**
 * 构建一个树结构，递归地分解每一个节点
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int Type;

// 树节点
typedef struct node {
    Type data;
    struct node* left;
    struct node* right;
} Node;
// 树结构
typedef struct tree {
    Node* root;
    int size;
} Tree;

Node* createNode(Type x);
int deleteNode(Node* nd);
Tree* createTree(void);
int deleteTree(Tree* t);
int divide(Node* nd);  // 递归分解
int displayLeaf(Node* nd);  // 递归打印树叶

int main(void) {
    unsigned long int n;
    Tree* tree = createTree();

    // 输入
    scanf("%Lu", &n);
    tree->root = createNode(n);
    tree->size += 1;

    // 分解
    divide(tree->root);

    // 输出
    displayLeaf(tree->root);
    
    deleteTree(tree);

    return 0;
}

Node* createNode(Type x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int deleteNode(Node* nd) {
    if (nd != NULL) {
        deleteNode(nd->left);
        deleteNode(nd->right);
        free(nd);
    }
    return 0;
}

Tree* createTree(void) {
    Tree* t = (Tree*)malloc(sizeof(Tree));
    t-> root = NULL;
    t-> size = 0;
    return t;
}

int deleteTree(Tree* t) {
    deleteNode(t->root);
    free(t);
    t = NULL;

    return 0;
}

int divide(Node* nd) {
    Type x = 2;
    while (x < (Type)sqrt(nd->data)+1) {    // 性质：一个数的质因数必小于其开根号
        if (nd->data % x == 0) {
            nd->left = createNode(x);
            nd->right = createNode(nd->data / x);
            divide(nd->left);
            divide(nd->right);
            break;
        }
        x++;
    }
    if (x == nd->data) {
        return 1;
    }

    return 0;
}

int displayLeaf(Node* nd){
    if(nd->left == NULL && nd->right == NULL){
        printf("%u ", nd->data);
    } else{
        if(nd->left != NULL)
            displayLeaf(nd->left);
        if(nd->right != NULL)
            displayLeaf(nd->right);
    }
    
    return 0;
}
