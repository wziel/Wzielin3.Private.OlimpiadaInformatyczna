//Wojciech Zieliñski
#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int n,m,r,t,k,a,b,match[1002],prev[1002],punktyKarne,problemsSolved,value;
int visited[1002];
bool sthChanged=true;
vector<int>v[501],wynik[501];
queue<int>q;
int main()
{
    scanf("%d %d %d %d %d",&n,&m,&r,&t,&k);
    while(--k>=0)
    {
                 scanf("%d %d",&a,&b);
                 v[a].push_back(n+b); 
    }
    for(k=0;k<=t-r && sthChanged;k+=r)
    {
                 sthChanged=false;
                 for(int i=1;i<=n;i++)
                 {
                         q.push(i);
                         prev[i]=0;
                         value=k/r*n+i;
                         visited[i]=value;
                         while(!q.empty())
                         {
                                       a=q.front(); q.pop();
                                       for(int j=0;j<v[a].size();j++)if(visited[v[a][j]]!=value)
                                       {
                                                       visited[v[a][j]]=value;
                                                       prev[v[a][j]]=a;
                                                       if(match[v[a][j]]==0)
                                                       {
                                                               punktyKarne+=k;
                                                               problemsSolved++;
                                                               sthChanged=true;
                                                               for(a=v[a][j];a>0;a=prev[prev[a]])match[a]=prev[a];
                                                               while(!q.empty())q.pop();
                                                               break;
                                                       }
                                                       if(visited[match[v[a][j]]]==value)continue;
                                                       visited[match[v[a][j]]]=value;
                                                       prev[match[v[a][j]]] = v[a][j];
                                                       q.push(match[v[a][j]]); 
                                       }
                         }
                 }
    }
    printf("%d %d\n",problemsSolved,punktyKarne+r*problemsSolved);
    for(int i=n+1;i<=n+m;i++)if(match[i]!=0)
    {
            wynik[match[match[i]]].push_back(match[i]);
            wynik[match[match[i]]].push_back(i-n);
            match[match[i]]++; 
    }
    for(int i=0;i<501;i++)for(int j=0;j<wynik[i].size();j+=2)printf("%d %d %d\n",wynik[i][j],wynik[i][j+1],i*r);
    return 0;
}
