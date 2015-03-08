#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int f[10000000],i,j,n,k,m,ch[100];
int main()
{
    string s;
    scanf("%d",&n);
    memset(f,0,sizeof(f));
    memset(ch,-1,sizeof(ch));
    ch['A']=ch['B']=ch['C']=ch['2']=2;
    ch['D']=ch['E']=ch['F']=ch['3']=3;
    ch['G']=ch['H']=ch['I']=ch['4']=4;
    ch['J']=ch['K']=ch['L']=ch['5']=5;
    ch['M']=ch['N']=ch['O']=ch['6']=6;
    ch['P']=ch['R']=ch['S']=ch['7']=7;
    ch['T']=ch['U']=ch['V']=ch['8']=8;
    ch['W']=ch['X']=ch['Y']=ch['9']=9;
    ch['0']=0;ch['1']=1;
    for (i=1;i<=n;i++)
    {
    cin>>s;
    k=0;
    for (j=0;j<s.length();j++)
    if ((s[j]!='Q')&&(s[j]!='Z')&&(s[j]!='-')) k=k*10+ch[s[j]];
    f[k]++;
    }
    k=1;
    for (i=0;i<10000000;i++)
    if (f[i]>1)
    {
        j=i/10000;
        if (j<100)cout<<0;
        if (j<10)cout<<0;
        cout<<j<<'-';
        j=i%10000;
        if (j<1000)cout<<0;
        if (j<100)cout<<0;
        if (j<10)cout<<0;
        cout<<j<<' '<<f[i]<<endl;
        k=0;
    }
    if (k) printf("No duplicates.\n");
    return 0;
}
