#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int n,m,tab[101][101],sprawdzone[101][101],wynik,x,y;
int kx[4]={0,0,1,-1},ky[4]={-1,1,0,0};
pair <int,int> kolej[10001],k;

int cmp(pair<int,int> a,pair<int,int> b)
{
    return (tab[a.first][a.second]<tab[b.first][b.second]);
}
int isLegal(int y,int x)
{
    return (y<n && x<m && y>=0 && x>=0);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
            scanf("%d",&tab[i][j]);
            kolej[i*m+j].first=i;
            kolej[i*m+j].second=j;
            sprawdzone[i][j]=-1;
    }
    sort(kolej,kolej+n*m,cmp);
    for(int i=0;i<n*m;i++)
    {
            stack< pair<int,int> >s,zwieksz;
            s.push(kolej[i]);
            int min=100000;
            while(!s.empty())
            {
                             k=s.top(); s.pop();
                             sprawdzone[k.first][k.second]=i;
                             for(int p=0;p<4;p++)
                             {
                                     if(isLegal(k.first+ky[p],k.second+kx[p]))
                                     {
                                            x=k.second+kx[p],y=k.first+ky[p];
                                            if(sprawdzone[y][x]==i)continue;
                                            if(tab[y][x]<tab[k.first][k.second]){min=0; break;}
                                            if(tab[y][x]==tab[k.first][k.second])
                                            {
                                                  s.push(make_pair(y,x));
                                                  sprawdzone[y][x]=i;
                                            }
                                            if(tab[y][x]>tab[k.first][k.second] && tab[y][x]-tab[k.first][k.second]<min)
                                            {
                                                    min=tab[y][x]-tab[k.first][k.second];
                                            }
                                     }
                                     else {min=0; break;}
                             }
                             if(min==0)break;
                             zwieksz.push(k);
            }
            if(min!=0)
            {
                      int obszar=0;
                      while(!zwieksz.empty())
                      {
                              obszar++;
                              k=zwieksz.top(); zwieksz.pop();
                              tab[k.first][k.second] += min;
                      }
                      wynik += obszar*min;
            }
    }
    printf("%d",wynik);
    return 0;
}
