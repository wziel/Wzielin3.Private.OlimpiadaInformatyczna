#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
struct def
{
       int cena,odleglosc;
};
int main()
{
    int p,n;
    scanf("%d %d",&p,&n);
    def stacja[n],k;
    for(int i=0;i<n;i++)
    {
            scanf("%d %d",&stacja[i].cena,&stacja[i].odleglosc);
    }
    stack<def>s;
    k.cena=0;
    s.push(k); //straznik
    s.push(stacja[n-1]);
    for(int i=n-2;i>=0;i--)
    {
            while(s.top().cena>stacja[i].cena)
            {
                     if(s.top().odleglosc+stacja[i].odleglosc<=p)
                     {
                               stacja[i].odleglosc += s.top().odleglosc;   
                               s.pop();                     
                     }
                     else
                     {
                               s.top().odleglosc -= (p-stacja[i].odleglosc);
                               stacja[i].odleglosc=p; break;
                     }
            }
            s.push(stacja[i]);
    }
    p=0;
    while(s.size()>1)
    {
                     p += s.top().odleglosc * s.top().cena;
                     s.pop();
    }
    printf("%d",p);
    return 0;
}
