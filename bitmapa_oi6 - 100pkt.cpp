#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
int tab[183][183];
int n,m;
char c;
bool isLegal(int y,int x){ return (y>=0 && y<n && x>=0 && x<m && tab[y][x]==-1); }
int kx[4]={1,-1,0,0};
int ky[4]={0,0,1,-1};
int main()
{
    memset(tab,-1,sizeof tab);
    scanf("%d%d",&n,&m);
    queue< pair<int,int> > q;
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<m;j++)
            {
                    do{c=getchar();}while(c!='0' && c!='1');
                    if(c=='1')
                    {
                              tab[i][j]=0;
                              q.push(make_pair(i,j));
                    }
            }
    }
    pair<int,int>k;
    while(!q.empty())
    {
                     k=q.front();
                     q.pop();
                     for(int i=0;i<4;i++)
                     {
                             if(isLegal(k.first+ky[i],k.second+kx[i]))
                             {
                                       q.push(make_pair (k.first+ky[i],k.second+kx[i]) );
                                       tab[k.first+ky[i]][k.second+kx[i]]=tab[k.first][k.second]+1;
                             }
                     }
    }
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<m;j++)printf("%d ",tab[i][j]);
            printf("\n");
    }
    return 0;
}
