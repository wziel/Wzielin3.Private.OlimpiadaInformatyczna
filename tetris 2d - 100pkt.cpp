#include<stdio.h>
#include<iostream>
using namespace std;
int duzew[2540000],malew[2540000];
int n,d,M;
int ZnajdzM(int n)
{
    int k=1;
    while(k<n)k=k*2;
    return k;
}
int Max(int a,int b)
{
    if(a>b)return a;
    else return b;
}
int ZnajdzMax(int p,int k)
{
    int wp=0,wk=0; 
    while(p/2!=k/2)
    {
                   wp=Max(wp,malew[p]);
                   if(p%2==0)wp=Max(wp,duzew[p+1]);
                   p=p/2;
                   
                   wk=Max(wk,malew[k]);
                   if(k%2==1)wk=Max(wk,duzew[k-1]);
                   k=k/2;
    }
    wp=Max(wp,malew[p]); wk=Max(wk,malew[k]);
    wp=Max(wp,wk);
    while(p!=1)
    {
               p=p/2; wp=Max(wp,malew[p]);
    }
    return wp;
}
int WstawMax(int p,int k,int x)
{
    malew[p]=x; malew[k]=x; duzew[p]=x; duzew[k]=x;
    while(p/2!=k/2)
    {
                   if(p%2==0){duzew[p+1]=x; malew[p+1]=x;}
                   p=p/2;
                   duzew[p]=Max(malew[p],Max(duzew[p*2],duzew[p*2+1]));
                   
                   if(k%2==1){duzew[k-1]=x; malew[k-1]=x;}
                   k=k/2;
                   duzew[k]=Max(malew[k],Max(duzew[k*2],duzew[k*2+1]));
    }
    while(p!=1)
    {
               p=p/2;
               duzew[p]=Max(malew[p],Max(duzew[p*2],duzew[p*2+1]));
    }
    return 0;
}
int main()
{
    scanf("%d%d",&d,&n);
    int p,l;
    M=ZnajdzM(d);
    while(--n>=0)
    {
                 scanf("%d%d",&l,&p); l--;
                 WstawMax(M+p,M+p+l,ZnajdzMax(M+p,M+p+l)+1);
    }
    printf("%d",ZnajdzMax(M,M+d-1));
   return 0;
}
