//poj2181
#include<cstdio>
int main()
{
    int max1=0,max2=0,i,n,j,f1,f2;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&j);
        f1=max2+j;
        if (max1>j) f2=max1-j;
        else f2=0;
        if (f1>max1) max1=f1;
        if (max2<f2) max2=f2;
    }//上面循环中的max1和max2分别表示最后取到的数是奇数个和是偶数个时的最大值。
    //而f1和f2则是两个临时变量。
    int _max=max1;
    if (max2>_max) _max=max2;//此处取max1和max2的较大者，即为题目所求的最大值。
    printf("%d\n",_max);
    return 0;
}
