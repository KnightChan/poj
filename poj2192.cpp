#include<iostream>
#include<string>
using namespace std;
int dp[201][201];

int max(int a,int b)
{
    if (a>b) return a;
    return b;
}

int main()
{
    int t,l1,l2,l3;
    string s1,s2,s3;
    cin>>t;
    for (int c=1;c<=t;c++)
    {
        cin>>s1>>s2>>s3;
        l1=s1.length();
        l2=s2.length();
        l3=s3.length();
        memset(dp,0,sizeof(dp));
        int flag=0;
        for (int i=0;i<=l1;i++)
         for (int j=0;j<=l2;j++)
         {
             int temp=dp[i][j];
             if (s1[i]==s3[temp])
             {
                 dp[i+1][j]=max(dp[i+1][j],temp+1);
                 if (dp[i+1][j]==l3) flag=1;
             }
             if (s2[j]==s3[temp])
             {
                 dp[i][j+1]=max(dp[i][j+1],temp+1);
                 if (dp[i][j+1]==l3) flag=1;
             }
             if (flag) goto LL;
         }

         LL:

         /* for (int i=0;i<=l1;i++)
         for (int j=0;j<=l2;j++)
         cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
         */
         if (flag) cout<<"Data set "<<c<<": yes\n";
         else cout<<"Data set "<<c<<": no\n";
    }
    return 0;
}
