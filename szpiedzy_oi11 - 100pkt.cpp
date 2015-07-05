#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
int n,tab[1000001],indeg[1000001],wynik=0,a;
queue<int>q;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            scanf("%d",&tab[i]); tab[i]--;
            indeg[tab[i]]++;
    }
    for(int i=0;i<n;i++)if(indeg[i]==0)q.push(i);
    while(!q.empty())
    {
            a=q.front(); q.pop(); indeg[a]=-1;
            a=tab[a];
            if(indeg[a]<0)continue;
            indeg[a]=-1; wynik++;
            a=tab[a];
            indeg[a]--;
            if(indeg[a]==0)q.push(a);
    }
    for(int i=0;i<n;i++)if(indeg[i]>0)
    {
            a=i;
            int licz=0;
            do
            {
                indeg[a]=-1;
                a=tab[a];
                licz++;
            }while(a!=i);
            wynik+= licz/2;
    }
    printf("%d",wynik);
    return 0;
}
