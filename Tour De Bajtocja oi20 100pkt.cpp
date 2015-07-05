#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int n,m,k,a,b,father[1000001],size[1000001];
vector<int>v[2];
int Find(int a)
{
    if(father[a] != a)father[a] = Find(father[a]);
    return father[a];
}
bool Union(int a,int b)
{
    a=Find(a);
    b=Find(b);
    if(a==b)return false;
    if(size[b]>size[a])swap(a,b);
    size[a]+=size[b];
    father[b]=a;
    return true;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){ father[i]=i; size[i]=1; }
    for(int i=0;i<m;i++)
    {
            scanf("%d%d",&a,&b);
            if(a > k && b > k) Union(a,b);
            else
            {
                v[0].push_back(a);
                v[1].push_back(b);
            }
    }
    for(int i=0;i<v[0].size();i++)if(Union(v[0][i],v[1][i]))
    {
                          swap(v[0][i],v[0][v[0].size()-1]);
                          swap(v[1][i],v[1][v[1].size()-1]);
                          v[0].pop_back();
                          v[1].pop_back();
                          i--;
    }
    printf("%d\n",v[0].size());
    for(int i=0;i<v[0].size();i++)printf("%d %d\n",v[0][i],v[1][i]);
    return 0;
}
