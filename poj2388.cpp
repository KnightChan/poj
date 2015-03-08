#include<cstdio>
#include<algorithm>

int a[10001],n;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    scanf("%d",&a[i]);
    std::sort(a,a+n);
    printf("%d\n",a[n/2]);
    return 0;
}
