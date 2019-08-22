#include <cstdio>
#include <queue>
using namespace std;

struct node
{
    int data;
    node *lchild, *rchild;
};

int post[35], in[35];

node *create(int postL, int postR, int inL, int inR)
{
    if (postR < postL)
        return NULL;
    node *root = new node;
    root->data = post[postR];
    int numL, numR;
    int k;
    for (k = inL; k <= inR; k++)
    {
        if (in[k] == post[postR])
            break;
    }
    numL = k - inL;
    numR = inR - k;
    root->lchild = create(postL, postL + numL - 1, inL, k - 1);
    root->rchild = create(postL + numL, postL + numL + numR - 1, k + 1, inR);

    return root;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);

    node *root = create(0, n - 1, 0, n - 1);

    queue<node*> q;
    q.push(root);
    node* temp;
    int count = 0;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        printf("%d",temp->data);
        count++;
        if(count < n)
            putchar(' ');
        else
            putchar('\n');
        if(temp->lchild != NULL)
            q.push(temp->lchild);
        if(temp->rchild != NULL)
            q.push(temp->rchild);
    }

    return 0;
}