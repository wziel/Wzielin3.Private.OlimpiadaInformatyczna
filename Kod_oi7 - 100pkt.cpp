#include<stdio.h>
#include<vector>
using namespace std;

int n,k;
vector<char>v;
vector<int>ile[20];
int m[20];

int inicjuj_dane(int x)
{
     if(x>k)return 0;
     for(int i=0;i<x;i++)
     {
             ile[x].push_back(m[i] * m[x-i-1]);
             m[x] = m[x] + ile[x].back();
     }
     inicjuj_dane(x+1);
     return 0;
}
void inicjuj()
{
    ile[0].push_back(1); 
    m[0]=1;
    ile[1].push_back(1); 
    m[1]=1;
    inicjuj_dane(2);
}
int wynik(vector<char>v,int ile_mozliwosci)
{
    int kk=v.size(),i, p=1;
    
    if(ile_mozliwosci!=m[kk])
    {
                         p=ile_mozliwosci/m[kk];
    }
    for(i=0;i<kk-1;i++)
    {
                     if(p*ile[kk][i]<n)n=n-p*ile[kk][i];
                     else break;
    }
    ile_mozliwosci=p*ile[kk][i];
    printf("%c",v[i]);
    if(i==kk-1 || i==0)
    {
            v.erase(v.begin()+i);
            if(!v.empty())ile_mozliwosci=wynik(v,ile_mozliwosci);
            return ile_mozliwosci;
    }
    
    vector<char>u;
    for(int j=0;j<i;j++)
    {
            u.push_back(v[0]);
            v.erase(v.begin());
    }v.erase(v.begin());
    
    ile_mozliwosci=wynik(u,ile_mozliwosci);
    ile_mozliwosci=wynik(v,ile_mozliwosci);
    return ile_mozliwosci;
}
int main()
{
    scanf("%d%d",&n,&k);
    inicjuj();
    for(int i=0;i<k;i++)v.push_back(char(97+i));
    wynik(v,m[k]);
    return 0;
}
