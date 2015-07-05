#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int parent[7000],ile[7000],n;
int Find(int x)
{
    if(parent[x]==x)return x;
    parent[x]=Find(parent[x]);
    return parent[x];
}
int Union(int x,int y)
{
    if(Find(x)==Find(y))return 0;
    if(ile[parent[x]]>ile[parent[y]])parent[parent[y]]=parent[x];
    else parent[parent[x]]=parent[y];
    return 0;
}
struct prostokat
{
    int downx,downy,upx,upy;
};
prostokat blok[7000];
int cmp(prostokat a, prostokat b)
{
    return a.downy<b.downy || (a.downy==b.downy && a.downx<b.downx);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            scanf("%d %d %d %d",&blok[i].downx,&blok[i].downy,&blok[i].upx,&blok[i].upy);
            parent[i]=i;
    }
    sort(blok,blok+n,cmp);
    for(int i=0;i<n-1;i++)
    {
            for(int j=i+1;j<n && blok[i].upy>=blok[j].downy;j++)
            {
                    if(( blok[j].downx>blok[i].upx || blok[j].upx<blok[i].downx ) ||
                    ( blok[i].upy==blok[j].downy && ( blok[j].downx==blok[i].upx || blok[j].upx==blok[i].downx )))continue;
                    Union(i,j);
            }
    }
    int licz=0;
    for(int i=0;i<n;i++)if(parent[i]==i)licz++;
    printf("%d",licz);
    return 0;
}
