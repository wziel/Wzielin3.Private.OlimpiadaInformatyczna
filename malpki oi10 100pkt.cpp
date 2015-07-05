#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int n,m,a,b,c,ojciec[200000],rece[200000][2],moment[400000][2],ile[200000],spadl[200000],vis[200000];
vector<int>v[200000];
int Find(int x)
{
    if(ojciec[x]!=x)ojciec[x]=Find(ojciec[x]);
    return ojciec[x];
}
int Union(int a,int b)
{
    a=Find(a); b=Find(b);
    if(ile[a]<ile[b])swap(a,b);
    ojciec[b]=a;
    ile[a]+=ile[b]+1;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
            scanf("%d %d",&rece[i][0],&rece[i][1]); rece[i][0]--; rece[i][1]--;
            ojciec[i]=i;
            spadl[i]=m;
    }
    for(int i=0;i<m;i++)
    {
            scanf("%d %d",&moment[i][0],&a); moment[i][0]--;
            moment[i][1]=rece[moment[i][0]][a-1];
            rece[moment[i][0]][a-1]=-1;
    }
    for(int i=0;i<n;i++)for(int j=0;j<2;j++)if(rece[i][j]>-1 && Find(i)!=Find(rece[i][j]))
    {
             v[i].push_back(rece[i][j]);
             v[rece[i][j]].push_back(i);
             Union(i,rece[i][j]);
    }
    int mm=m;
    while(--m>=0)
    {
                 a=moment[m][0]; b=moment[m][1];
                 a=Find(a); b=Find(b);
                 if(a!=b)
                 {
                         c=-1;
                         if(a==Find(0))c=b;
                         if(b==Find(0))c=a;
                         if(c>-1)
                         {
                                 queue<int>q; q.push(c);  spadl[c]=m;
                                 while(!q.empty())
                                 {
                                                  c=q.front(); q.pop();
                                                  for(int i=0;i<v[c].size();i++)if(spadl[v[c][i]]>m)
                                                  {
                                                          spadl[v[c][i]]=m;
                                                          q.push(v[c][i]);
                                                  }
                                 }
                         }
                         Union(a,b);
                         v[a].push_back(b);
                         v[b].push_back(a);
                 }
    }
    for(int i=0;i<n;i++)
    {
            if(spadl[i]==mm)printf("-1\n");
            else printf("%d\n",spadl[i]);
    }
    return 0;
}
