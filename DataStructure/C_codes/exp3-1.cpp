#include <stdio.h>
#include "sqstack.cpp"  // 包含顺序栈的基本运算算法

int main() {
    ElemType e;
    SqStack *s = NULL;  // 初始化栈指针

    printf("顺序栈 s 的基本运算如下:\n");
    
    printf("(1) 初始化栈 s\n");
    InitStack(s);
    
    printf("(2) 栈为%s\n", (StackEmpty(s) ? "空" : "非空"));
    
    printf("(3) 依次进栈元素 a, b, c, d, e\n");
    Push(s, 'a');
    Push(s, 'b');
    Push(s, 'c');
    Push(s, 'd');
    Push(s, 'e');

    GetTop(s, e);
    printf("取栈顶元素:%c\n", e);
    
    printf("(4) 栈为%s\n", (StackEmpty(s) ? "空" : "非空"));
    
    printf("(5) 出栈序列:");
    while (!StackEmpty(s)) {
        Pop(s, e);
        printf("%c", e);
    }
    printf("\n");
    
    printf("(6) 栈为%s\n", (StackEmpty(s) ? "空" : "非空"));
    
    printf("(7) 释放栈\n");
    DestroyStack(s);
    
    return 0;
}
