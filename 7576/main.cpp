#include <iostream>
#include <queue>

using namespace std;

int n,m,cnt=2;
int box[1000][1000];
queue<pair<int,int>> loc;

void riping(int a, int b)
{
    if(a>0&&box[a-1][b]==0)
        box[a-1][b]=box[a][b]+1,loc.push(make_pair(a-1,b));
    if(a<n-1&&box[a+1][b]==0)
        box[a+1][b]=box[a][b]+1,loc.push(make_pair(a+1,b));
    if(b>0&&box[a][b-1]==0)
        box[a][b-1]=box[a][b]+1,loc.push(make_pair(a,b-1));
    if(b<m-1&&box[a][b+1]==0)
        box[a][b+1]=box[a][b]+1,loc.push(make_pair(a,b+1));
}

bool ripe_check()
{
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(box[i][j]==0)
                return false;
    return true;
}
bool passage(int a, int b)
{
    if(box[a][b]!=0)
        return true;
    if(a>0&&box[a-1][b]!=-1)
        return true;
    if(a<n-1&&box[a+1][b]!=-1)
        return true;
    if(b>0&&box[a][b-1]!=-1)
        return true;
    if(b<m-1&&box[a][b+1]!=-1)
        return true;
    return false;
}

int main()
{
    scanf("%d %d", &m,&n);
    bool check=true;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            scanf("%d", &box[i][j]);
            if(box[i][j]==1)
                loc.push(make_pair(i,j));
        }
    if(loc.empty())
    {
        printf("-1");
        return 0;
    }
    while(!loc.empty())
    {
        if(ripe_check())
            break;
        int num=loc.size();
        for(int i=0;i<num;++i){
            int a=loc.front().first;
            int b=loc.front().second;
            if(box[a][b]>0){
                riping(a,b);
            }
            loc.pop();
        }
    }
    bool chk=false;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(box[i][j]==0)
                chk=true;
    if(chk)
    {
        printf("-1");
        return 0;
    }
    int ans=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(ans<box[i][j])
                ans=box[i][j];
    printf("%d", ans-1);
    return 0;
}
