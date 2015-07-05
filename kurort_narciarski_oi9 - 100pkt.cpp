#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
bool tab[1000][2001];
int main()
{
    int n,n1,a,b,c,m,min,k;
    scanf("%d%d%d",&n,&n1,&k);
    vector< pair<int,int> >v[n];
    while(k>0)
    {
              k--;
              scanf("%d%d",&a,&b); a--; b--;
              v[a].push_back(make_pair(b,0));
    }
    scanf("%d",&m);
    while(m>0)
    {
              m--;
              scanf("%d%d%d",&a,&b,&c); a--; b--;
              v[a].push_back(make_pair(b,c));
    }
    scanf("%d%d",&a,&c); a--; min=c;
    tab[a][c]=1;
    stack< pair<int,int> > s; s.push(make_pair(a,c));
    while(!s.empty())
    {
                     a=s.top().first; c=s.top().second; s.pop();
                     for(int i=0;i<v[a].size();i++)
                     {
                             if(v[a][i].second<=c && tab[v[a][i].first][c-v[a][i].second]==0)
                             {
                                  if(v[a][i].first<n1 && c-v[a][i].second<min)min=c-v[a][i].second;
                                  s.push(make_pair(v[a][i].first,c-v[a][i].second));
                                  tab[v[a][i].first][c-v[a][i].second]=1;
                             }
                     }
    }
    printf("%d",min);
    return 0;
}
