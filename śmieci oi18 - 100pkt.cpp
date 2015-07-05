//Wojciech Zieliñski
#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<list>
#define last v[a].size()-1
using namespace std;
struct Edge
{
       int a,b;
       bool visited;
       int N(int x)
       {
           if(a==x)return b;
           return a;
       }
};
int n,m,a,b,licz,vis[100001];
bool b1,b2;
vector<int>v[100001];
list<int>wynik,wyniktmp;
stack<int>s;
Edge edge[1000001];
int main()
{
    scanf("%d %d\n",&n,&m);
    while(--m>=0)
    {
                 scanf("%d %d %d %d",&a,&b,&b1,&b2);
                 if(b1==b2)continue;
                 v[a].push_back(m);
                 v[b].push_back(m);
                 edge[m].a = a; edge[m].b = b;
                 edge[m].visited = false;
    }
    for(int i=1;i<=n;i++)if(v[i].size()%2!=0){printf("NIE"); return 0;}
    for(int i=1;i<=n;i++)//szukanie cykli eulera
    {
            a=i;
            while(!v[a].empty() && edge[v[a][last]].visited)v[a].pop_back();
            if(v[a].empty())continue;
            s.push(a);
            while(!s.empty())
            {
                             a=s.top();
                             while(!v[a].empty() && edge[v[a][last]].visited)v[a].pop_back();
                             if(v[a].empty())
                             { 
                                             wynik.push_back(a); 
                                             wyniktmp.push_back(a);
                                             s.pop(); 
                                             continue; 
                             }
                             s.push(edge[v[a][last]].N(a));
                             edge[v[a][last]].visited=true;
            }
    }
    licz=0;//szukanie liczby "podcykli" eulera
    for(list<int>::iterator it=wyniktmp.begin();it!=wyniktmp.end();it++)
    {
                            if(++vis[*it]==1)continue;
                            licz++;
                            list<int>::iterator it2=it; it2--;
                            while(*it2!=*it)it2--;
                            while(it2!=it)
                            {
                                          --vis[*it2]; 
                                          it2=wyniktmp.erase(it2);
                            }
    }
    printf("%d\n",licz);
    for(int i=1;i<=n;i++)vis[i]=0;
    for(list<int>::iterator it=wynik.begin();it!=wynik.end();it++)//wypisywanie "podcykli" eulera
    {
                            if(++vis[*it]==1)continue;
                            list<int>::iterator it2=it; it2--;
                            licz=1;
                            while(*it2!=*it){it2--; licz++;}
                            printf("%d ",licz);
                            while(it2!=it)
                            {
                                          printf("%d ",*it2); 
                                          --vis[*it2]; 
                                          it2=wynik.erase(it2);
                            }
                            printf("%d\n",*it2);
    }
    return 0;
}
