#include <cstdio>

using namespace std;

int parent[1000001];

int Find(int x)
{
    if(x==parent[x])
        return x;
    else
        return parent[x]=Find(parent[x]);
}
void Union(int x, int y)
{
    x=Find(x);
    y=Find(y);
    if(x!=y)
        parent[y]=x;
}

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0;i<=n;++i)
        parent[i]=i;
    while(m--)
    {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        if(a)
        {
            if(Find(b)==Find(c))
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
            Union(b,c);
    }
    return 0;
}
