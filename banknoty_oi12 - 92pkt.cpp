#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
int tab[200][20001][2],kasa[200][2];
int main()
{
    int n,ile,kk,i,k;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&kasa[i][0]);
    for(int i=0;i<n;i++)scanf("%d",&kasa[i][1]);
    scanf("%d",&ile);
    memset(tab,-1,sizeof tab);
    for(int i=0;i<n;i++)
    {
            tab[i][0][0]=0;
            tab[i][0][1]=0;
    }
    for(k=1;k<=ile;k++)
    {
            if(k%kasa[0][0]==0)
            {
                     if(k/kasa[0][0]<=kasa[0][1])
                     {
                                tab[0][k][0]=k/kasa[0][0];
                                tab[0][k][1]=tab[0][k][0];
                     }
                     else break;
            }
    }
    for(i=1;i<n;i++)
    {
            for(k=1;k<kasa[i][0];k++) if(tab[i-1][k][0]!=-1)
            {
                      tab[i][k][0]=0;
                      tab[i][k][1]=tab[i-1][k][1];
            }
            for(k=kasa[i][0];k<=ile;k++)
            {
                    kk=(k-k%kasa[i][0])/kasa[i][0];
                    if(kk>kasa[i][1])kk=kasa[i][1];
                    while(kk>0)
                    {
                                if(tab[i-1][k-kk*kasa[i][0]][0]!=-1 && (tab[i-1][k-kk*kasa[i][0]][1]+kk<tab[i][k][1] || tab[i][k][1]<1))
                                {
                                       tab[i][k][0]=kk; 
                                       tab[i][k][1]=tab[i-1][k-kk*kasa[i][0]][1]+kk;
                                }
                                kk--;
                    }
            }
    }
   k=1000000;
   for(int i=0;i<n;i++)
   {
           if(tab[i][ile][1]!=-1 && tab[i][ile][1]<k)
           {
                                 k=tab[i][ile][1]; kk=i;
           }
    }
    stack<int>s;
    for(i=n-1;i>kk;i--)s.push(0);
    k=ile;
    printf("%d\n",tab[i][k][1]);
    while(i>=0)
    {
               s.push(tab[i][k][0]);
               if(tab[i][k]!=0)
               {
                               k -= tab[i][k][0]*kasa[i][0];
               } 
               i--;
    }
    while(!s.empty())
    {
                     printf("%d ",s.top()); s.pop();
    }
    return 0;
}
