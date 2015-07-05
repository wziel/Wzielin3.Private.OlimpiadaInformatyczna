#include<stdio.h>
#include<iostream>
using namespace std;
int ile_waga[202];
int main()
{
    int w,n,i,j,licz=0,k;
    scanf("%d %d",&w,&n);
    for(i=0;i<n;i++)
    {
            scanf("%d",&k);
            ile_waga[k]++;
    }
    i=4;j=201;
    while(i<j)
    {
              if(ile_waga[i]==0){i++; continue;}
              if(ile_waga[j]==0){j--; continue;}
              if(i+j>w)
              {
                          licz += ile_waga[j];
                          ile_waga[j]=0;
                          j--;
                          continue;
              }
              if(ile_waga[i]<ile_waga[j])
              {
                                 ile_waga[j] -= ile_waga[i]; 
                                 licz += ile_waga[i];
                                 ile_waga[i]=0;
                                 i++;
                                 continue;
              }
              ile_waga[i] -= ile_waga[j];
              licz += ile_waga[j];
              ile_waga[j]=0;
              j--;
    }
    if(2*i>w)licz += ile_waga[i];
    else
    {
        licz += ile_waga[i]/2;
        if(ile_waga[i]%2==1)licz++;
    }
    printf("%d",licz);
    return 0;
}
