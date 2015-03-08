#include<iostream>
#include<string>
using namespace std;
string light,heavy,s1,s2,s3;
int i,j,k,n,f[100],fl[100],fh[100],maxl,maxh,pdl[100],pdh[100],ol,oh;
int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
    {
        memset(f,0,sizeof(f));
        memset(fl,0,sizeof(fl));
        memset(fh,0,sizeof(fh));
        k=0;
        light="";
        heavy="";
        while (k<3)
        {
            k++;
            cin>>s1>>s2>>s3;
            if (s3[0]=='e')
            {
                for (j=0;j<s1.length();j++)
                f[s1[j]]=1;
                for (j=0;j<s2.length();j++)
                f[s2[j]]=1;
            }
            if (s3[0]=='u')
            {
                if (f[s2[j]]) continue;
                for (j=0;j<s2.length();j++)
                {
                    if (fh[s2[j]])
                    {
                        f[s2[j]]=1;
                        continue;
                    }
                   // if (fl[s2[j]]==0)
                    {
                        light+=s2[j];
                        fl[s2[j]]=1;
                    }
                }
                for (j=0;j<s1.length();j++)
                {
                    if (f[s1[j]]) continue;
                    if (fl[s1[j]])
                    {
                        f[s1[j]]=1;
                        continue;
                    }
                   // if (fh[s1[j]]==0)
                    {
                        heavy+=s1[j];
                        fh[s1[j]]=1;
                    }
                }
            }
            if (s3[0]=='d')
            {
                for (j=0;j<s1.length();j++)
                {
                    if (f[s1[j]]) continue;
                    if (fh[s1[j]])
                    {
                        f[s1[j]]=1;
                        continue;
                    }
                  //  if (fl[s1[j]]==0)
                    {
                        light+=s1[j];
                        fl[s1[j]]=1;
                    }
                }
                for (j=0;j<s2.length();j++)
                {
                    if (f[s2[j]]) continue;
                    if (fl[s2[j]])
                    {
                        f[s2[j]]=1;
                        continue;
                    }
                   // if (fh[s2[j]]==0)
                    {
                        heavy+=s2[j];
                        fh[s2[j]]=1;
                    }
                }
            }
        }
    //cout<<light<<endl;
    //cout<<heavy<<endl;
    memset(pdl,0,sizeof(pdl));
    memset(pdh,0,sizeof(pdh));
    maxl=0;maxh=0;
    for (j=0;j<light.length();j++)
    if (f[light[j]]==0)
    {
        ++(pdl[light[j]]);
        if (pdl[light[j]]>maxl) { maxl=pdl[light[j]];ol=j;}
    }
    for (j=0;j<heavy.length();j++)
    if (f[heavy[j]]==0)
    {
        ++(pdh[heavy[j]]);
        if (pdh[heavy[j]]>maxh) { maxh=pdh[heavy[j]];oh=j;}
    }
    if (maxl>maxh)
    cout<<light[ol]<<" is the counterfeit coin and it is light."<<endl;
    else
    cout<<heavy[oh]<<" is the counterfeit coin and it is heavy."<<endl;
    }
    return 0;
}
