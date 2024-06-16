#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char ElemType;

typedef struct linknode {
    ElemType data;
    struct linknode *next;
} LinkStNode;

// 初始化链栈
void InitStack(LinkStNode *&s) {
    s = (LinkStNode*)malloc(sizeof(LinkStNode));
    s->next = NULL;
}

// 销毁链栈
void DestroyStack(LinkStNode *&s) {
    LinkStNode *p = s->next;
    while (p != NULL) {
        free(s);
        s = p;
        p = p->next;
    }
    free(s);
}

// 判断栈空否
bool StackEmpty(LinkStNode *s) { 
    return (s->next == NULL);
}

// 进栈
void Push(LinkStNode *&s, ElemType e) {
    LinkStNode *p;
    p = (LinkStNode *)malloc(sizeof(LinkStNode));
    p->data = e;
    p->next = s->next;
    s->next = p;
}

// 出栈
bool Pop(LinkStNode *&s, ElemType &e) {
    LinkStNode *p;
    if (s->next == NULL) {
        return false;
    }
    p = s->next;
    e = p->data;
    s->next = p->next;
    free(p);
    return true;
}

// 取栈顶元素
bool GetTop(LinkStNode *s, ElemType &e) {
    if (s->next == NULL) {
        return false;
    }
    e = s->next->data;
    return true;
}
