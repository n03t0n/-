#include <stdio.h>
#include "listack.cpp"

bool bracketsMatch(char *exp) {
    LinkStNode *s;
    InitStack(s);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            Push(s, exp[i]);
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            ElemType topElem;
            if (Pop(s, topElem)) {
                if ((exp[i] == ')' && topElem != '(') ||
                    (exp[i] == ']' && topElem != '[') ||
                    (exp[i] == '}' && topElem != '{')) {
                    return false;
                }
            } else {
                return false; // 栈为空，但表达式中还有右括号
            }
        }
    }

    return StackEmpty(s);
}

int main() {

    char *test[3] = {"a*{b*[1/(2-c)+1/(1+d)]-3}", "a*{b*1/(2-c)+1/(1+d)]-3}", "a*{b*1/(2-c]+1/[1+d)-3}"};
    for(int i=0;i<3;i++)
    {
        printf("test[%d]括号%s\n", i, (bracketsMatch(test[i])?"配对":"不配对"));
    }

    ElemType e;
    LinkStNode *s ;
    printf("链栈s的基本运算如下 :\n");
    
    printf("(1) 初始化栈 s\n");
    InitStack(s);
    
    printf("(2) 栈为%s\n", (StackEmpty(s) ? "空" : "非空"));
    
    printf("(3) 依次进栈元素 a, b, c, d, e\n");
    Push(s, 'a');
    Push(s, 'b');
    Push(s, 'c');
    Push(s, 'd');
    Push(s, 'e');
    
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
