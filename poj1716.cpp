//poj1716
//���͵Ĳ��Լ��ϵͳ��
//�㷨˼·�������Ѿ����Ͽε�ʱ��˵���������������·���󷨡�
//���������õ�spfa��������������·��������ʱ����ʱ����ͦΣ�յģ�900��MS�չ���- -!~

//�����뿴���룺

#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

struct AAA
{
    int v,len;
};

const int MAX=2147483647;
vector<AAA> p[100001];
int q[2100000],d[100001],_max=0,f[100001],_min=MAX;

void Swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}

void SPFA(int v0)//spfa�㷨�ľ�����롣
{
    int l=0,r=1,i;
    vector<AAA> temp;
    for (i=_min;i<=_max+1;i++) d[i]=MAX;
    q[1]=v0;d[v0]=0;f[v0]=1;
    while (l<r)
    {
        l++;
        f[q[l]]=0;
        temp=p[q[l]];
        for (i=0;i<temp.size();i++)
        if (d[q[l]]+temp[i].len<d[temp[i].v])
        {
            d[temp[i].v]=d[q[l]]+temp[i].len;
            if (!f[temp[i].v])
            {
                r++;
                q[r]=temp[i].v;
                f[temp[i].v]=1;
            }
        }
    }
}

int main()
{
    int n,b,a;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)//�������ݹ�ͼ��
    {
        AAA dd;
        scanf("%d%d",&a,&b);
        if (a>b) Swap(a,b);
        dd.len=-2;
        dd.v=b+1;
        p[a].push_back(dd);
        if (b>_max) _max=b;
        if (a<_min) _min=a;
    }
    for (int i=_min;i<=_max;i++)//��ͼ��
    {
        AAA dd;
        dd.len=1;
        dd.v=i;
        p[i+1].push_back(dd);
        dd.len=0;
        dd.v=i+1;
        p[i].push_back(dd);
    }
    memset(d,0,sizeof(d));
    memset(f,0,sizeof(f));
    SPFA(_min);//��spfa
    printf("%d\n",-d[_max+1]+d[_min]);//��������
    return 0;
}
