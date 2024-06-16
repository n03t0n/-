#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char ElemType;

// 定义链表节点结构体
typedef struct DLinkNode {
    ElemType data;
    struct DLinkNode *prior;
    struct DLinkNode *next;
} DLinkNode;

// 头插法建立循环双链表
void CreateListF(DLinkNode *&L, ElemType a[], int n) {
    L = (DLinkNode *)malloc(sizeof(DLinkNode));  // 创建头节点
    L->prior = L->next = L;  // 初始时头节点的前驱和后继都指向自己
    for (int i = 0; i < n; i++) {
        DLinkNode *s = (DLinkNode *)malloc(sizeof(DLinkNode));  // 创建新节点
        s->data = a[i];  // 将元素赋值给新节点
        s->next = L->next;  // 新节点的后继指向原首节点
        L->next->prior = s;  // 原首节点的前驱指向新节点
        L->next = s;  // 头节点的后继指向新节点
        s->prior = L;  // 新节点的前驱指向头节点
    }
}

// 尾插法建立循环双链表
void CreateListR(DLinkNode *&L, ElemType a[], int n) {
    L = (DLinkNode *)malloc(sizeof(DLinkNode));  // 创建头节点
    L->prior = L->next = L;  // 初始时头节点的前驱和后继都指向自己
    DLinkNode *r = L;  // r指向尾节点
    for (int i = 0; i < n; i++) {
        DLinkNode *s = (DLinkNode *)malloc(sizeof(DLinkNode));  // 创建新节点
        s->data = a[i];  // 将元素赋值给新节点
        r->next = s;  // 尾节点的后继指向新节点
        s->prior = r;  // 新节点的前驱指向尾节点
        s->next = L;  // 新节点的后继指向头节点
        L->prior = s;  // 头节点的前驱指向新节点
        r = s;  // 更新尾节点指针
    }
}

// 正序输出循环双链表
void DispList(DLinkNode *L) {
    DLinkNode *p = L->next;  // 从首节点开始遍历
    while (p != L) {  // 循环直到回到头节点
        printf("%c ", p->data);  // 输出当前节点的数据
        p = p->next;  // 移动到下一个节点
    }
    printf("\n");
}

// 逆序输出循环双链表
void DispListRev(DLinkNode *L) {
    DLinkNode *p = L->prior;  // 从尾节点开始遍历
    while (p != L) {  // 循环直到回到头节点
        printf("%c ", p->data);  // 输出当前节点的数据
        p = p->prior;  // 移动到前一个节点
    }
    printf("\n");
}

// 在循环双链表尾部插入节点
void InsertTail(DLinkNode *&L, ElemType e) {
    DLinkNode *s = (DLinkNode *)malloc(sizeof(DLinkNode));  // 创建新节点
    s->data = e;  // 将元素赋值给新节点
    s->next = L;  // 新节点的后继指向头节点
    s->prior = L->prior;  // 新节点的前驱指向尾节点的前驱节点
    L->prior->next = s;  // 尾节点的后继指向新节点
    L->prior = s;  // 头节点的前驱指向新节点
}

// 从循环双链表尾部删除节点
bool DeleteTail(DLinkNode *&L, ElemType &e) {
    if (L->next == L)  // 空链表无法删除
        return false;
    DLinkNode *p = L->prior;  // p指向尾节点
    e = p->data;  // 获取尾节点数据
    p->prior->next = L;  // 倒数第二个节点的后继指向头节点
    L->prior = p->prior;  // 头节点的前驱指向倒数第二个节点
    free(p);  // 释放尾节点内存
    return true;
}

// 主函数
int main() {  
    DLinkNode *L;
    char a[] = {'A', 'a', 'b', 'c', 'a', 'a', 'b', 'b'};
    int n = sizeof(a) / sizeof(a[0]);

    // 使用头插法建立循环双链表
    CreateListF(L, a, n);
    printf("使用头插法建立的循环双链表正序输出：");
    DispList(L);
    printf("使用头插法建立的循环双链表逆序输出：");
    DispListRev(L);

    // 使用尾插法建立循环双链表
    CreateListR(L, a, n);
    printf("使用尾插法建立的循环双链表正序输出：");
    DispList(L);
    printf("使用尾插法建立的循环双链表逆序输出：");
    DispListRev(L);

    // 在尾部插入节点
    ElemType newData = 'Z';
    InsertTail(L, newData);
    printf("插入节点后的循环双链表正序输出：");
    DispList(L);

    // 删除尾部节点
    ElemType deletedData;
    DeleteTail(L, deletedData);
    printf("删除尾部节点后的循环双链表正序输出：");
    DispList(L);

    return 0;
}
