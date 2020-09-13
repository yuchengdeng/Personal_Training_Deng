#include "stdio.h"   
#include "math.h"   
#include <stdlib.h>   
int L1[8],L2[8],v[20],u[20];   
int s_1[16]={14,3,4,8,1,12,10,15,7,13,9,6,11,2,0,5};    //S�е���   
   
void bit(int l[],int a,int begin)   //ʮ����ת��Ϊ������   
{   
    if (a>=8)   
    {   
        l[begin]=1;   
        a=a-8;   
    }   
    else l[begin]=0;   
    if (a>=4)   
    {   
        l[begin+1]=1;   
        a=a-4;   
    }   
    else l[begin+1]=0;   
    if (a>=2)   
    {   
        l[begin+2]=1;   
        a=a-2;   
    }   
    else l[begin+2]=0;   
    if (a>=1)   
    {   
        l[begin+3]=1;   
        a=a-1;   
    }   
    else l[begin+3]=0;   
}   
   
int main()   
{   
    char c;   
    int n,i,j,t,ix,iy,v2,v4,u2,u4,z,max=-1,a,b;   
    int x[20],y[20],p[20][20];   
    freopen("in.txt","r",stdin);        //���ļ���ʽ����8000���������Ķ�   
    for(i=0;i<16;i++)   
    {   
        for(j=0;j<16;j++)   
        {   
            p[i][j]=0;   
        }   
    }   
    scanf("%d",&n); //n����Ϊ8000   
    getchar();   
    for (t=0;t<n;t++)   
    {   
        for (ix=1;ix<=16;ix++)   
        {https://gmplib.org/manual/   
            scanf("%c",&c);   
            x[ix]=c-48;                 //��ȡ����   
        }   
        getchar();   
        for (iy=1;iy<=16;iy++)   
        {   
            scanf("%c",&c);   
            y[iy]=c-48;                 //��ȡ����   
        }   
        getchar();   
        for (i=0;i<16;i++)   
        {   
            bit(L1,i,1);   
            for (j=0;j<16;j++)   
            {   
                bit(L2,j,1);   
                v[5]=(L1[1]+y[5])%2;   
                v[6]=(L1[2]+y[6])%2;   
                v[7]=(L1[3]+y[7])%2;   
                v[8]=(L1[4]+y[8])%2;   
                v[13]=(L2[1]+y[13])%2;   
                v[14]=(L2[2]+y[14])%2;   
                v[15]=(L2[3]+y[15])%2;   
                v[16]=(L2[4]+y[16])%2;   
                v2=0;   
                if (v[5]==1)    v2=v2+8;   
                if (v[6]==1)    v2=v2+4;   
                if (v[7]==1)    v2=v2+2;   
                if (v[8]==1)    v2=v2+1;   
                u2=s_1[v2];   
                bit(u,u2,5);   
                v4=0;   
                if (v[13]==1)   v4=v4+8;   
                if (v[14]==1)   v4=v4+4;   
                if (v[15]==1)   v4=v4+2;   
                if (v[16]==1)   v4=v4+1;   
                u4=s_1[v4];   
                bit(u,u4,13);   
                z=(x[5]+x[7]+x[8]+u[6]+u[8]+u[14]+u[16])%2;   
                if (z==0) p[i][j]++;   
            }   
        }   
    }   
    for (i=0;i<16;i++)   
    {   
        for (j=0;j<16;j++)   
        {   
            p[i][j]=abs(p[i][j]-n/2);   
            if (p[i][j]>max)   
            {   
                max=p[i][j];   
                a=i;   
                b=j;   
            }   
        }   
    }   
    printf("������ܵ�8λ����Կ��\n");   
    bit(L1,a,1);   
    printf("%d%d%d%d ",L1[1],L1[2],L1[3],L1[4]);   
    bit(L2,b,1);   
    printf("%d%d%d%d\n",L2[1],L2[2],L2[3],L2[4]);   
    return 0;   
}   
