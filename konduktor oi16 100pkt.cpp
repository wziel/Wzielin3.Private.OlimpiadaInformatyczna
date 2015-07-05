#include<iostream>
#include<stdio.h>
using namespace std;
int n,k,a,t[602][602],dyn[602][51],prev[602][51];
int Count_Rec(int x1,int h1,int x2,int h2)
{
    return t[h2][x2]-t[h2][x1-1]-t[h1-1][x2]+t[h1-1][x1-1];
}
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) scanf("%d",&t[i][j]);
    for(int i=1;i<n;i++) for(int j=1;j<=n;j++) t[i][j]+=t[i-1][j]+t[i][j-1]-t[i-1][j-1];
    for(int i=1;i<=k;i++)for(int j=n;j>1;j--)
    {
            for(int l=j;l<n+1;l++)
            {
                    a=Count_Rec(j,1,l,j-1)+dyn[l+1][i-1];
                    if(a>dyn[j][i])
                    {
                                dyn [j][i]=a;
                                prev[j][i]=l+1;
                    }
            }
    }
    a=0;
    for(int j=1;j<=n;j++) if(dyn[j][k]>dyn[a][k])a=j;
    for(int i=0;i<k;i++)
    {
            printf("%d ",a-1); a=prev[a][k-i];
    }
    return 0;
}
