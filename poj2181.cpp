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
    }//����ѭ���е�max1��max2�ֱ��ʾ���ȡ������������������ż����ʱ�����ֵ��
    //��f1��f2����������ʱ������
    int _max=max1;
    if (max2>_max) _max=max2;//�˴�ȡmax1��max2�Ľϴ��ߣ���Ϊ��Ŀ��������ֵ��
    printf("%d\n",_max);
    return 0;
}
