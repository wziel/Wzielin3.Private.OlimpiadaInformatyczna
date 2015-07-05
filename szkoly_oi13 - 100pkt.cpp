#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int,int> >edge[400];//f- do kogo, s-za ile
int n,a,b,c,d,dist[400],poprzednik[400],wynik;
bool used[200];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            scanf("%d %d %d %d",&a,&b,&c,&d); a--; b--; c--;
            for(int j=b;j<a;j++) edge[i].push_back(make_pair(j+n,(a-j)*d));
            for(int j=a;j<=c;j++)edge[i].push_back(make_pair(j+n,(j-a)*d));
    }
    for(int i=0;i<n;i++)
    {
            for(int i=0;i<n*2;i++)dist[i]=100000000;
            poprzednik[i]=-1;
            dist[i]=0;
            queue<int>q;
            q.push(i);
            while(!q.empty())
            {
                                 a=q.front(); q.pop();
                                 for(int j=0;j<edge[a].size();j++)
                                 {
                                         if(dist[a]+edge[a][j].second >= dist[edge[a][j].first])continue;
                                         dist[edge[a][j].first]=dist[a]+edge[a][j].second;
                                         poprzednik[edge[a][j].first]=a;
                                         q.push(edge[a][j].first);
                                 }
            }
            int min[2]={100000000,-1};
            for(int j=0;j<n;j++)if(used[j]==0 && dist[j+n]<min[0])
            {
                    min[0]=dist[j+n];
                    min[1]=j+n;
            }
            if(min[1]==-1){printf("NIE"); return 0;}
            used[min[1]-n]=1;
            a=min[1];
            while(poprzednik[a]!=-1)
            {
                        for(int j=0;j<edge[poprzednik[a]].size();j++)if(edge[poprzednik[a]][j].first==a)
                        {
                                b=edge[poprzednik[a]][j].second;
                                edge[poprzednik[a]].erase(edge[poprzednik[a]].begin()+j);
                        }
                        wynik=wynik+b;
                        edge[a].push_back(make_pair(poprzednik[a],-b));
                        a=poprzednik[a];
            }
    }
    printf("%d",wynik);
    return 0;
}
