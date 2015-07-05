//Wojciech Zieliñski
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
bool tab[3001][3001];
int main()
{
    int n,m,a,b,wywalone=0;
    scanf("%d%d",&n,&m);
    vector<int>v;
    for(int i=1;i<=n;i++)v.push_back(i);
    for(int i=0;i<m;i++)
    {
            scanf("%d%d",&a,&b);
            tab[a][b]=1; tab[b][a]=1;
    }
    for(int i=0;i<v.size()-1;i++)
    {
            for(int j=i+1;j<v.size();j++)
            {
                    if(tab[v[i]][v[j]]==0)
                    {
                          swap(v[j],v.back()); v.pop_back();
                          swap(v[i],v.back()); v.pop_back();
                          wywalone++;
                          if(wywalone*3==n)i=v.size()+100;
                          i--; break;
                    }
            }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n/3;i++)printf("%d ",v[i]);
    return 0;
}
