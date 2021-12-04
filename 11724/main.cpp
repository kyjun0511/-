#include <iostream>
#include <vector>
using namespace std;
vector<int> l[1001];
bool check[1001];

void dfs(int node)
{
    check[node]=true;
    for(int i=0;i<l[node].size();++i)
        if(!check[l[node][i]])
            dfs(l[node][i]);
}

int main()
{
    int n,m,cnt=0;
    scanf("%d %d", &n, &m);
    while(m--)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        l[a].push_back(b);
        l[b].push_back(a);
    }
    for(int i=1;i<=n;++i)
    {
        if(!check[i])
        {
            dfs(i);
            ++cnt;
        }
    }
    printf("%d", cnt);
    return 0;
}
