#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
char tab[1000000];
int main()
{
    int n,p,q,x,y,min,akt,wynik=0,mm;
    scanf("%d %d %d %d %d",&n,&p,&q,&x,&y); akt=p; min=0;
    for(int i=0;i<n;i++)
    {
            do{scanf("%c",&tab[i]);}while(tab[i]!='-' && tab[i]!='+');
            if(tab[i]=='-')
            {
                           akt--; if(akt<min)min=akt;
            }
            else akt++;
    }
    if(akt>q)wynik += x*((akt-q)/2);
    else if(akt<q)
    {
         wynik += x*((q-akt)/2);
         min += (q-akt);
    }
    akt=y; mm=0;
    vector<int>v; v.push_back(0);
    for(int i=n-1;i>=0 && v.size()<=-min;i--)
    {
            if(tab[i]=='+')
            {
                           if(mm==0)v.push_back(akt);
                           else mm++;
            }
            else mm--;
            akt += y;
    }
    min=-min;
    mm=1000000000;
    akt=min;
    while(akt>0)
    {
                if((min-akt)*x+v[akt]<mm)mm=(min-akt)*x+v[akt];
                akt=akt-2;
    }
    if(mm!=1000000000)wynik += mm;
    printf("%d",wynik);
    return 0;
}
