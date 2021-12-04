#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

bool check[100001];

vector<pair<int,int>> line[100001];

int lowest, max_depth;

void dfs(int pre, int depth)
{
    check[pre]=1;
    if(depth>max_depth)
        max_depth=depth,lowest=pre;
    for(int i=0;i<line[pre].size();++i)
    {
        if(check[line[pre][i].first]==0)
            dfs(line[pre][i].first, depth+line[pre][i].second);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;++i)
    {
        int node1;
        cin>>node1;
        while(1)
        {
            int node2, len;
            cin>>node2;
            if(node2==-1)
                break;
            cin>>len;
            line[node1].push_back(make_pair(node2,len));
        }
    }
    dfs(1,0);
    memset(check, false, sizeof(check));
    max_depth=0;
    dfs(lowest,0);
    printf("%d", max_depth);
}
