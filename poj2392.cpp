//poj2392
//����Ϊһ��dp����ʦ˵������Ż���TLE���������ʼд����û�Ż��ͽ���һ�Σ����Ǻܼ򵥵�AC�ˣ�
//���������ְ�����ʦ˵�ķ����Ż���һ�£���Ȼ��Ҫ��ԭ���ĳ�����˲��١�

#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

struct Node
{
    int a,c,h;
}bl[401];

bool cmp(Node d,Node b)
{
    if (d.a<b.a) return 1;
    return 0;
}

int main()
{
    int k,f[40001],_max=-1,ans;
    memset(f,0,sizeof(f));
    scanf("%d",&k);
    for (int i=1;i<=k;i++)
    {
        scanf("%d%d%d",&bl[i].h,&bl[i].a,&bl[i].c);
        if (_max<bl[i].a) _max=bl[i].a;
    }
    sort(bl+1,bl+k+1,cmp);
    f[0]=1;
    for (int i=1;i<=k;i++)
     for (int j=bl[i].a;j>=0;j--)
     if (f[j])//���j����߶��ܹ�����������ڴ˸߶����õ�i�ַ�������
      for (int p=1;p<=bl[i].c;p++)
      if (f[j+p*bl[i].h]||j+p*bl[i].h>bl[i].a) break;//ǰ��һ������Ϊ���أ�����һ��������ʦ�����Ż���
      else f[j+p*bl[i].h]=1;
    for (ans=_max;ans>=0;ans--)//����ߵĸ߶�һֱ�����ң��ҵ��ĵ�һ���ܴ�����ļ�Ϊ���ܴ���������ֵ��
    if (f[ans]) break;
    printf("%d\n",ans);//��������
    return 0;
}
