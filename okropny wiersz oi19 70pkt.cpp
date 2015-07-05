#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int n,q;
long long int hasz[500001],potegi[500001];
char word[500001];
vector<int>dzielniki[500001]; 
void RobTabliceHaszy()
{
     int base = 27;
     long long int suma=0;
     potegi[0]=1;
     for(int i=1;i<=n;i++)
     {
             potegi[i]=potegi[i-1]*base;
             suma*=base;
             suma+=word[i]-'a'+1;
             hasz[i]=suma;
     }
}
bool RownePodslowa(int a,int b,int l)
{
      a--; b--;
      long long int tmp1=hasz[a]*potegi[l] , tmp2=hasz[b]*potegi[l];
      if(hasz[a+l]-tmp1 == hasz[b+l]-tmp2)return true;
      return false;
}
int main()
{
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++)scanf("%c",&word[i]);
    RobTabliceHaszy();
    for(int i=1;i<=n/2;i++)for(int j=i;j<=n;j+=i)dzielniki[j].push_back(i);
    
    scanf("%d",&q);
    int a,b,k,i; 
    while(--q>=0)
    {
                scanf("%d%d",&a,&b);
                k=b-a+1;
                for(i=0;i<dzielniki[k].size();i++)
                if(RownePodslowa(a,a+dzielniki[k][i],k-dzielniki[k][i]))
                {
                             printf("%d\n",dzielniki[k][i]);
                             break;               
                }
                if(i==dzielniki[k].size())printf("%d\n",k);
    }
    return 0;
}
