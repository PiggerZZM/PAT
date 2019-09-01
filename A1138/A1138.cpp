#include <iostream>
#include <cstdio>
using namespace std;

int pre[50010],in[50010];

struct node
{
    int data;
    node *left, *right;
};

node* create(int preL, int preR, int inL, int inR)
{
    if(preL > preR)
        return NULL;
    node *root = new node;
    root->data = pre[preL];
    int k;
    for(k=inL; k<= inR; k++)
        if(in[k] == pre[preL])
            break;
    root->left = create(preL +1, preL+k-inL,inL,k-1);
    root->right = create(preL+k-inL+1,preR, k+1,inR);
    return root;
}

int findfirst(node* root)
{
    if(root->left != NULL)
        return findfirst(root->left);
    else if(root->right != NULL)
        return findfirst(root->right);
    else
        return root->data;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&pre[i]);
    for(int i=0; i<n; i++)
        scanf("%d",&in[i]);
    node* root = create(0,n-1,0,n-1);
    while(root->left != NULL)
        root = root->left;
    printf("%d\n",findfirst(root));

    return 0;
}
