#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int dlugosc[1000000],deg[1000000],tab[1000000];
bool sprawdzone[1000000];

bool cmp(int a,int b)
{
     return dlugosc[a]>dlugosc[b];
}

int main()
{
    int n,l,a,b,wynik=0;
    scanf("%d%d",&n,&l); 
    vector<int>v[n];
    for(int i=0;i<n-1;i++)
    {
            scanf("%d%d",&a,&b); a--; b--;
            v[a].push_back(b); deg[a]++;
            v[b].push_back(a); deg[b]++;
            tab[i]=i;
    }tab[n-1]=n-1;
    if(l==0)
    {
            printf("0"); return 0;
    }
    queue<int>q;
    for(int i=0;i<n;i++) if(deg[i]==1)
    {
            q.push(i);
            dlugosc[i]=1;
    }
    while(!q.empty())
    {
                     a=q.front(); q.pop(); 
                     deg[a]=0;
                     for(int i=0;i<v[a].size();i++)
                     {
                             deg[v[a][i]]--;
                             if(deg[v[a][i]]==0 || deg[v[a][i]]==1)
                             {
                                                dlugosc[v[a][i]]=dlugosc[a]+1;
                                                q.push(v[a][i]);
                             }
                     }
    }
    sort(tab,tab+n,cmp); l*=2;
    for(int i=0;i<n;i++)
    {
                    a=tab[i];
                    if(sprawdzone[a])continue; 
                    sprawdzone[a]=true; wynik += dlugosc[a];
                    if(--l==0)break;
                    while(dlugosc[a]>1)
                    {
                                      for(int j=0;j<v[a].size();j++)if(dlugosc[v[a][j]]==dlugosc[a]-1)
                                      {
                                                       sprawdzone[v[a][j]]=true;
                                                       a=v[a][j];
                                                       break;
                                      } 
                    }
                    
    }
    printf("%d",wynik);
    return 0;
}
