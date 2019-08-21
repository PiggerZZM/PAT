#include <cstdio>
#include <queue>
using namespace std;

int X[6] = {1, -1, 0, 0, 0, 0};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};

int matrix[1290][130][61];
bool inque[1290][130][61] = {false};
int m, n, l, t;

struct node
{
    int x, y, z;
} Node;

bool judge(int x, int y, int z)
{
    if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l)
        return false;
    if (inque[x][y][z] || matrix[x][y][z] == 0)
        return false;
    return true;
}

int BFS(int x, int y, int z)
{
    int count = 0;
    queue<node> q;
    Node.x = x;
    Node.y = y;
    Node.z = z;
    q.push(Node);
    inque[x][y][z] = true;
    while (!q.empty())
    {
        node top = q.front();
        q.pop();
        count++;
        int newx, newy, newz;
        for (int i = 0; i < 6; i++)
        {
            newx = top.x + X[i];
            newy = top.y + Y[i];
            newz = top.z + Z[i];
            if (judge(newx, newy, newz))
            {
                Node.x = newx;
                Node.y = newy;
                Node.z = newz;
                q.push(Node);
                inque[newx][newy][newz] = true;
            }
        }
    }
    if (count >= t)
        return count;
    else
        return 0;
}

int main()
{
    scanf("%d%d%d%d", &m, &n, &l, &t);
    for (int z = 0; z < l; z++)
        for (int x = 0; x < m; x++)
            for (int y = 0; y < n; y++)
                scanf("%d", &matrix[x][y][z]);
    int ans = 0;

    for (int z = 0; z < l; z++)
        for (int x = 0; x < m; x++)
            for (int y = 0; y < n; y++)
                if (matrix[x][y][z] == 1 && !inque[x][y][z])
                    ans += BFS(x, y, z);

    printf("%d\n", ans);

    return 0;
}