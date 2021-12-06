#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int a[1005][1005];
bool check[1005];
int n, m, v;

void dfs(int s)
{
    printf("%d ", s);
    for(int i=1;i<=1000;++i)
    {
        if(check[i]==false&&a[s][i]==1){
            check[i]=1;
            dfs(i);
        }
    }
}

queue<int> ne;

void bfs()
{
    int s=ne.front();
    ne.pop();
    printf("%d ", s);
    for(int i=1;i<=1000;++i)
    {
        if(check[i]==false&&a[s][i]==1)
        {
            check[i]=1;
            ne.push(i);
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &v);
    for(int i=0;i<m;++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x][y]=a[y][x]=1;
    }
    check[v]=1;
    dfs(v);
    printf("\n");
    memset(check, false, sizeof(check));
    check[v]=1;
    ne.push(v);
    while(!ne.empty())
        bfs();
    return 0;
}
