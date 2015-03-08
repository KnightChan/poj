#include<cstdio>

const int t[8]={1,2,4,8,16,32,64,128};
double dp[8][129],p[129][129];

int main()
{
    int n;
    scanf("%d",&n);
    while (n!=-1)
    {
        for (int i=1;i<=t[n];i++)
        for (int j=1;j<=t[n];j++)
        scanf("%lf",&p[i][j]);

        //printf("haha1\n");

        for (int i=0;i<=n;i++)
        for (int j=0;j<=t[n];j++)
        dp[i][j]=0;

        for (int i=1;i<=t[n];i++)
        {
            dp[0][i]=1;
        }

        //printf("haha2\n");

        for (int i=0;i<n;i++)
        for (int k=1;k<=t[n];k++)
        {
            int temp=k/t[i];
            if (k%t[i]==0) temp--;
            temp++;
            if (temp%2) temp++;else temp--;
            //printf("%d %d\n",(temp-1)*t[i]+1,temp*t[i]);
            for (int j=(temp-1)*t[i]+1;j<=temp*t[i];j++)
            dp[i+1][k]=dp[i+1][k]+dp[i][j]*p[k][j]*dp[i][k];
        }

        int ans=0;
        double max=0;
        for (int i=1;i<=t[n];i++)
        if (dp[n][i]>max)
        {
            max=dp[n][i];
            ans=i;
        }
/*
        for (int i=1;i<=t[n];i++)
        printf("%lf ",dp[n][i]);
        printf("\n");
*/
        printf("%d\n",ans);

        scanf("%d",&n);
    }
    return 0;
}
