#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
int n,k,liczc;
vector<pair<int,int> >v;//numer, dlugosc
stack<int>wypisz;
char a;
int main()
{
    scanf("%d %d",&n,&k);
    getchar();
    for(int j=1;j<=n;j++)
    {
            scanf("%c",&a);
            if(a == 'c')
            {
                   if(!v.empty() && v[v.size()-1].second >= k)
                   {
                                 wypisz.push(j);
                                 for(int i=0;i<k;i++)
                                 {
                                       wypisz.push(v[v.size()-1].first);
                                       v.pop_back();
                                 }
                                 continue;
                   }
                   liczc++;
                   v.push_back( make_pair(j,0) );
            }
            else
            {
                if(v.empty())
                {
                             v.push_back( make_pair(j,1) );  
                             continue;
                }
                v.push_back( make_pair(j,v[v.size()-1].second +1 ) );
                if(v[v.size()-1].second == k && liczc>0)
                {
                                 for(int i=0;i<=k;i++)
                                 {
                                       wypisz.push(v[v.size()-1].first);
                                       v.pop_back();
                                 }
                                 liczc--;
                }
            }
    }
    for(int i=0;i<v.size();i+=k+1)
    {
            for(int j=i;j<i+k+1;j++)printf("%d ",v[j].first);
            printf("\n");
    }
    while(!wypisz.empty())
    {
            for(int i=0;i<k+1;i++){printf("%d ",wypisz.top());  wypisz.pop();}
            printf("\n");
    }
    return 0;
}
