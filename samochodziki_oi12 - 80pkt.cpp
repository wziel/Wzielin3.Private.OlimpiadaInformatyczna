#include<iostream>
#include<stdio.h>
#include<set>
#include<vector>
using namespace std;
vector<int>next[100005];
int tab[500005];
struct compare
{
       bool operator()(const int&a,const int&b)const
       {
            return next[a]>next[b];
       }
};
int main()
{
    int n,k,p,i,wynik;
    set<int,compare>s;
    scanf("%d%d%d",&n,&k,&p);
    for(i=0;i<p;i++)
    {
            scanf("%d",&tab[i]);
            next[tab[i]].push_back(i);
    }
    for(int i=0;i<=n;i++)next[i].push_back(600000+i);
    i=0;
    while(s.size()<k && i<p)
    {
                       if(s.find(tab[i])!=s.end())s.erase(s.find(tab[i]));
                       next[tab[i]].erase(next[tab[i]].begin());
                       s.insert(tab[i]);
                       i++;
    }
    wynik=k;
    while(i<p)
    {
              if(s.find(tab[i])!=s.end()) s.erase(s.find(tab[i]));
              else
              {
                        s.erase(s.begin());
                        wynik++;
              }
              next[tab[i]].erase(next[tab[i]].begin());
              s.insert(tab[i]);
              i++;
    }
    printf("%d",wynik);
    return 0;
}
