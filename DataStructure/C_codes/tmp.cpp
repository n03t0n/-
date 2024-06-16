#include "btree.cpp"  // 确保这个头文件存在，并包含必要的定义和函数声明

void InOrder(BTNode * b, char* max) 
{ 
    if (b != NULL) 
    { 
        InOrder(b->lchild, max);         // 递归访问左子树
        printf("%c ", b->data);          // 访问根结点
        if ((*max - b->data) < 0) { *max = b->data; }
        InOrder(b->rchild, max);         // 递归访问右子树
    } 
}

int main() 
{ 
    BTNode *b;
    char max = 'A';                      // 初始化max
    CreateBTree(b, "X(B(E,Y(G,A)),C(,D(Z,J(,K))))");
    printf("二叉树 b:"); DispBTree(b); printf("\n");
    printf("递归算法:"); InOrder(b, &max); printf("\n");
    printf("最大字符: %c\n", max);       // 输出最大字符
    DestroyBTree(b);                     // 确保销毁树
    return 0; 
}
