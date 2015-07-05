#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int n,m,p,k,a,b,c,d,swordstemp,swords,t,t2,city,sword[13]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096},miecz[200];
vector<pair<int,pair<int,int> > >sasiad[200];//time,city,monsters
priority_queue<pair<int,pair<int,int> > >q;
bool visited[200][8192];
bool Have_Sword(int x,int sum)
{
     int temp=sum | x; //alternatywa logiczna - operacja na bitach - suma
     if(sum==temp)return 1;
     return 0;
}
int main()
{
    scanf("%d %d %d %d",&n,&m,&p,&k);
    while(--k>=0)
    {
                 scanf("%d %d",&a,&b); a--;
                 while(--b>=0)
                 {
                              scanf("%d",&c); c--;
                              miecz[a]=miecz[a] | sword[c];
                 }
    }
    while(--m>=0)
    {
                 d=0;
                 scanf("%d %d %d %d",&a,&b,&t,&k); a--; b--;
                 while(--k>=0)
                 {
                              scanf("%d",&c); c--;
                              d= d | sword[c];
                 }
                 sasiad[a].push_back(make_pair(t,make_pair(b,d)));
                 sasiad[b].push_back(make_pair(t,make_pair(a,d)));
    }
    visited[0][miecz[0]]=1;
    q.push(make_pair(0,make_pair(0,miecz[0]))); 
    while(!q.empty())
    {
                     t=q.top().first,city=q.top().second.first,swords=q.top().second.second; q.pop();
                     if(city==n-1){printf("%d",-t); return 0;}
                     for(int i=0;i<sasiad[city].size();i++)
                     {
                             t2=sasiad[city][i].first;
                             k =sasiad[city][i].second.first;
                             m =sasiad[city][i].second.second;
                             swordstemp=swords | miecz[k];
                             if(Have_Sword(m,swords)==0 || visited[k][swordstemp]==1)continue;
                             visited[k][swordstemp]=1;
                             q.push(make_pair(t-t2,make_pair(k,swordstemp)));
                     }
    }
    printf("-1");
    return 0;
}
