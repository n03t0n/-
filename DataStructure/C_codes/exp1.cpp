#include "sqlist.cpp"
#include<string.h>
using namespace std;
void DeleteSame(SqList*& L)
{
    int i,k=0;
    int n = L->length;
    for (i = 0; i < n; i++)
    {
        if (L->data[i] == L->data[i + 1])
            k = k - 1;
        else
        L->data[k] = L->data[i];
        k++;
    }
    L->length = k;
}

int main()
{
    SqList* L;
    char h[] = "0024447";
    CreateList(L, h, strlen(h));
    printf("原顺序表：");
    DispList(L);
    
    DeleteSame(L);
    printf("删除后顺序表：");
    DispList(L);
    DestroyList(L);
    return 0;
}