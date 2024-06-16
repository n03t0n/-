#include "sqstack.cpp"

void StackSort(SqStack* &st) {
    // 包含顺序栈的基本运算算法
    // 对栈 st 中元素排序
    SqStack *tmpst;
    InitStack(tmpst);
    ElemType e, el;

    while (!StackEmpty(st)) {
        Pop(st, e); // 出栈元素 e
        printf("st:出栈%c=>\n", e);

        while (!StackEmpty(tmpst)) {
            GetTop(tmpst, el);
            printf("tmpst:取栈顶元素%c", el);

            if (el > e) {
                printf("因%c>%c", el, e);
            } else {
                printf("因%c<%c,退出循环      ", el, e);
                break;
            }

            printf("tmpst:退栈%c\n", el);
            Pop(tmpst, el);
            printf("st:进栈%c\n", el);
            Push(st, el);
        }

        Push(tmpst, e);
        printf("tmpst:进栈%c\n", e);
    }

    while (!StackEmpty(tmpst)) {
        Pop(tmpst, e);
        Push(st, e);
    }

    DestroyStack(tmpst);
}

int main() {
    ElemType e;
    SqStack *s;
    InitStack(s);

    printf("(1)依次进栈元素 1,3,4,2\n");
    Push(s, '1');
    Push(s, '3');
    Push(s, '4');
    Push(s, '2');

    printf("(2)栈s排序过程:\n");
    StackSort(s);

    printf("(3)栈s排序完毕\n");
    printf("(4)s 的出栈序列:");

    while (!StackEmpty(s)) {
        Pop(s, e);
        printf("%c", e);
    }

    printf("\n");
    DestroyStack(s);
    return 0;
}
