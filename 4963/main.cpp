#include <cstdio>
int land[50][50]={0};
int max_n;
int a,b;

void dfs(int x, int y)
{
    if(land[x][y]==0)
        return;
    land[x][y]=0;
    if(x!=0){
        if(y!=0)
            dfs(x-1,y-1);
        dfs(x-1,y);
        if(y!=b-1)
            dfs(x-1,y+1);
    }
    if(y!=0)
        dfs(x,y-1);
    if(y!=b-1)
        dfs(x,y+1);
    if(x!=a-1){
        if(y!=0)
            dfs(x+1,y-1);
        dfs(x+1,y);
        if(y!=b-1)
            dfs(x+1,y+1);
    }
    return;
}
int main()
{
    while(1)
    {
        for(int i=0; i<50; i++) {
                for(int j=0; j<50; j++) {land[i][j]=0; }
        }
        max_n=1;
        scanf("%d %d", &b, &a);
        if(a==0 && b==0) return 0;
        for(int i=0;i<a;++i)
            for(int j=0;j<b;++j)
                scanf("%d", &land[i][j]);

        for(int x=0;x<a;++x)
            for(int y=0;y<b;++y){
                if(land[x][y]==0)
                    continue;
                dfs(x,y);
                max_n++;
            }
        printf("%d\n", max_n-1);
    }
}
