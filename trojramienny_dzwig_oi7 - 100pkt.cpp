#include<stdio.h>
#include<iostream>
using namespace std;
bool t[500000];
int tab[300001][3];
int main()
{
    int n,p,q,i=1,licz=0;
    scanf("%d%d%d",&p,&q,&n);
    if(p>q) swap(p,q);
    while(i<=n)
    {
              if(t[i]==1)
              {
                         while(t[i]==1)i++;
                         continue;
              } 
              t[i]=1; t[i+p+q]=1;
              tab[licz][0]=i; tab[licz][2]=i+p+q;
              if(t[i+p]==0)
              {
                           t[i+p]=1; 
                           tab[licz][1]=i+p; licz++;
              }
              else
              {
                           t[i+q]=1;
                           tab[licz][1]=i+q; licz++;
              } i++;
    }
    printf("%d\n",licz);
    for(i=0;i<licz;i++) printf("%d %d %d\n",tab[i][0],tab[i][1],tab[i][2]);     
    return 0;
}
