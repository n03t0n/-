// 文件名：exp7-1.cpp
#include "btree.cpp" // 包含二叉树的基本运算算法

int main() {
    BTNode *b, *p, *lp, *rp;
    printf("二叉树的基本运算如下:\n");
    printf("\t(1)创建二叉树\n");
    CreateBTree(b, "A(B(D,E(H(J,K(L,M(,N)))))C(F,G( ,I)))");

    printf("\t(2)输出二叉树:");
    DispBTree(b);
    printf("\n");

    printf("\t(3)查结点:");
    p = FindNode(b, 'H');
    if (p != NULL) {
        lp = LchildNode(p);
        if (lp != NULL)
            printf("左孩子为 %c ", lp->data);
        else
            printf("无左孩子 ");

        rp = RchildNode(p);
        if (rp != NULL)
            printf("右孩子为 %c ", rp->data);
        else
            printf("无右孩子 ");
    }

    printf("\n");
    printf("\t(4)二叉树 b 的高度: %d\n", BTHeight(b));
    printf("\t(5)找节点N, J的最近公共祖先节点%c\n", findLCA(b, 'N', 'J'));
    printf("\t(6)释放二叉树 b\n");
    DestroyBTree(b);

    return 1;
}
