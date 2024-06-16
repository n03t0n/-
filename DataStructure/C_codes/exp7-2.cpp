# include "btree.cpp"  // 包含二叉树的基本运算算法

// 先序遍历的递归算法
void PreOrder(BTNode * b) 
{ 
    if (b!=NULL) 
    { 
        printf("%c ",b->data);      // 访问根结点
        PreOrder(b->lchild);        // 递归访问左子树
        PreOrder(b->rchild);        // 递归访问右子树
    } 
}

// 先序非递归遍历算法
void PreOrder1(BTNode * b) 
{ 
    BTNode * St[MaxSize], * p; 
    int top = -1; 
    if (b!=NULL) 
    { 
        top++; 
        St[top] = b;                // 根结点进栈
        while (top > -1)            // 栈不为空时循环
        { 
            p = St[top]; 
            top--;                  // 出栈并访问该结点
            printf("%c ",p->data); 
            if (p->rchild!= NULL)   // 有右孩子, 将其进栈
            { 
                top++; 
                St[top] = p->rchild; 
            } 
            if (p->lchild!= NULL)   // 有左孩子, 将其进栈
            { 
                top++; 
                St[top] = p->lchild; 
            } 
        } 
    } 
    printf("\n"); 
}

// 中序遍历的递归算法
void InOrder(BTNode * b) 
{ 
    if (b!=NULL) 
    { 
        InOrder(b->lchild);         // 递归访问左子树
        printf("%c ",b->data);      // 访问根结点
        InOrder(b->rchild);         // 递归访问右子树
    } 
}

// 中序非递归遍历算法
void InOrder1(BTNode * b) 
{ 
    BTNode * St[MaxSize], * p; 
    int top = -1; 
    if (b!=NULL) 
    { 
        p = b; 
        while (top > -1 || p!= NULL) // 扫描结点 p 的所有左下结点并进栈
        { 
            while (p!= NULL) 
            { 
                top++; 
                St[top] = p; 
                p = p->lchild; 
            } 
            if (top > -1)           // 出栈结点 p 并访问
            { 
                p = St[top]; 
                top--; 
                printf("%c ",p->data); 
                p = p->rchild; 
            } 
        } 
    } 
    printf("\n"); 
}

// 后序遍历的递归算法
void PostOrder(BTNode * b) 
{ 
    if (b!= NULL) 
    { 
        PostOrder(b->lchild);       // 递归访问左子树
        PostOrder(b->rchild);       // 递归访问右子树
        printf("%c ",b->data);      // 访问根结点
    } 
}

// 后序非递归遍历算法
void PostOrder1(BTNode * b) 
{ 
    BTNode * St[MaxSize]; 
    BTNode * p; 
    int top = -1; 
    bool flag; 
    if (b!= NULL) 
    { 
        do 
        { 
            while (b!= NULL)        // 将 b 结点的所有左下结点进栈
            { 
                top++;
                St[top] = b; 
                b = b->lchild; 
            } 
            p = NULL; 
            flag = true; 
            while (top != -1 && flag) 
            { 
                b = St[top]; 
                if (b->rchild == p) // 右子树不存在或已被访问, 访问之
                { 
                    printf("%c ",b->data); 
                    top--; 
                    p = b;          // p 指向被访问的结点
                } 
                else 
                { 
                    b = b->rchild;  // b 指向右子树
                    flag = false;   // 表示当前不是处理根结点
                } 
            } 
        } while (top != -1); 
    } 
    printf("\n"); 
}

// 层次遍历
void TraveLevel(BTNode * b) 
{ 
    BTNode * Qu[MaxSize]; 
    int front,rear; 
    front = rear = 0;               // 定义队首和队尾指针
    if (b!= NULL) printf("%c ",b->data); // 根结点进队
    rear++; 
    Qu[rear] = b; 
    while (rear != front)           // 队列不为空
    { 
        front = (front + 1) % MaxSize; 
        b = Qu[front];              // 出队结点 b
        if (b->lchild!= NULL) 
        { 
            printf("%c ",b->lchild->data); // 输出左孩子, 并进队
            rear = (rear + 1) % MaxSize; 
            Qu[rear] = b->lchild; 
        } 
        if (b->rchild!= NULL) 
        { 
            printf("%c ",b->rchild->data); // 输出右孩子, 并进队
            rear = (rear + 1) % MaxSize; 
            Qu[rear] = b->rchild; 
        } 
    } 
    printf("\n"); 
}

int main() 
{ 
    BTNode * b; 
    CreateBTree(b,"A(B(D,E(H(J,K(L,M(N))))),C(F(G,I)))"); 
    printf("二叉树 b:");DispBTree(b);printf("\n"); 
    printf("层次遍历序列:"); 
    TraveLevel(b); 
    printf("先序遍历序列:\n"); 
    printf("    递归算法:");PreOrder(b);printf("\n"); 
    printf("  非递归算法:");PreOrder1(b);printf("\n"); 
    printf("中序遍历序列:\n"); 
    printf("    递归算法:");InOrder(b);printf("\n"); 
    printf("  非递归算法:");InOrder1(b);printf("\n"); 
    printf("后序遍历序列:\n"); 
    printf("    递归算法:");PostOrder(b);printf("\n"); 
    printf("  非递归算法:");PostOrder1(b);printf("\n"); 
    DestroyBTree(b); 
    return 1; 
}
