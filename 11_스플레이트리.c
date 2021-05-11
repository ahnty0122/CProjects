#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int key, height; // 높이 균형 맞추기 위해 이진탐색트리에서 height 변수 추가
    struct TreeNode* parent, * left, * right;
}TreeNode;

typedef struct{
    TreeNode* root;
}TreeType;

void initTree(TreeType* T)
{
    // 루트의 parent는 항상 null
    T->root = (TreeNode*)malloc(sizeof(TreeNode));
    T->root->parent = T->root->left = T->root->right = NULL;
    T->root->height = 0;
}

int isExternal(TreeNode* w)
{
    return (w->left == NULL && w->right == NULL);
}

void expandExternal(TreeNode* w)
{
    TreeNode* l = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* r = (TreeNode*)malloc(sizeof(TreeNode));
    l->left = NULL;
    l->right = NULL;
    l->parent = w;
    r->left = NULL;
    r->right = NULL;
    r->parent = w;
    w->left = l;
    w->right = r;
}

// 노드의 주소를 리턴
TreeNode* treeSearch(TreeNode* v, int k)
{
    if(isExternal(v))
        return v;
    if(k == v->key)
        return v;
    else if(k < v->key)
        return treeSearch(v->left, k);
    else
        return treeSearch(v->right, k);
}

int findElement(TreeType* T, int k)
{
    TreeNode* w = treeSearch(T->root, k);

    if(isExternal(w))
        return 0;
    else
        return w->key;
}


void rightRotate(TreeType * T, TreeNode * x, TreeNode * y)
{
    TreeNode * T0, * T1, * T2, * p;
    p = y->parent;
    T0 = x->left;
    T1 = x->right;
    T2 = y->right;

    y->parent = x;
    x->parent = p;

    if(x->parent == NULL)
        T->root = x;
    
    x->left = T0;
    x->right = y;
    y->left = T1;
    y->right = T2;
}

void leftRotate(TreeType * T, TreeNode * x, TreeNode * y)
{
    TreeNode * T0, * T1, * T2, * p;
    p = y->parent;
    T0 = y->left;
    T1 = x->left;
    T2 = x->right;

    y->parent = x;
    x->parent = p;

    if(x->parent == NULL)
        T->root = x;
    
    x->left = y;
    x->right = T2;
    y->left = T0;
    y->right = T1;
}

int main()
{
    TreeType* T = (TreeType*)malloc(sizeof(TreeType));
    initTree(T);
}