//poj3342
//�������һ������dp���Ƚϼ򵥡�
//dp[i][1]��ʾѡi����ڵ��ʱ��i�Լ�i�������������������������������ܲμӵ�����������
//dp[i][0]���ʾ��ѡi����ڵ��ʱ��i���������ܲμӵ����������
//��Ȼ��״̬ת�Ʒ��̣�
//1��dp[i][1]=��dp[k][0]��kȡ��i�������ӽڵ㡣
//2��dp[i][0]=��max{dp[k][0]��dp[k][1]}��kȡ��i�������ӽڵ㡣
//���ֻ��Ҫȥ�������ڵ���ȡ���ǲ�ȡ���������ˡ�

//����Ķ��ǱȽϼ򵥵ģ�����һ��ľ����жϵ����ǲ���Ψһ�⡣
//��Ȼ��״̬ת�Ʒ���������ֻ��dp[i][0]=��max{dp[k][0]��dp[k][1]}��������п��ܻ����������
//Ҳ������ȡdp[i][0]��ĳ���ӽڵ�k��ʱ��dp[k][0]==dp[k][1]����ôi����ڵ�Ĳ�ȡʱ������ֵ�Ͳ���Ψһ�ģ�
//��Ӧ�ģ������i����ڵ�ȡ�����ӽڵ�ʱ������ӽڵ㲻��Ψһ�ģ���ȻiҲ��Ψһ�ˡ�
//�����뿴���룺
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
vector <int> v[201];//v[i]�����¼����i�������ӽڵ㡣

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
        if (!f[v[x][i]]) Dfs(v[x][i]);//�ݹ�����ҳ����ӽڵ��ֵ��
        f[v[x][i]]=1;//���x����ʾx�ڵ��Ѿ���������ˣ������ظ����㡣
        dp[x][1]+=dp[v[x][i]][0];//�����Ļ���״̬ת�Ʒ��̡�

        if (yes[v[x][i]][0]) yes[x][1]=true;//yes=true��ʾ��Ψһ��
        //�����Ҳ�Ǻ�����Ĳ�ࡣ
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
        }//Ԥ�����������Ľṹ��
        memset(f,0,sizeof(f));//��ʼ����
        memset(yes,0,sizeof(yes));
        memset(dp,0,sizeof(dp));
        for (i=1;i<=l;i++)
        {
            dp[i][1]=1;
            dp[i][0]=0;
        }
        Dfs(1);

        for (i=1;i<=l;i++)
        v[i].clear();//����ۼ����Ա��´�ʹ�á�

        cout<<max(dp[1][1],dp[1][0])<<' ';//���ѡ���ڵ�Ͳ�ѡ���ڵ�����ֵ����Ϊ������������ֵ��
        if (dp[1][1]>dp[1][0]) i=1; else i=0;
        if (yes[1][i]||dp[1][1]==dp[1][0]) cout<<"No\n";//�жϽ��Ƿ�Ψһ��
        else cout<<"Yes\n";
        cin>>n;//����n�Ա�����һ�Ρ�
    }
    return 0;
}
