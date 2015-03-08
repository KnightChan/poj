#include<cstdio>

int a[100001],b[100001],c[100001];
const int M=2147483647;

int main()
{
    int n;
    scanf("%d",&n);
    while (n)
    {
        int count=0,max1=-M,max2=-M;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if (a[i]>=0) count++;
            if (a[i]>=max1)
            {
                max2=max1;
                max1=a[i];
            }
            else if (a[i]>max2) max2=a[i];
        }
        if (count<=2)
        {
            printf("%d\n",max1+max2);
            scanf("%d",&n);
            continue;
        }
        int t=0,sum=0;
        for (int i=1;i<n;i++)
        {
            if (t>0) t+=a[i];
            else t=a[i];
            if (sum<t) sum=t;
            b[i]=sum;
        }
        t=0;sum=0;
        for (int i=n;i>1;i--)
        {
            if (t>0) t+=a[i];
            else t=a[i];
            if (sum<t) sum=t;
            c[i]=sum;
        }
        sum=0;
        for (int i=1;i<n;i++)
        if (sum<b[i]+c[i+1]) sum=b[i]+c[i+1];
        printf("%d\n",sum);
/*
        for (int i=1;i<=n;i++)
        printf("%d ",b[i]);
        printf("\n");
        for (int i=1;i<=n;i++)
        printf("%d ",c[i]);
        printf("\n");
*/
        scanf("%d",&n);
    }
    return 0;
}
