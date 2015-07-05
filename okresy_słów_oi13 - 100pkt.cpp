#include<iostream>
#include<stdio.h>
using namespace std;
int k,a,pref[1000000],d[1000000];
long long int suma;
char s[1000000];
int main()
{
    scanf("%d",&k);getchar();
    for(int i=0;i<k;i++)scanf("%c",&s[i]);
    for(int i=1;i<k;i++)
    {
            a=i;
            while(a!=0 && (s[i]!=s[pref[a-1]]))a=pref[a-1];
            if(a!=0)
            {
                    pref[i]=pref[a-1]+1;
                    if(d[pref[i]-1] > 0) d[i]=d[pref[i]-1];
                    else                 d[i]=pref[i];
            }
            if(d[i]>0)suma+=i+1-d[i];
    }
    printf("%lld",suma);
    return 0;
}
