#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int n,m,a,b,moc[6],warstwa[40000],nr[6]={0,0,1,1,5,-1}; //tablica pomocnicza do przydzielania v odleglych o 2 od koncow
vector<int>sasiad[40000];
queue<int>q;
int main()
{
    scanf("%d %d",&n,&m); moc[0]=1; moc[5]=1;
    memset(warstwa,-1,sizeof warstwa);
    for(int i=0;i<m;i++)
    {
            scanf("%d %d",&a,&b); a--; b--;
            sasiad[a].push_back(b);
            sasiad[b].push_back(a);
    }
    for(int j=0;j<6;j+=3) //przydzielam do warstw wierzcholki odlegle o 2 od 1 i 2
    {
            q.push(nr[j]); warstwa[nr[j]]=nr[j+1]; moc[nr[j+1]]=1;
            while(!q.empty())
            {
                     a=q.front(); q.pop();
                     for(int i=0;i<sasiad[a].size();i++)
                     {
                             if(warstwa[sasiad[a][i]]==-1){ warstwa[sasiad[a][i]]=warstwa[a]+nr[j+2]; moc[warstwa[a]+nr[j+2]]++; }
                             if(warstwa[a]==nr[j+1])q.push(sasiad[a][i]);
                     }
            }
    }
    if(moc[1]>moc[4])a=2; //wierzcholki bardziej odlegle przydzielam do warstwy ktora ma wiecej sasiadow
    else             a=3;
    for(int i=2;i<n;i++)if(warstwa[i]==-1)moc[a]++;
    long long int wynik=0;
    for(int i=0;i<5;i++)//licze wynik
    {
            wynik+=moc[i]*(moc[i]-1)/2;
            wynik+=moc[i]*moc[i+1];
    }
    printf("%lld",wynik-m);
    return 0;
}
