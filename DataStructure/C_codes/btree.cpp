#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef char ElemType;

typedef struct node {
    ElemType data;
    struct node *lchild;
    struct node *rchild;
} BTNode;

void CreateBTree(BTNode *&b, char *str) {
    BTNode *St[MaxSize], *p;
    int top = -1, k, j = 0;
    char ch;
    b = NULL;

    ch = str[j];

    //一定会先遇到'('
    //紧跟'('就是第一个节点lchild
    //lchild后面会有 ','  '('
    //','后面会有')'或者rchild
    //'('后面会有下一节点的lchild
    while (ch != '\0') {
        switch (ch) {
            case '(':
                top++;
                St[top] = p;
                k = 1;
                break;
            case ')':
                top--;
                break;
            case ',':
                k = 2;
                break;
            default:
                p = (BTNode *)malloc(sizeof(BTNode));
                p->data = ch;
                p->lchild = p->rchild = NULL;
                if (b == NULL) {
                    b = p;
                } else {
                    switch (k) {
                        case 1:
                            St[top]->lchild = p;
                            break;
                        case 2:
                            St[top]->rchild = p;
                            break;
                    }
                }
                break;
        }
        j++;
        ch = str[j];
    }
}

void DestroyBTree(BTNode *&b) {
    if (b != NULL) {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
        b = NULL; // 避免悬挂指针
    }
}

BTNode *FindNode(BTNode *b, ElemType x) {
    if (b == NULL) {
        return NULL;
    } else if (b->data == x) {
        return b;
    } else {
        BTNode *p = FindNode(b->lchild, x);
        if (p != NULL) {
            return p;
        } else {
            return FindNode(b->rchild, x);
        }
    }
}

BTNode *LchildNode(BTNode *p) {
    return p->lchild;
}

BTNode *RchildNode(BTNode *p) {
    return p->rchild;
}

int BTHeight(BTNode *b) {
    if (b == NULL) {
        return 0;
    } else {
        int lchildh = BTHeight(b->lchild);
        int rchildh = BTHeight(b->rchild);
        return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
    }
}

void DispBTree(BTNode *b) {
    if (b != NULL) {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL) {
            printf("(");
            DispBTree(b->lchild);
            if (b->rchild != NULL) {
                printf(",");
            }
            DispBTree(b->rchild);
            printf(")");
        }
    }
}

bool findPath(BTNode *root, ElemType path[], int *pathLen, ElemType k) {
    if (root == NULL) {
        return false;
    }

    path[*pathLen] = root->data;
    (*pathLen)++;

    if (root->data == k) {
        return true;
    }

    if ((root->lchild && findPath(root->lchild, path, pathLen, k)) ||
        (root->rchild && findPath(root->rchild, path, pathLen, k))) {
        return true;
    }

    (*pathLen)--;
    return false;
}

// 找到最近公共祖先节点
ElemType findLCA(BTNode *root, ElemType n1, ElemType n2) {
    ElemType path1[MaxSize];
    ElemType path2[MaxSize];
    int pathLen1 = 0, pathLen2 = 0;

    if (!findPath(root, path1, &pathLen1, n1) || !findPath(root, path2, &pathLen2, n2)) {
        return '\0'; // If either n1 or n2 is not present
    }

    int i;
    for (i = 0; i < pathLen1 && i < pathLen2; i++) {
        if (path1[i] != path2[i]) {
            break;
        }
    }
    return path1[i - 1];
}
