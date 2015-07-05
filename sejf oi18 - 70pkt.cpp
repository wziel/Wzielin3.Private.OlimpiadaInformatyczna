//Wojciech Zieliñski
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
long long int NWD(long long int a,long long int b)
{
     if(a<b)swap(a,b);
     while(b>0)
     {
               a%=b;
               swap(a,b);
     }
     return a;
}
long long int n,n2,a,k,wynik;
vector<long long int>v,dzielnik;
set<long long int>s;
set<long long int>::iterator it;
bool found;
int main()
{
    scanf("%lld%lld",&n,&k); n2=n;
    while(--k>0){scanf("%lld",&a); v.push_back(a);}
    scanf("%lld",&a);
    n=NWD(n,a);
    for(int i=0;i<v.size();i++)s.insert(NWD(v[i],n));
    for(long long int i=1;i<=sqrt(n);i++)if(n%i==0)
    {
            a = i;
            found = true;
            for(it=s.begin();it!=s.end();it++)if((*it)%a==0){found = false; break;}
            if(found)
            {
                     printf("%lld",n2/a); 
                     return 0;
            }
            a = n/i;
            found = true;
            for(it=s.begin();it!=s.end();it++)if((*it)%a==0){found = false; break;}
            if(found)wynik=n2/a;
    }
    printf("%lld",wynik); 
    return 0;
}
