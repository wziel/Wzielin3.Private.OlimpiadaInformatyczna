//Wojciech Zieliñski
#include<iostream>
#include<stdio.h>
using namespace std;
char s[500002];
int n,R[500002];
long long int wynik;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<=n;i++)scanf("%c",&s[i]);
    s[0]='#'; s[n+1]='@'; R[0]=0;
    int t=0,i=1,k=0;
    while(i<=n)
    {
            while(s[i-t]!=s[i+1+t] && i>t && i+t<n) t++;
            R[i]=t;
            for(k=1;k<=t && R[i]-k != R[i-k];k++)    R[i+k]=min(R[i]-k,R[i-k]);
            t-=k;
            t=max(0,t);
            i+=k;
    }
    for(int i=0;i<n+2;i++)wynik+=R[i];
    printf("%lld",wynik);
    return 0;
}
