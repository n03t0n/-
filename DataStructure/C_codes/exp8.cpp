#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MaxSize 100
#define NumLen 3

int WPL=0;

typedef char ElemType;

typedef struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
} BTNode;

void CreateBTree(BTNode *&b, const char *str) {
    BTNode *St[MaxSize], *p;
    int top = -1;  // Stack top pointer
    int k;         // Indicates whether it's a left or right child
    b = NULL;
    char number[NumLen];
    int i = 0;
    int numIndex;
    char ch = str[i];

    
    //可以把ST看成一个递归创建的栈
    while (ch != '\0') {
        switch (ch) {
        case '(':
            St[++top] = p;
            k = 1;  // Next node is the left child
            break;
        case ')':
            top--;
            break;
        case ',':
            k = 2;  // Next node is the right child
            break;
        default:
            if (isdigit(ch)) {
                numIndex = 0;
                while (isdigit(ch)) {
                    number[numIndex++] = ch;
                    ch = str[++i];
                }
                number[numIndex] = '\0';
                int num = atoi(number);

                p = (BTNode *)malloc(sizeof(BTNode));
                p->data = num;
                p->lchild = p->rchild = NULL;

                if (b == NULL) {
                    b = p;  // Initialize the root
                } else {
                    if (k == 1) {
                        St[top]->lchild = p;
                    } else {
                        St[top]->rchild = p;
                    }
                }
                i--;  // Adjust the position as the outer loop also increments i
            }
            break;
        }
        ch = str[++i];
    }
}

void PreOrder(BTNode *b) {
    if (b != NULL) {
        printf("%d ", b->data);
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

void PreOrderWPL(BTNode *b, int h) {
    if (b != NULL) {
        printf("%d ", b->data);
        if(b->lchild == NULL && b->rchild == NULL){
            WPL += h*b->data;
        }
        else{
            h += 1;
            PreOrderWPL(b->lchild, h);
            PreOrderWPL(b->rchild, h);
        }

    }
}

void DispBTree(BTNode *b) {
    if (b != NULL) {
        printf("%d", b->data);
        if (b->lchild != NULL || b->rchild != NULL) {
            printf("(");
            DispBTree(b->lchild);
            if (b->rchild != NULL) printf(",");
            DispBTree(b->rchild);
            printf(")");
        }
    }
}

int main() {
    BTNode *bt;
    CreateBTree(bt, "100(42(19(8(3,5),11),23),58(29,29(14,15(7,8))))");
    printf("二叉树 bt: ");
    DispBTree(bt);
    printf("\nbt 先序遍历: ");
    PreOrder(bt);
    printf("\n");
    PreOrderWPL(bt, 0);
    printf("\nWPL = %d\n", WPL);
    return 0;
}
