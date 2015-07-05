#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int ojciec[500000],n,a,b,c;
vector<int>dzieci[500000],dziecialive[500000],dziecizero[500000],wynik;
bool visited[500000],OnPath[500000];
int Dziecko(int v, bool isOnPath)
{
    for(int i=0;i<dziecizero[v].size();i++)
    {
            c=dziecizero[v][i];
            if(visited[c]==0)
            {
                if(OnPath[c] != isOnPath)continue;
                swap(dziecizero[v][i],dziecizero[v][dziecizero[v].size()-1]);
                dziecizero[v].pop_back();
                return c;
            }
            else
            {
                swap(dziecizero[v][i],dziecizero[v][dziecizero[v].size()-1]);
                dziecizero[v].pop_back();
                i--;
            }
    }
    for(int i=0;i<dziecialive[v].size();i++)
    {
            c=dziecialive[v][i];
            if(visited[c]==0)
            {
                if(OnPath[c] != isOnPath)continue;
                swap(dziecialive[v][i],dziecialive[v][dziecialive[v].size()-1]);
                dziecialive[v].pop_back();
                return c;
            }
            else
            {
                swap(dziecialive[v][i],dziecialive[v][dziecialive[v].size()-1]);
                dziecialive[v].pop_back();
                i--;
            }
    }
    return -1;
}
int DzieckoDziecka(int v, bool isOnPath1, bool isOnPath2)
{
    int x;
    for(int i=0;i<dzieci[v].size();i++)if(OnPath[dzieci[v][i]] == isOnPath1)
    {
            x=Dziecko(dzieci[v][i], isOnPath2);
            if(x != -1)return x;
    }
    return -1;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
            scanf("%d %d",&a,&b);a--; b--;
            dzieci[a].push_back(b); dziecialive[a].push_back(b);
            dzieci[b].push_back(a); dziecialive[b].push_back(a);
    }
    ojciec[0]=-1;
    queue<int>q; q.push(0);
    while(!q.empty())
    {
                     a=q.front(); q.pop();
                     if(dzieci[a].empty()){ dziecizero[ojciec[a]].push_back(a); continue; }
                     for(int i=0;i<dzieci[a].size();i++)
                     {
                             b=dzieci[a][i];
                             ojciec[b]=a;
                             q.push(dzieci[a][i]);
                             for(int j=0;j<dzieci[b].size();j++)if(dzieci[b][j]==a)
                             {
                                     swap(dzieci[b][j],dzieci[b][dzieci[b].size()-1]);
                                     swap(dziecialive[b][j],dziecialive[b][dziecialive[b].size()-1]);
                                     dzieci[b].pop_back();
                                     dziecialive[b].pop_back();
                                     break;
                             }
                     }
    }
    a=n-1;
    while(a>=0){OnPath[a]=1; a=ojciec[a];}
    
    wynik.push_back(0);
    a=0;
    
    for(int i=0;i<n-1;i++)
    {
                     if(a==n-1){printf("BRAK"); return 0;}
                     visited[a]=1;
                     if(OnPath[a]==1)
                     {
                                     b=DzieckoDziecka(a,0,0);
                                     if(b==-1)
                                     {
                                               b=Dziecko(a,0);          
                                               if(b==-1)
                                               {
                                                         b=DzieckoDziecka(a,1,0); 
                                                         if(b==-1)
                                                         {
                                                                   b=Dziecko(a,1);          
                                                                   if(b==-1)
                                                                   {
                                                                             b=DzieckoDziecka(a,1,1); 
                                                                             if(b==-1)
                                                                             {
                                                                                      printf("BRAK");
                                                                                      return 0;
                                                                             }
                                                                   }
                                                         }
                                               }
                                     }
                     }
                     else
                     {
                                     b=DzieckoDziecka(a,0,0);
                                     if(b==-1)
                                     {
                                              b=Dziecko(a,0);          
                                              if(b==-1)
                                              {
                                                       if(ojciec[a]>=0)
                                                       {
                                                                    b=Dziecko(ojciec[a],0);  
                                                                    if(b==-1)
                                                                    {
                                                                             if(visited[ojciec[a]]==0)b=ojciec[a];
                                                                             if(b==-1)
                                                                             {
                                                                                   if(ojciec[ojciec[a]] >=0 && visited[ojciec[ojciec[a]]]==0)
                                                                                   b=ojciec[ojciec[a]];
                                                                                   if(b==-1)b=Dziecko(ojciec[a],1);
                                                                             }
                                                                    }
                                                       }
                                                       if(b==-1)
                                                       {
                                                                printf("BRAK"); 
                                                                return 0;
                                                       }
                                              }
                                     }
                     }
                     wynik.push_back(b);
                     a=b;
    }
    for(int i=0;i<wynik.size();i++)printf("%d\n",wynik[i]+1);
    return 0;
}
