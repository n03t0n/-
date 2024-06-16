#include <stdio.h>
#include "linklist.cpp" // 包含单链表的基本运算算法

LinkNode* sortColors(LinkNode* head) {
    LinkNode* dummy0 = (LinkNode*)malloc(sizeof(LinkNode));
    LinkNode* dummy1 = (LinkNode*)malloc(sizeof(LinkNode));
    LinkNode* dummy2 = (LinkNode*)malloc(sizeof(LinkNode));

    LinkNode* node0 = dummy0;
    LinkNode* node1 = dummy1;
    LinkNode* node2 = dummy2;

    while (head) {
        switch (head->data) {
            case '0':
                node0->next = head;
                node0 = node0->next;
                break;
            case '1':
                node1->next = head;
                node1 = node1->next;
                break;
            case '2':
                node2->next = head;
                node2 = node2->next;
                break;
            default:
                break;
        }
        head = head->next;
    }

    node0->next = dummy1->next;
    node1->next = dummy2->next;
    node2->next = NULL;

    head = dummy0;
    free(dummy1);
    free(dummy2);

    return head;
}

int main() {
    
    LinkNode *hr, *hf;
    ElemType e[] = "0120022010021";
    
    CreateListR(hr, e, 12);
    CreateListR(hf, e, 12);
    printf("头插与尾插法：\n");
    DispList(hr);
    DispList(hr);

    printf("Olist: ");
    DispList(hr);

    hr = sortColors(hr);
    printf("Slist: ");
    DispList(hr);
    
    return 0;
}
