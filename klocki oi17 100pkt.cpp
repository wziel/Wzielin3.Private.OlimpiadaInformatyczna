#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,a,b,tab[1000000];
long long int sum[1000000];
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",&tab[i]);
    while(--m>=0)
    {
                 scanf("%d",&a);
                 sum[0]=tab[0]-a;
                 int max=0,last,akt;
                 long long int suma;
                 for(int i=1;i<n;i++)
                 {
                         sum[i]=tab[i]-a;
                         if(sum[i-1]>=0)sum[i]+=sum[i-1];
                 }
                 for(int i=n-1;i>=0;i--)if(sum[i]>=0)
                 {
                         last=i;
                         i--;
                         suma=sum[last];
                         while(i>=0 && sum[i]>=0)i--;
                         akt=last-i;
                         if(akt>max)max=akt;
                         while(i<last)
                         {
                                    while(i>=0 && sum[i]>=0)i--;
                                    akt=last-i;
                                    if(akt>max)max=akt;
                                    if(i<0)break;
                                    if(sum[i]+suma>=0)
                                    {
                                                  suma+=sum[i];
                                                  i--;
                                    }
                                    else
                                    {
                                                  suma-=tab[last]-a;
                                                  last--;
                                    }
                         }
                         if(akt>max)max=akt;
                 }
                 printf("%d ",max);
    }
    return 0;
}
