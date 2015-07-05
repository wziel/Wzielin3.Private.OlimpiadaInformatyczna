#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
int n,m,k,a,b,v,u,licz,wynik[100000],vis[100000];
priority_queue< pair<int,int> > q;
queue<int>qu;
vector<int>sasiad[100000];
int main()
{
    scanf("%d %d %d %d %d",&n,&m,&k,&a,&b); k--;
    while(--m>=0)
    {
                 scanf("%d %d",&v,&u); v--; u--;
                 sasiad[v].push_back(u);
                 sasiad[u].push_back(v);
    }
    wynik[k]=0; qu.push(k); 
    while(!qu.empty())
    {
                      v=qu.front(); qu.pop();
                      for(int i=0;i<sasiad[v].size();i++)if(wynik[sasiad[v][i]]==0 && sasiad[v][i]!=k)
                      {
                              qu.push(sasiad[v][i]);
                              wynik[sasiad[v][i]] = wynik[v]+1;
                              if(wynik[v]%2==1)q.push( make_pair( -(wynik[v]+1)/2 *b, sasiad[v][i]) );
                      }
    }
    if(2*a <= b){for(int i=0;i<n;i++)printf("%d\n",wynik[i]*a); return 0;}
    for(int i=0;i<n;i++)
    {
            if(wynik[i]%2==0)wynik[i] = wynik[i]/2 * b;
            else             wynik[i] = (wynik[i]-1)/2 *b + a;
    }
    licz=1;
    while(!q.empty())
    {
                     v=q.top().second; q.pop(); 
                     vis[v]=licz;
                     for(int i=0;i<sasiad[v].size();i++) vis[sasiad[v][i]]=licz;
                     for(int i=0;i<sasiad[v].size();i++)for(int j=0;j<sasiad[sasiad[v][i]].size();j++)
                     if(vis[sasiad[sasiad[v][i]][j]]!=licz && wynik[v]+b < wynik[sasiad[sasiad[v][i]][j]])
                     {
                             u=sasiad[sasiad[v][i]][j];
                             wynik[u]=wynik[v]+b;
                             q.push(make_pair( -wynik[u],u));
                     }
                     licz++;
    }
    for(int i=0;i<n;i++)printf("%d\n",wynik[i]);
    return 0;
}
