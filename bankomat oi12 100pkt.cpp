//Wojciech Zieliñski
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int n,t,tab[10000][10];
char a;
vector<int>v[4];
int main()
{
    for(int q=0;q<10;q++)for(int w=0;w<10;w++)for(int e=0;e<10;e++)for(int r=0;r<10;r++)
    {
            v[0].push_back(q);
            v[1].push_back(w);
            v[2].push_back(e);
            v[3].push_back(r);
    }
    scanf("%d",&n);
    while(--n>=0)
    {
                 scanf("%d ",&t); 
                 for(int i=0;i<t;i++)for(int j=0;j<10;j++)tab[i][j]=-1;
                 for(int i=0;i<t;i++)
                 {
                         scanf("%c",&a);
                         tab[i][a-'0']=i;
                 }
                 for(int i=t-2;i>=0;i--)for(int j=0;j<10;j++)if(tab[i][j]==-1)tab[i][j]=tab[i+1][j];
                 for(int i=0;i<v[0].size();i++)
                 {
                         int j=0,column=0;
                         while(j<4 && tab[column][v[j][i]]!=-1)
                         {
                                   column=tab[column][v[j][i]];
                                   j++;
                         }
                         if(j<4)
                         {
                                for(j=0;j<4;j++)
                                {swap(v[j][i],v[j][v[j].size()-1]); v[j].pop_back();}
                                i--;
                         }
                 }
    }
    printf("%d",v[0].size());
    return 0;
}
