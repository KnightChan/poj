//poj3351
//动态规划：
//1：dp[i][j]表示把前面i个选区合并为j个时的最大输赢差（即胜利的选区数减去输掉的选区数）
//2：状态转移方程：dp[i][j]=max{dp[k][j-1]+win[k+1][i],j-1<=k<i}
//3：目标则是max(t) 使得dp[n][t] > 0，输出答案n-t。
//win[i][j]表示从i到j的选区合并后的输赢，1为赢，-1为输，需要预处理。

//困难之处：上述的算法是O(n^3)的dp，第一次这样写了之后交上去TLE了，后来就使劲想优化，
//最后在网上看到一个强力的优化，将复杂度降为接近O(n^2)才过掉了。下面我用自己的话将看到的优化叙述出来。
//首先dp[i][j]=max{dp[k][j-1]+win[k+1][i],j-1<=k<i}
//受win[k+1][i]影响，dp[k][j-1] 的最大值，加上win[k+1][i]后并不一定是dp[i][j]的最大值
//但是：win[k+1][i]仅有两种取值，1和-1,而且当k变化时dp[k][j-1]的值相差2、4、6......
//这样的话，方程可以写成：dp[k][j] = maxdp + win[k'+1][i]，这里maxdp = max(dp[k'][t-1])，k'有一个限制，就是，dp[k'][j-1]必须等于maxdp。
//一旦转换成这类方程后，dp[k][j-1]的信息就可以重复利用，状态转移的复杂度大大降低。

//实现：记录maxdp，然后建一个list，记录满足dp[k'][j-1] = maxdp的k’，实时更新list，每次只需从list里转移状态就行。

#include<cstdio>
#include<string>

int win[1010][1010],v[1010][1010],dp[1010][1010],n,p,ans,list[1010],top,_max;

int max(int a,int b)
{
    if (a>b) return a;
    return b;
}

int main()
{
    int i,j,k;
    scanf("%d",&n);
    scanf("%d",&p);
    memset(win,0,sizeof(win));//初始化。
    memset(dp,0,sizeof(dp));//初始化。
    for (i=1;i<=n;i++)
     for (j=1;j<=p;j++)
     {
         scanf("%d",&k);
         v[i][j]=v[i-1][j]+k;
     }
    for (i=1;i<=n;i++)
     for (j=i;j<=n;j++)
     {
         for (k=2;k<=p;k++)
         if (v[j][1]-v[i-1][1]<=v[j][k]-v[i-1][k])
         break;
         if (k>p) win[i][j]=1;
         else win[i][j]=-1;
     }//预处理，win[i][j]表示从i到j的选区合并后的输赢，1为赢，-1为输。

    for (i=1;i<=n;i++) dp[i][0]=-100000;//预处理；

    for (j=1;j<=n;j++)
    {
        _max=-1000000;
        for (i=j;i<=n;i++)
        {
        if (dp[i-1][j-1]>_max)
        {
            _max=dp[i-1][j-1];
            list[1]=i-1;
            top=1;
        }else if (dp[i-1][j-1]==_max)
        list[++top]=i-1;
        for(p=1;p<top;p++)
        if (win[list[p]+1][i]==1) break;//找到为1的即可确定为最大，所以退出。
        dp[i][j]=dp[list[p]][j-1]+win[list[p]+1][i];//更新dp[i][j]的值。
        }
    }

    for (ans=n;ans>0;ans--)
    if (dp[n][ans]>0) break;//目标则是max(ans) 使得dp[n][ans] > 0，输出答案n-ans。

    if (ans) printf("%d\n",n-ans);//当然如果不能获胜的话，ans会等于0，需要判断一下。
    else printf("-1\n");
    return 0;
}
