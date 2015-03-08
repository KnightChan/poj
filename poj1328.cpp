//poj1328
//����ĽⷨΪ̰�ģ��㷨˼·��ʦ�Ѿ��������ҾͲ���˵�ˡ�

//������ʱд������ʱ���ǳ��˺ݶ���󣬺���ʦ˵��һ����
//��������Ӧ�����кܶ��ĵģ�Ȼ���Լ������Щ�������ݸĶ���һ�£��͹����ˣ����ǱȽ����˵ġ�

//�����뿴���룺
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>

struct Node
{
    double l,r;
}a[1001];//��¼ÿ���������Ϣ��

bool cmp(Node a,Node b)
{
    if (a.r<b.r) return 1;
    return 0;
}

int main()
{
    int n,d,k=0,f[1001];
    scanf("%d%d",&n,&d);
    while (n)
    {
        k++;
        bool flag=0;
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if (abs(y)>d)
            {
                flag=1;
            }
            a[i].l=x-sqrt((double)(d*d-y*y));
            a[i].r=x+sqrt((double)(d*d-y*y));
        }
        if (flag)
        {
            printf("Case %d: %d\n",k,-1);
            scanf("%d%d",&n,&d);
            continue;
        }
        std::sort(a+1,a+n+1,cmp);//�����ұ߽�����
        int ans=0;
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)//��˳����ÿ�����졣
        if (!f[i])//�����i�����컹û�б����ǹ����ͼ�һ���״︲�ǡ�
        {
            ans++;
            f[i]=1;
            for (int j=i+1;j<=n;j++)//�����¼ӵ�����״��ܸ��ǵĵ��죬�������Ǳ��Ϊ���ǹ���
            if (a[i].r>=a[j].l) f[j]=1;
        }
        printf("Case %d: %d\n",k,ans);//�����Ҫ���״�����
        scanf("%d%d",&n,&d);//������һ�����ݡ�
    }
    return 0;
}
