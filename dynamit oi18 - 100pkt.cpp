//Wojciech Zieliñski
#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#define INF 300002
using namespace std;
vector<int>layer[INF];
queue<int>q;
int n,m,a,b,maxLay,v,u;
struct Vert
{
       vector<int>son;
       int layer,father;
       bool dynamite;
       int dynaDist,fireRange;
}vert[INF];
bool Check(int time)
{
     int detonate=m;
     for(int i=maxLay;i>=0;i--)for(int j=0;j<layer[i].size();j++)
     {
             v=layer[i][j];
             vert[v].fireRange=-INF;
             if(vert[v].dynamite)vert[v].dynaDist=0;
             else                vert[v].dynaDist=-INF;
             for(int k=0;k<vert[v].son.size();k++)
             {
                     u=vert[v].son[k];
                     if(vert[u].fireRange > 0) vert[v].fireRange= max(vert[v].fireRange, vert[u].fireRange-1);
                                               vert[v].dynaDist = max(vert[v].dynaDist, vert[u].dynaDist+1);
             }
             if(vert[v].dynaDist <= vert[v].fireRange)vert[v].dynaDist = -INF;
             if(vert[v].dynaDist == time)
             {
                                 if(--detonate<0)return false;
                                 vert[v].dynaDist = -INF;
                                 vert[v].fireRange = time;
             }
     }
     if(vert[1].dynaDist>=0 && detonate==0)return false;
     return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&vert[i].dynamite);
    for(int i=0;i<n-1;i++)
    {
            scanf("%d%d",&a,&b);
            vert[a].son.push_back(b);
            vert[b].son.push_back(a);
    }
    vert[1].layer=0;
    vert[1].father=0;
    q.push(1);
    while(!q.empty())
    {
                     a=q.front(); q.pop();
                     layer[vert[a].layer].push_back(a);
                     maxLay=vert[a].layer;
                     for(int i=0;i<vert[a].son.size();i++)
                     {
                             if(vert[a].son[i]==vert[a].father)
                             {
                                          swap(vert[a].son[i],vert[a].son[vert[a].son.size()-1]);
                                          vert[a].son.pop_back();
                                          i--; continue;
                             }
                             b=vert[a].son[i];
                             q.push(b);
                             vert[b].father=a;
                             vert[b].layer=vert[a].layer+1;
                     }
    }
    a=-1; b=n/m;
    while(a+1<b)
    {
                if(Check( (a+b)/2 ))b=(a+b)/2;
                else a=(a+b)/2; 
                
    }
    printf("%d",b);
    return 0;
}
