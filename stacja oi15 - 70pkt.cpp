#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int n,a,b,ojciec[1000001],post[1000001],depost[1000001],sons[1000001],sumdist[1000001],max[2];
vector<int>v[1000001];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
            sons[i]=1;
    }sons[n]=1;
    queue<int>q; q.push(1); b=1;
    while(!q.empty())
    {
             a=q.front(); q.pop();
             post[a]=b; depost[b]=a; b++;
             for(int i=0;i<v[a].size();i++) if(post[v[a][i]]==0) { q.push(v[a][i]); ojciec[v[a][i]]=a; }
    }
    for(int i=n;i>1;i--)
    {
            sons   [ojciec[depost[i]]]+=sons[depost[i]];
            sumdist[ojciec[depost[i]]]+=sons[depost[i]]+sumdist[depost[i]];
    }
    int max[2]={1,sumdist[1]};
    for(int i=2;i<=n;i++)
    {
            printf("%d %d %d %d %d\n",i,depost[i],ojciec[depost[i]],sons[depost[i]], sumdist[depost[i]]);
            sumdist[depost[i]]=sumdist[ojciec[depost[i]]]+n-2*sons[depost[i]];
            printf("%d %d %d %d %d\n",i,depost[i],ojciec[depost[i]],sons[depost[i]], sumdist[depost[i]]);
            if(sumdist[depost[i]]>max[1])
            {
                                         max[1]=sumdist[depost[i]];
                                         max[0]=depost[i];
            }
    }
    printf("%d",max[0]);
    return 0;
}
