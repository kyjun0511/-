#include <iostream>
#include <cstring>

using namespace std;

bool check[1001];

void cycle(int arr[], int node)
{
    check[node]=1;
    if(!check[arr[node]])
        cycle(arr,arr[node]);
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        int cnt=0;
        scanf("%d", &n);
        int arr[n+1];
        for(int i=1;i<=n;++i)
            scanf("%d", &arr[i]);
        for(int i=1;i<=n;++i)
            if(!check[i]){
                cycle(arr,i);
                ++cnt;
            }
        printf("%d\n", cnt);
        memset(check,0,sizeof(check));
    }
    return 0;
}
