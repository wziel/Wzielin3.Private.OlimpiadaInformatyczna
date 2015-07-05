#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
int n,nr=1,m,a,b,ojciec[100001],low[100001],syn[100001],pre[100001],tlu[100001];
vector<int>wt[100001];
stack<int>s; 
int main()
{
    scanf("%d %d",&n,&m);   
    while(--m>=0)
    {
                 scanf("%d %d",&a,&b);
                 wt[a].push_back(b);
                 wt[b].push_back(a);
    }s.push(1);
    while(!s.empty())
    {
                     a=s.top(); s.pop();
                     if(pre[a]!=0)continue;
                     pre[a]=nr; tlu[nr]=a; nr++;
                     for(int i=0;i<wt[a].size();i++)
                     {
                             if(pre[wt[a][i]]==0)
                             {
                                                  b=wt[a][i];
                                                  ojciec[b]=a;
                                                  s.push(b);
                             }
                     }
    }
    for(int i=0;i<=n;i++)low[i]=pre[i];
    for(int i=n;i>1;i--)
    {
            syn[tlu[i]]++;
            syn[ojciec[tlu[i]]]+=syn[tlu[i]];
            for(int j=0;j<wt[tlu[i]].size();j++)
            {
                    a=wt[tlu[i]][j];
                    if(ojciec[tlu[i]]!=a)low[tlu[i]]=min(pre[a],min(low[tlu[i]],low[a]));
            }
    }syn[tlu[1]]=n;
    
    long long int wynik=2*(n-1),suma;
    vector<int>v;
    for(int j=0;j<wt[1].size();j++)
    {
            if(ojciec[wt[1][j]]==1){ v.push_back(syn[wt[1][j]]); }
    }
    for(int j=0;j<v.size();j++)
    {
            wynik+=v[j]*(n-1-v[j]);
    }
    printf("%lld\n",wynik);
    for(int i=2;i<=n;i++)
    {
            wynik=2*(n-1),suma=n-1;
            vector<int>v;
            for(int j=0;j<wt[i].size();j++)
            {
                    if(ojciec[wt[i][j]]==i && low[wt[i][j]]>=pre[i]){ v.push_back(syn[wt[i][j]]); suma-=syn[wt[i][j]]; }
            }
            wynik+=(suma*(n-1-suma));
            for(int j=0;j<v.size();j++)
            {
                    wynik+=v[j]*(n-1-v[j]);
            }
            printf("%lld\n",wynik);
    }
    return 0;
}
