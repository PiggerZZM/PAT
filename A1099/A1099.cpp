#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
int a[110];
int p = 0;

struct node
{
    int left;
    int right;
    int data;
}Node[110];

void inorder(int root)
{
    if(root == -1)
        return;
    inorder(Node[root].left);
    Node[root].data = a[p++];
    inorder(Node[root].right);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int left,right;
        scanf("%d %d",&left,&right);
        Node[i].left = left;
        Node[i].right = right;
    }

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    inorder(0);
    vector<int> ans;
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        if(Node[temp].left != -1)
            q.push(Node[temp].left);
        if(Node[temp].right != -1)
            q.push(Node[temp].right);
    }

    for(int i=0;i<n-1;i++)
        printf("%d ",Node[ans[i]].data);
    printf("%d\n",Node[ans[n-1]].data);

    return 0;
}
