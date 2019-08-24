#include <cstdio>
#include <vector>
using namespace std;

struct node
{
    int data;
    node *lchild, *rchild;
    node(int d) : data(d), lchild(NULL), rchild(NULL) {}
};

void insert1(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return;
    }
    else if (data < root->data)
        insert1(root->lchild, data);
    else
        insert1(root->rchild, data);
}

void insert2(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return;
    }
    else if (data < root->data)
        insert2(root->rchild, data);
    else
        insert2(root->lchild, data);
}

void preorder(node *root, vector<int> &t)
{
    if (root == NULL)
        return;
    t.push_back(root->data);
    preorder(root->lchild, t);
    preorder(root->rchild, t);
}

void postorder(node *root, vector<int> &t)
{
    if (root == NULL)
        return;
    postorder(root->lchild, t);
    postorder(root->rchild, t);
    t.push_back(root->data);
}

int main()
{
    int n;
    int temp;
    scanf("%d", &n);
    vector<int> t1, t2, t3, t4, ans;
    node *root1 = NULL, *root2 = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        t1.push_back(temp);
        t2.push_back(temp);
        insert1(root1, temp);
        insert2(root2, temp);
    }

    preorder(root1, t3);
    preorder(root2, t4);

    if (t1 == t3)
    {
        printf("YES\n");
        postorder(root1, ans);
        for (int i = 0; i < ans.size() - 1; i++)
            printf("%d ", ans[i]);
        printf("%d\n", ans[ans.size() - 1]);
    }
    else if (t2 == t4)
    {
        printf("YES\n");
        postorder(root2, ans);
        for (int i = 0; i < ans.size() - 1; i++)
            printf("%d ", ans[i]);
        printf("%d\n", ans[ans.size() - 1]);
    }
    else
        printf("NO\n");

    return 0;
}