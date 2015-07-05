#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
int n,m,a,b,tempwynik;
vector<int>v[100001],wynik;
list<int>lista;
list<int>::iterator it;
queue<int>q;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){ lista.push_back(i); v[i].push_back(n+1); }
    while(--m>=0)
    {
                 scanf("%d %d",&a,&b);a--; b--;
                 v[a].push_back(b);
                 v[b].push_back(a);
    }
    for(int i=0;i<n;i++)sort(v[i].begin(), v[i].end());
    while(!lista.empty())
    {
                         tempwynik=1;
                         q.push(*lista.begin());
                         lista.erase(lista.begin());
                         while(!q.empty())
                         {
                                          a=q.front(); q.pop();
                                          it=lista.begin();
                                          for(int i=0;i<v[a].size();i++)
                                          {
                                                  while(*it < v[a][i])
                                                  {
                                                            tempwynik++;
                                                            q.push(*it);
                                                            it=lista.erase(it);
                                                  }
                                                  if(*it == v[a][i])it++;
                                          }
                         }
                         wynik.push_back(tempwynik);
    }
    sort(wynik.begin(), wynik.end());
    printf("%d\n",wynik.size());
    for(int i=0;i<wynik.size();i++)printf("%d ",wynik[i]);
    return 0;
}
