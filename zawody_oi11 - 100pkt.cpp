#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int n,m,a,b,c,d,T[5001],S[5001],ST[5001];//T - ktory podzbior, S odleglosc w G, ST odleglosc w GT
vector<pair<int,int> >G[5001],GT[5001]; // vi,vj,cost
bool visited[5001];
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){S[i]=100000000; ST[i]=100000000;}
    for(int i=0;i<m;i++)
    {
            scanf("%d %d %d %d",&a,&b,&c,&d); a--; b--;
             G[a].push_back(make_pair( b,c ) );
             G[b].push_back(make_pair( a,d ) );
    }
    priority_queue<pair<int,int> >q;
    q.push(make_pair( 0,0 ));
    S[0]=0; T[0]=-1;
    while(!q.empty())//odleglosci od v0 i podzial na podgrupy w G
    {
                     a=q.top().second; c=-q.top().first; q.pop();
                     if(visited[a]==1)continue;
                     visited[a]=1;
                     for(int i=0;i<G[a].size();i++)
                     {
                             b=G[a][i].first;
                             d=G[a][i].second;
                             if(c+d < S[b])
                             {
                                    S[b]=c+d;
                                    if(a==0)T[b]=b;
                                    else    T[b]=T[a];
                                    q.push(make_pair( -S[b],b ) );
                             }
                     }
    }
    for(int i=0;i<n;i++)for(int j=0;j<G[i].size();j++)//tworzenie GT
    {
            b=G[i][j].first;
            c=G[i][j].second;
            if(T[i]==T[b] || b==0)
            {
                          GT[b].push_back( make_pair( i,c ) );
            }
    }
    q.push(make_pair( 0,0 ));
    ST[0]=0;
    while(!q.empty())//szukanie najkrotszej drogi powrotnej w GT
    {
                     a=q.top().second; c=-q.top().first; q.pop();
                     if(visited[a]==0)continue;
                     visited[a]=0;
                     for(int i=0;i<GT[a].size();i++)
                     {
                             b=GT[a][i].first;
                             d=GT[a][i].second;
                             if(c+d < ST[b])
                             {
                                    ST[b]=c+d;
                                    q.push(make_pair ( -ST[b],b ) );
                             }
                     }
    }
    int min=10000000;
    for(int i=1;i<n;i++)for(int j=0;j<G[i].size();j++)
    {
            b=G[i][j].first;
            c=G[i][j].second;
            if(T[i]!=T[b] && (b!=0 || T[i]!=i) && S[i]+ST[b]+c < min)min=S[i]+ST[b]+c;
    }
    printf("%d",min);
    return 0;
}
