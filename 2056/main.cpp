#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> cmp[10001];
queue<int> stu;
int fnt[10001];
int sp[10001];
int d[10001];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;++i)
    {
        int a,b,c;
        scanf("%d %d", &a, &b);
        sp[i]=a;
        while(b--)
        {
            scanf("%d",&c);
            ++fnt[i];
            cmp[c].push_back(i);
        }
    }
    for(int i=1;i<=n;++i){
        if(fnt[i]==0){
            stu.push(i);
            d[i]=sp[i];
        }
    }
    while(!stu.empty())
    {
        int s=stu.front();
        stu.pop();
        for(int i=0;i<cmp[s].size();++i)
        {
            int a=cmp[s][i];
            --fnt[a];
            if(d[a]<d[s]+sp[a])
                d[a]=d[s]+sp[a];
            if(!fnt[cmp[s][i]])
                stu.push(cmp[s][i]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i)
        if(ans<d[i])
            ans=d[i];
    printf("%d", ans);
    return 0;
}
