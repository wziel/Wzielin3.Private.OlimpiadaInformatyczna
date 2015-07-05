#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
int tab[1000][1000],n,typ,x,y,wynik[2];//[1]-grzbiet,[0]-dolina
bool visited[1000][1000];
bool IsLegal(int x,int y)
{
     return x>=0 && y>=0 && x<n && y<n;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&tab[i][j]);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)
    {
            if(visited[i][j]==1)continue;
            visited[i][j]=1;
            queue<pair<int,int> >q;
            q.push(make_pair(i,j));
            typ=0;
            while(!q.empty())
            {
                      x=q.front().first; y=q.front().second; q.pop();
                      for(int ii=x-1;ii<=x+1;ii++)for(int jj=y-1;jj<=y+1;jj++)if(IsLegal(ii,jj))
                      {
                              if(visited[ii][jj]==0 && tab[ii][jj]==tab[x][y])
                              {
                                     visited[ii][jj]=1;
                                     q.push(make_pair(ii,jj));
                              }
                              if(tab[ii][jj]!=tab[x][y])
                              {
                                      if(typ==0)
                                      {
                                                if(tab[ii][jj]>tab[x][y])typ=-1;
                                                else typ=1;
                                      }
                                      else if((typ==1 && tab[ii][jj]>tab[x][y]) || (typ==-1 && tab[ii][jj]<tab[x][y]))typ=2;
                              }
                      }
            }
            if(typ==0)        {wynik[0]++; wynik[1]++;}
            else if(typ==-1)   wynik[0]++;
            else if(typ==1)    wynik[1]++;
    }
    printf("%d %d",wynik[1], wynik[0]);
    return 0;
}
