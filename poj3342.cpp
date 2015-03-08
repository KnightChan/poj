//poj3342
//此题就是一个树形dp，比较简单。
//dp[i][1]表示选i这个节点的时候，i以及i的下属（包括下属的下属。。。）能参加的最大的人数。
//dp[i][0]则表示不选i这个节点的时候，i的下属们能参加的最大人数。
//显然有状态转移方程：
//1：dp[i][1]=∑dp[k][0]，k取遍i的所有子节点。
//2：dp[i][0]=∑max{dp[k][0]，dp[k][1]}，k取遍i的所有子节点。
//最后只需要去看看根节点是取还是不取的最大就行了。

//上面的都是比较简单的，困难一点的就是判断到底是不是唯一解。
//显然从状态转移方程来看，只有dp[i][0]=∑max{dp[k][0]，dp[k][1]}这个方程有可能会引起多个最大。
//也就是在取dp[i][0]的某个子节点k的时候，dp[k][0]==dp[k][1]，那么i这个节点的不取时候的最大值就不是唯一的，
//相应的，如果在i这个节点取它的子节点时，如果子节点不是唯一的，显然i也不唯一了。
//下面请看代码：
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Node
{
    int no;
    string name;
}a[201];

int dp[201][2],f[201],l=0;
bool yes[201][1];
string name[201];
vector <int> v[201];//v[i]里面记录的是i的所有子节点。

int find(string s,int l)
{
    for (int i=1;i<=l;i++)
    if (s==name[i]) return i;
    return 0;
}

int max(int a,int b) {return (a>b?a:b);}

void Dfs(int x)
{
    int i;
    for (i=0;i<v[x].size();i++)
    {
        if (!f[v[x][i]]) Dfs(v[x][i]);//递归的先找出它子节点的值。
        f[v[x][i]]=1;//标记x，表示x节点已经被算出来了，避免重复计算。
        dp[x][1]+=dp[v[x][i]][0];//不懂的话看状态转移方程。

        if (yes[v[x][i]][0]) yes[x][1]=true;//yes=true表示不唯一。
        //下面的也是和上面的差不多。
        dp[x][0]+=max(dp[v[x][i]][1],dp[v[x][i]][0]);
        if (dp[v[x][i]][1]==dp[v[x][i]][0]) yes[x][0]=true;
        if (dp[v[x][i]][1]>dp[v[x][i]][0]&&yes[v[x][i]][1]) yes[x][0]=true;
        if (dp[v[x][i]][1]<dp[v[x][i]][0]&&yes[v[x][i]][0]) yes[x][0]=true;
        f[x]=1;
    }
}

int main()
{
    int n,i;
    cin>>n;
    while (n)
    {
        string s1,s2;
        l=1;
        cin>>name[1];
        for (i=2;i<=n;i++)
        {
            cin>>s2>>s1;
            if (!find(s1,l)) name[++l]=s1;
            if (!find(s2,l)) name[++l]=s2;
            v[find(s1,l)].push_back(find(s2,l));
        }//预处理，做出树的结构。
        memset(f,0,sizeof(f));//初始化。
        memset(yes,0,sizeof(yes));
        memset(dp,0,sizeof(dp));
        for (i=1;i<=l;i++)
        {
            dp[i][1]=1;
            dp[i][0]=0;
        }
        Dfs(1);

        for (i=1;i<=l;i++)
        v[i].clear();//清楚痕迹，以便下次使用。

        cout<<max(dp[1][1],dp[1][0])<<' ';//输出选根节点和不选根节点的最大值，即为问题所求的最大值。
        if (dp[1][1]>dp[1][0]) i=1; else i=0;
        if (yes[1][i]||dp[1][1]==dp[1][0]) cout<<"No\n";//判断解是否唯一。
        else cout<<"Yes\n";
        cin>>n;//读入n以便做下一次。
    }
    return 0;
}
