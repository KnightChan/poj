#include<cstdio>

int main()
{
    int n,a,b;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        if (b>a) printf("NO BRAINS\n");
        else printf("MMM BRAINS\n");
    }
}
