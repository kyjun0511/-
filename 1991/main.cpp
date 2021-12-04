#include <iostream>
using namespace std;
int a[50][2];
void preorder(int x)
{
    printf("%c", x+'A');
    if(a[x][0]!=NULL)
        preorder(a[x][0]);
    if(a[x][1]!=NULL)
        preorder(a[x][1]);
}
void inorder(int x)
{
    if(a[x][0]!=NULL)
        inorder(a[x][0]);
    printf("%c", x+'A');
    if(a[x][1]!=NULL)
        inorder(a[x][1]);
}
void postorder(int x)
{
    if(a[x][0]!=NULL)
        postorder(a[x][0]);
    if(a[x][1]!=NULL)
        postorder(a[x][1]);
    printf("%c", x+'A');
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        char x,y,z;
        cin>>x>>y>>z;
        x=x-'A';
        if(y!='.')
            a[x][0]=y-'A';
        if(z!='.')
            a[x][1]=z-'A';
    }
    preorder(0);
    cout<<'\n';
    inorder(0);
    cout<<'\n';
    postorder(0);
    cout<<'\n';
}
