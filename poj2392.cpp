//poj2392
//此题为一简单dp，老师说如果不优化会TLE，不过我最开始写完了没优化就交了一次，还是很简单的AC了，
//不过后来又按照老师说的方法优化了一下，果然是要比原来的程序快了不少。

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
     if (f[j])//如果j这个高度能够搭出来，则在此高度上用第i种方块继续搭。
      for (int p=1;p<=bl[i].c;p++)
      if (f[j+p*bl[i].h]||j+p*bl[i].h>bl[i].a) break;//前面一个条件为判重，后面一个则是老师讲的优化。
      else f[j+p*bl[i].h]=1;
    for (ans=_max;ans>=0;ans--)//从最高的高度一直往下找，找到的第一个能搭出来的即为所能搭出来的最大值。
    if (f[ans]) break;
    printf("%d\n",ans);//输出结果。
    return 0;
}
