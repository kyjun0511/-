#include <iostream>
#include <queue>

using namespace std;

int n,cnt=1;
int island[100][100];
int locate[100][100];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
queue<pair<int,int>> loc;

void check(int x, int y)
{
    locate[x][y]=cnt;
    for(int i=0;i<4;++i)
    {
        int a=x+dx[i],b=y+dy[i];
        if(a>=0&&a<n&&b>=0&&b<n&&locate[a][b]==0&&island[a][b]==1)
        {
            check(a,b);
        }
    }
}

void connect(int x, int y)
{
    for(int i=0;i<4;++i)
    {
        int a=x+dx[i],b=y+dy[i];
        if(a>=0&&a<n&&b>=0&&b<n&&island[a][b]==0)
        {
            island[a][b]=island[x][y]+1;
            locate[a][b]=locate[x][y];
            loc.push(make_pair(a,b));
        }
    }
}

int bridge(int x, int y)
{
    int short_bri=200;
    for(int i=0;i<4;++i)
    {
        int a=x+dx[i],b=y+dy[i];
        if(locate[a][b]==locate[x][y])
            continue;
        if(a>=0&&a<n&&b>=0&&b<n)
            if(island[a][b]+island[x][y]-2<short_bri)
                short_bri=island[a][b]+island[x][y]-2;
    }
    return short_bri;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            scanf("%d", &island[i][j]);
            if(island[i][j]==1)
                loc.push(make_pair(i,j));
        }
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(locate[i][j]==0&&island[i][j]==1)
                check(i,j),++cnt;
    while(!loc.empty())
    {
        int num=loc.size();
        for(int i=0;i<num;++i){
            int a=loc.front().first;
            int b=loc.front().second;
            if(island[a][b]>0){
                connect(a,b);
            }
            loc.pop();
        }
    }
    int ans=200;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            if(island[i][j]==1)
                continue;
            int bri=bridge(i,j);
            if(ans>bri)
                ans=bri;
        }
    printf("%d", ans);
    return 0;
}
