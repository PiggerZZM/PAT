#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 2010; //  通话记录最多1000说明人数最多可能有2000
const int INF = 0x7FFFFFFF;

map<int, string> intToString; //  编号->姓名，输出时用
map<string, int> stringToint; //  姓名->编号，输入时用
map<string, int> Gang;        //  head->人数

int G[maxn][maxn] = {0};
int weight[maxn] = {0}; // 邻接矩阵，点权
int n, k, numPerson = 0;
bool vis[maxn] = {false};

int change(string str)
{
    // 返回姓名str对应的编号
    if (stringToint.find(str) != stringToint.end())
        return stringToint[str];
    else
    {
        stringToint[str] = numPerson;
        intToString[numPerson] = str;
        return numPerson++;
    }
}

void DFS(int nowvisit, int &head, int &numMember, int &totalvalue)
{
    // DFS遍历单个联通块，任务是：找出头目，计算总成员数，计算总权值
    numMember++; // 团伙成员加一
    vis[nowvisit] = true;
    if (weight[nowvisit] > weight[head])
        head = nowvisit; // 更新头目
    for (int i = 0; i < numPerson; i++)
    {
        if (G[nowvisit][i] > 0) // 遍历所有人，如果能到达i
        {
            totalvalue += G[nowvisit][i];        // 团伙总权值加上这条边权
            G[nowvisit][i] = G[i][nowvisit] = 0; // 删去这条边，避免重复计算
            if (!vis[i])
                DFS(i, head, numMember, totalvalue);
        }
    }
}

void DFStrave()
{
    for (int i = 0; i < numPerson; i++)
    {
        if (!vis[i])
        {
            int head = i, numMember = 0, totalvalue = 0;
            DFS(i, head, numMember, totalvalue);
            if (numMember > 2 && totalvalue > k)
                Gang[intToString[head]] = numMember;    // 符合团伙条件，用一个map记录下来这个团伙的头目和人数
        }
    }
}

int main()
{
    int w;
    string str1, str2;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }

    DFStrave();
    cout << Gang.size() << endl;
    map<string, int>::iterator it;
    for(it = Gang.begin(); it != Gang.end(); it++)
        cout << it->first << " " << it->second << endl;

    return 0;
}