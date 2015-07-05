#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,a,b,sasiad[26][26],jed,akt=1000000,temp;
int bin[26],odp[26],t=0;
int main()
{
    scanf("%d %d",&n,&m); jed=n/2;
    while(--m>=0)
    {
                scanf("%d %d",&a,&b); a--; b--;
                sasiad[a][b]=1;
                sasiad[b][a]=1;
    }
    for(int i=0;i<n/2;i++)bin[i]=1;
    while(bin[n-1]!=2)
    {
               if(jed!=n/2 || t==1)
               {
                           a=1; bin[a]++;
                           while(bin[a]==2 && a<n-1)
                           {
                                           bin[a]=0; jed--;
                                           a++;
                                           bin[a]++;
                           }
                           jed++;
                           t=0;
                           continue;
               }
               t=1;
               temp=0;
               for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(bin[i]==1 && bin[j]==0 && sasiad[i][j]==1)temp++;
               if(temp<akt)
               {
                          akt=temp;
                          for(int i=0;i<n;i++)odp[i]=bin[i];
               }
    }
    for(int i=0;i<n;i++)if(odp[i]==1)printf("%d ",i+1);
    return 0;
}
