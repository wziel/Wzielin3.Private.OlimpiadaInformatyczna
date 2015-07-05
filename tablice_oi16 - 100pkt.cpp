#include<stdio.h>
using namespace std;
int ktory[2000002][2],tab[1000][1000][2];
int main()
{
    int t,x,y;
    scanf("%d",&t);
    while(t>0)
    {
              t--;
              int n,m; bool b=0;
              scanf("%d%d",&n,&m);
              scanf("%d",&x); x+=1000000; tab[0][0][0]=x;
              ktory[x][0]=x; ktory[x][1]=x;
              for(int j=1;j<m;j++)
              {
                      scanf("%d",&y); y+=1000000;  tab[0][j][0]=y;
                      ktory[y][0]=x; ktory[y][1]=y;
              }
              for(int i=1;i<n;i++)
              {
                      scanf("%d",&x); x+=1000000; tab[i][0][0]=x;
                      ktory[x][0]=x; ktory[x][1]=ktory[tab[i-1][0][0]][1];
                      for(int j=1;j<m;j++)
                      {
                              scanf("%d",&y); y+=1000000;  tab[i][j][0]=y;
                              ktory[y][0]=x; ktory[y][1]=ktory[tab[i-1][j][0]][1];
                      }
              }
              for(int i=0;i<n;i++)for(int j=0;j<m;j++)
              {
                      scanf("%d",&tab[i][j][1]); tab[i][j][1]+=1000000;
              }
              for(int i=0;i<n;i++)for(int j=0;j<m-1;j++)
              {
                      if(ktory[tab[i][j][1]][0]!=ktory[tab[i][j+1][1]][0])
                      {
                             b=1; j=m; i=n; break;                       
                      }
              }
              if(b==1)
              {
                      printf("NIE\n");
                      continue;
              }
              for(int j=0;j<m;j++)for(int i=0;i<n-1;i++)
              {
                      if(ktory[tab[i][j][1]][1]!=ktory[tab[i+1][j][1]][1])
                      {
                                                                               b=1; j=m; i=n; printf("NIE\n"); break;                       
                      }
              }
              if(b==0)printf("TAK\n");
    }
    return 0;
}
