#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int deg[10000],pop[10000];
pair<int,int>pojedynek[10000];
bool sprawdzone[10000];
vector<int>v[10000];
int main()
{
    int n,m,a,b,max=0,d,k;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
            scanf("%d%d",&a,&b);a--; b--;
            pojedynek[i].first=a; pojedynek[i].second=b;
            if(deg[a]>deg[b])
            {
                             v[b].push_back(a);
                             deg[b]++;
                             if(deg[max]<deg[b])max=b;
            }
            else
            {
                             v[a].push_back(b);
                             deg[a]++;
                             if(deg[max]<deg[a])max=a;
            }
    }
    while(true)
    {
               queue<int>s;
               s.push(max);
               while(!s.empty())
               {
                                k=s.front(); 
                                if(deg[k]<=deg[max]-2)break;
                                s.pop();
                                for(int i=0;i<v[k].size();i++)
                                {
                                        if(sprawdzone[v[k][i]]==0)
                                        {
                                                    sprawdzone[v[k][i]]=1;
                                                    pop[v[k][i]]=k;   
                                                    s.push(v[k][i]);
                                        }
                                }
               }
               if(s.empty())break;
               else
               {
                            deg[k]++;
                            while(k!=max)
                            {
                                         a=pop[k];
                                         v[k].push_back(a);
                                         for(int i=0;i<v[a].size();i++)if(v[a][i]==k)
                                         {
                                                 v[a].erase(v[a].begin()+i); break;
                                         }
                                         k=a;
                            }
                            deg[max]--;
               }
               for(int i=0;i<n;i++)if(deg[i]>deg[max])
               {
                       max=i; break;
               }
               memset(sprawdzone,0,sizeof sprawdzone);
    }
    printf("%d\n",deg[max]); int j;
    for(int i=0;i<m;i++)
    {
            a=pojedynek[i].first; b=pojedynek[i].second;
            for(j=0;j<v[a].size();j++)if(v[a][j]==b)break;
            if(j<v[a].size())
            {
                          v[a].erase(v[a].begin()+j);
                          printf("1\n");
            }
            else for(j=0;j<v[b].size();j++)if(v[b][j]==a)
            {
                          v[b].erase(v[b].begin()+j);
                          printf("0\n");
                          break;
            }
    }
    return 0;
}
