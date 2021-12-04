#include <iostream>

using namespace std;

int check[240001];

int next(int a, int p)
{
    int sum=0;
    while(a)
    {
        int n1, n2;
        n1=n2=a%10;
        a/=10;
        for(int i=0;i<p-1;++i)
            n2*=n1;
        sum+=n2;
    }
    return sum;
}

int ch(int a, int p, int cnt)
{
    if(check[a]!=0)
        return check[a]-1;
    check[a]=cnt;
    return ch(next(a,p),p,cnt+1);
}

int main()
{
    int a, p;
    scanf("%d %d", &a, &p);
    printf("%d\n", ch(a,p,1));
    return 0;
}
