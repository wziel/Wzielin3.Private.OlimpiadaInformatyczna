#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
int n,a,b,wynik;
vector<int>v[1000000];
bool visited[1000000];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            scanf("%d",&a); a--;
            v[a].push_back(i);
            v[i].push_back(a);
    }
    for(int i=0;i<n;i++)if(visited[i]==0)
    {
            wynik++;
            queue<int>q; q.push(i);
            while(!q.empty())
            {
                             a=q.front(); q.pop();
                             visited[a]=1;
                             for(int i=0; i<v[a].size(); i++)  if(visited[ v[a][i] ]==0)  q.push(v[a][i]);
            }
    }
    printf("%d",wynik);
    return 0;
}
