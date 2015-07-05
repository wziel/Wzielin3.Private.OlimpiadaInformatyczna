#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<queue>
#define M 262143
using namespace std;
int n,m,a,b,ojciec[250001],preord[250001],przedzial[(M+1)*2],zakres[250001];
vector<int>synt[250001],syn[250001];
char c;
int main()
{
      scanf("%d",&n);
      for(int i=1;i<n;i++)
      {
              scanf("%d %d",&a,&b);
              if(a<b) { synt[a].push_back(b); ojciec[b]=a; }
              else    { synt[b].push_back(a); ojciec[a]=b; }
      }
      stack<int>dfs; a=1; dfs.push(1);
      while(!dfs.empty())
      {
                         b=dfs.top(); dfs.pop();
                         preord[b]=a;  a++;
                         for(int i=0;i<synt[b].size();i++)dfs.push(synt[b][i]);
      }
      for(int i=1;i<=n;i++) for(int j=0;j<synt[i].size();j++) 
      {
              syn[preord[i]].push_back(preord[synt[i][j]]);
              ojciec[preord[synt[i][j]]]=preord[i];
      }
      queue<int>bfs; przedzial[M+1]=0; bfs.push(1);
      while(!bfs.empty())
      {
                         a=bfs.front(); bfs.pop();
                         for(int i=0;i<syn[a].size();i++)
                         {
                                 bfs.push(syn[a][i]);
                                 przedzial[M+syn[a][i]]=przedzial[M+ojciec[syn[a][i]]]+1;
                         }
      }
      for(int i=n;i>0;i--)
      {
              a=i;
              while(ojciec[a]!=0 && zakres[a]==0){ zakres[a]=i; a=ojciec[a]; }
      }
      scanf("%d",&m);
      while(--m+n>0)
      {
                   do
                   {
                                 c=getchar();
                   }while(!isalpha(c));
                   if(c=='A')
                   {
                             scanf("%d %d",&a,&b);  
                             a=preord[b]+M; b=zakres[a-M]+M; 
                             przedzial[a]--;
                             if(a!=b)przedzial[b]--;
                             while(a<b-1)
                             {
                                                        if(a%2==0)przedzial[a+1]--;
                                                        if(b%2==1)przedzial[b-1]--;
                                                        a=a/2;
                                                        b=b/2;
                             }
                             continue;
                   }
                   scanf("%d",&a);
                   a=preord[a]+M;  b=przedzial[a];
                   do
                   {
                          a=a/2;
                          b+=przedzial[a];
                   }while(a!=1);
                   printf("%d\n",b);
      }
      system("PAUSE");
}
