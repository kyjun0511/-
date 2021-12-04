#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check[100001];
int p[100001];
vector<int> tree[100001];

void findp(int n)
{
    check[n]=1;
    for(int i=0;i<tree[n].size();++i)
    {
        int next=tree[n][i];
        if(!check[next])
        {
            p[next]=n;
            findp(next);
        }
    }
}

int main()
{
    int n;
    check[1]=1;
    scanf("%d", &n);
    for(int i=0;i<n-1;++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    findp(1);
    for(int i=2;i<=n;++i)
    {
        printf("%d\n", p[i]);
    }
}
