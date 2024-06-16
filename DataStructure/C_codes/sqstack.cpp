#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 100

typedef char ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

// 初始化顺序栈
void InitStack(SqStack *&s) {
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}

// 销毁顺序栈
void DestroyStack(SqStack *&s) {
    free(s);
}

// 判断栈空否
bool StackEmpty(SqStack *s) {
    return (s->top == -1);
}

// 进栈
bool Push(SqStack *&s, ElemType e) {
    if (s->top == MaxSize - 1) {
        return false; // 栈满的情况, 即栈上溢出
    }
    s->top++;
    s->data[s->top] = e;
    return true;
}

// 出栈
bool Pop(SqStack *&s, ElemType &e) {
    if (s->top == -1) {
        return false; // 栈为空的情况, 即栈下溢出
    }
    e = s->data[s->top];
    s->top--;
    return true;
}

// 取栈顶元素
bool GetTop(SqStack *s, ElemType &e) {
    if (s->top == -1) {
        return false; // 栈为空的情况, 即栈下溢出
    }
    e = s->data[s->top];
    return true;
}
