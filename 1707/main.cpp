#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int num, n,m;
int check[20002];
vector<int> line[20001];

bool dfs(int node, int color)
{
    check[node]=color;
    for(int i=0;i<line[node].size();++i)
    {
        if(check[line[node][i]]==color)
            return 1;
        else if(!check[line[node][i]])
            if(dfs(line[node][i],3-color))
                return 1;
    }
    return 0;
}

int main()
{
    scanf("%d", &num);
    while(num--)
    {
        int ch=0;
        memset(check, 0, sizeof(check));
        scanf("%d %d", &n, &m);
        for(int i=0;i<m;++i)
        {
            int a,b;
            scanf("%d %d", &a, &b);
            line[a].push_back(b);
            line[b].push_back(a);
        }
        for(int i=0;i<n;++i)
            if(!check[i])
                if(dfs(i,1))
                    ch=1;
        if(ch)
            printf("NO\n");
        else
            printf("YES\n");
        for(int i=0; i<=n; i++)
            line[i].clear();
    }
    return 0;
}
