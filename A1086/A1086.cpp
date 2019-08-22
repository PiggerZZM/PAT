#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

int pre[30];
int in[30];
stack<int> st;
int n, count = 0;

struct node
{
    int data;
    node *lchild, *rchild;
} Node;

node *create(int preL, int preR, int inL, int inR)
{
    if (preR < preL)
        return NULL;
    node *root = new node;
    root->data = pre[preL];
    int k;
    for (k = inL; k <= inR; k++)
        if (in[k] == pre[preL])
            break;
    int numL = k - inL;
    root->lchild = create(preL + 1, preL + numL, inL, k - 1);
    root->rchild = create(preL + numL + 1, preR, k + 1, inR);

    return root;
}

void postOrder(node *root)
{
    if (root == NULL)
        return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d", root->data);
    count++;
    if (count < n)
        putchar(' ');
    else
        putchar('\n');
}

int main()
{
    scanf("%d", &n);
    int preindex = 0;
    int inindex = 0;
    for (int i = 0; i < 2*n; i++)
    {
        int num;
        char word[10];
        scanf("%s", word);
        if (strcmp(word, "Push") == 0)
        {
            scanf("%d", &num);
            st.push(num);
            pre[preindex++] = num;
        }
        else
        {
            num = st.top();
            st.pop();
            in[inindex++] = num;
        }
    }

    node *root = create(0, n - 1, 0, n - 1);
    postOrder(root);

    return 0;
}