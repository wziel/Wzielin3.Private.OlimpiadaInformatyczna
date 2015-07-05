#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
int n,m,a,b,c;
long long int price[5000],dist[5000][2];
vector<pair<int,int> >G[2][5000];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){ dist[i][0]=50000000; dist[i][1]=50000000; }
    for(int i=0;i<n;i++)scanf("%lld",&price[i]);
    scanf("%d",&m);
    while(--m>=0)
    {
                 scanf("%d %d %d",&a,&b,&c); a--; b--;
                 G[0][a].push_back(make_pair(b,c));
                 G[1][b].push_back(make_pair(a,c));//graf transponowany
    }
    priority_queue<pair<int,int> >q;
    for(int i=0;i<2;i++)//Dijkstra od tylu i od przodu
    {
            q.push(make_pair(0,0));
            while(!q.empty())
            {
                             a=q.top().second; c=-q.top().first; q.pop();
                             if(c >= dist[a][i])continue;
                             dist[a][i]=c;
                             for(int j=0;j<G[i][a].size();j++)
                             {
                                     b=G[i][a][j].first;
                                     c=G[i][a][j].second;
                                     if(dist[a][i]+c >= dist[b][i])continue;
                                     q.push(make_pair(-dist[a][i]-c,b));
                             }
            }
    }
    int min=50000000;
    for(int i=0;i<n;i++)if(dist[i][0] + dist[i][1] + price[i]/2 < min)
    min=dist[i][0] + dist[i][1] + price[i]/2;
    printf("%d",min);
    return 0;
}
