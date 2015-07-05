#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
vector<int>znak[1000001];
int n,m,a,min,ostatnie[1000001], przejscie[1000001];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            scanf("%d",&a);
            znak[a].push_back(i);
    }
    scanf("%d",&n);
    int i=0;
    while(n>0)
    {
              n--;
              i++;
              scanf("%d",&m);
              int min=0;
              bool b=0;
              while(m>0)
              {
                        m--;
                        scanf("%d",&a);
                        if(przejscie[a]<i)
                        {
                                          przejscie[a]=i;
                                          ostatnie[a]=0;
                        }
                        if(ostatnie[a]>=znak[a].size()){b=1; break;}
                        while(ostatnie[a]<znak[a].size() && znak[a][ostatnie[a]]<min)ostatnie[a]++;
                        if(ostatnie[a]>=znak[a].size()){b=1; break;}
                        min=znak[a][ostatnie[a]];
                        ostatnie[a]++;  
              }
              while(m>0){ scanf("%d",&a); m--; }
              if(b==0)printf("TAK\n");
              else printf("NIE\n");
    }
    return 0;
}
