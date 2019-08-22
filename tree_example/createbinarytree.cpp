#include <cstdio>

struct node
{
    int data;
    node* lchild;
    node* rchild;
};

node* create(int preL, int preR, int inL, int inR)
{
    // 给定前序遍历序列和中序遍历序列的序列区间，重建二叉树
    if(preL > preR)
        return NULL;
    node* root = new node;
    root->data = pre[preL];
    int k;
    for(k = inL; k <= inR;k++)
    {
        if(in[k] == pre[preL])
            break;
    }
    int numLeft = k - inL;
    root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    root->rchild = create(preL + numLeft + 1, preR, k+1, inR);

    return root;
}

int main()
{




    return 0;
}