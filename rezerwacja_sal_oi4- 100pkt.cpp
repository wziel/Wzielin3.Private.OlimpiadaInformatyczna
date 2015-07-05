#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int tab[30001];
pair<int,int>wyklad[10000];
int max(int a,int b)
{
    if(a>b)return a;
    return b;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%d",&wyklad[i].second,&wyklad[i].first);  //second-poczatek, first-koniec
    sort(wyklad,wyklad+n);
    tab[0]=0;
    int k=0,i=1;
    while(true)
    {   
            if(wyklad[k].first==i)
            {
                                  tab[i]=max(tab[i],max(wyklad[k].first-wyklad[k].second+tab[wyklad[k].second],tab[i-1]));
                                  if(k==n-1)break;
                                  i--;
                                  k++;
            }
            else tab[i]=max(tab[i],tab[i-1]);
            i++;
    }
    printf("%d",tab[i]);
    return 0;
}
