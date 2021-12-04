#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int parent[1001];
vector<pair<int,pair<int,int>>> net;

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
    int n,m,cnt=0;
    scanf("%d %d", &n, &m);
    int l=m;
    for(int i=1;i<=n;++i)
        parent[i]=i;
    while(m--)
    {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        net.push_back(make_pair(c,make_pair(a,b)));
    }
    sort(net.begin(),net.end());
    for(int i=0;i<l;++i)
    {
        int a, b;
        a=net[i].second.first;
        b=net[i].second.second;
        if(Find(a)!=Find(b)){
            Union(a,b);
            cnt+=net[i].first;
        }
    }
    printf("%d", cnt);
    return 0;
}
