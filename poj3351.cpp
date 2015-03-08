//poj3351
//��̬�滮��
//1��dp[i][j]��ʾ��ǰ��i��ѡ���ϲ�Ϊj��ʱ�������Ӯ���ʤ����ѡ������ȥ�����ѡ������
//2��״̬ת�Ʒ��̣�dp[i][j]=max{dp[k][j-1]+win[k+1][i],j-1<=k<i}
//3��Ŀ������max(t) ʹ��dp[n][t] > 0�������n-t��
//win[i][j]��ʾ��i��j��ѡ���ϲ������Ӯ��1ΪӮ��-1Ϊ�䣬��ҪԤ����

//����֮�����������㷨��O(n^3)��dp����һ������д��֮����ȥTLE�ˣ�������ʹ�����Ż���
//��������Ͽ���һ��ǿ�����Ż��������ӶȽ�Ϊ�ӽ�O(n^2)�Ź����ˡ����������Լ��Ļ����������Ż�����������
//����dp[i][j]=max{dp[k][j-1]+win[k+1][i],j-1<=k<i}
//��win[k+1][i]Ӱ�죬dp[k][j-1] �����ֵ������win[k+1][i]�󲢲�һ����dp[i][j]�����ֵ
//���ǣ�win[k+1][i]��������ȡֵ��1��-1,���ҵ�k�仯ʱdp[k][j-1]��ֵ���2��4��6......
//�����Ļ������̿���д�ɣ�dp[k][j] = maxdp + win[k'+1][i]������maxdp = max(dp[k'][t-1])��k'��һ�����ƣ����ǣ�dp[k'][j-1]�������maxdp��
//һ��ת�������෽�̺�dp[k][j-1]����Ϣ�Ϳ����ظ����ã�״̬ת�Ƶĸ��Ӷȴ�󽵵͡�

//ʵ�֣���¼maxdp��Ȼ��һ��list����¼����dp[k'][j-1] = maxdp��k����ʵʱ����list��ÿ��ֻ���list��ת��״̬���С�

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
    memset(win,0,sizeof(win));//��ʼ����
    memset(dp,0,sizeof(dp));//��ʼ����
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
     }//Ԥ����win[i][j]��ʾ��i��j��ѡ���ϲ������Ӯ��1ΪӮ��-1Ϊ�䡣

    for (i=1;i<=n;i++) dp[i][0]=-100000;//Ԥ����

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
        if (win[list[p]+1][i]==1) break;//�ҵ�Ϊ1�ļ���ȷ��Ϊ��������˳���
        dp[i][j]=dp[list[p]][j-1]+win[list[p]+1][i];//����dp[i][j]��ֵ��
        }
    }

    for (ans=n;ans>0;ans--)
    if (dp[n][ans]>0) break;//Ŀ������max(ans) ʹ��dp[n][ans] > 0�������n-ans��

    if (ans) printf("%d\n",n-ans);//��Ȼ������ܻ�ʤ�Ļ���ans�����0����Ҫ�ж�һ�¡�
    else printf("-1\n");
    return 0;
}
