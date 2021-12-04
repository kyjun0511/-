#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> cmp[32001];
queue<int> stu;
int fnt[32001];

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    for(int _=0;_<m;++_)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        cmp[a].push_back(b);
        ++fnt[b];
    }
    for(int i=1;i<=n;++i)
        if(fnt[i]==0)
            stu.push(i);
    while(!stu.empty())
    {
        int s=stu.front();
        stu.pop();
        printf("%d ",s);
        for(int i=0;i<cmp[s].size();++i)
        {
            --fnt[cmp[s][i]];
            if(!fnt[cmp[s][i]])
                stu.push(cmp[s][i]);
        }
    }
    return 0;
}
