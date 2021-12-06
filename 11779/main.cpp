#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;
int n, m, st, en;
int dp[1001];
int dpp[1001];
bool check[1001][1001];
queue<int> next_node;
vector<pair<int,int>> road[1001];
stack<int> dp_road;

int main()
{
    memset(dp,1000000,sizeof(dp));
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;++i)
    {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        road[a].push_back(make_pair(b,c));
    }
    scanf("%d %d", &st, &en);
    dp[st]=0;
    next_node.push(st);
    while(!next_node.empty())
    {
        int a=next_node.front();
        next_node.pop();
        for(int i=0;i<road[a].size();++i)
        {
            if(dp[road[a][i].first]>road[a][i].second+dp[a])
            {
                dp[road[a][i].first]=road[a][i].second+dp[a];
                dpp[road[a][i].first]=a;
            }
            if(!check[a][road[a][i].first])
                next_node.push(road[a][i].first);
            check[a][road[a][i].first]=true;
        }
    }
    printf("%d\n", dp[en]);
    int node=en;
    while(node!=st)
    {
        dp_road.push(node);
        node=dpp[node];
    }
    dp_road.push(st);
    int sz=dp_road.size();
    printf("%d\n", sz);
    while(sz--)
    {
        printf("%d ", dp_road.top());
        dp_road.pop();
    }
    return 0;
}
