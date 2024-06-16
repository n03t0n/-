#include "../exp3/sqstack.cpp"

void InitQueue(SqStack *&s1, SqStack *&s2) {
    InitStack(s1);
    InitStack(s2);
}

bool EnQueue(SqStack *&s1, SqStack *&s2, ElemType e) {
    if (s1->top == MaxSize - 1 && s2->top == MaxSize - 1) {
        return false; // 队满
    }
    while (!StackEmpty(s1)) {
        ElemType temp;
        Pop(s1, temp);
        Push(s2, temp);
    }
    Push(s1, e);
    while (!StackEmpty(s2)) {
        ElemType temp;
        Pop(s2, temp);  
        Push(s1, temp);
    }
    return true;
}

// 出队
bool DeQueue(SqStack *&s1, ElemType &e) {
    if (StackEmpty(s1)) {
        return false; // 队空
    }
    Pop(s1, e);
    return true;
}

int main() {
    SqStack *s1, *s2;
    InitQueue(s1, s2);
    
    // 入队a b c
    EnQueue(s1, s2, 'a');
    EnQueue(s1, s2, 'b');
    EnQueue(s1, s2, 'c');
    printf("入队元素a, b, c\n");
    
    // 出队a
    ElemType e;
    DeQueue(s1, e);
    printf("出队元素：%c\n", e);
    
    // 入队d e f g
    EnQueue(s1, s2, 'd');
    EnQueue(s1, s2, 'e');
    EnQueue(s1, s2, 'f');
    EnQueue(s1, s2, 'g');
    printf("入队元素d, e, f, g\n");

    // 连续出队
    while (DeQueue(s1, e)) {
        printf("出队元素：%c\n", e);
    }

    DestroyStack(s1);
    DestroyStack(s2);
    
    return 0;
}
