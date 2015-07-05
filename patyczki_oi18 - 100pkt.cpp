//Wojciech Zieliñski
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int> >v;
int cmp(pair<int,int>a,pair<int,int>b)
{
    return a.first>b.first;
}
int main()
{
    int k,n,a;
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
            scanf("%d",&n);
            for(int j=0;j<n;j++)
            {
                    scanf("%d",&a);
                    v.push_back(make_pair(a,i));
            }
    }
    sort(v.begin(),v.end(),cmp);
    int w[3]={0,1,2};
    bool b=0;
    while(w[2]<v.size() && b==0)
    {
                     if(v[w[2]].first+v[w[1]].first<=v[w[0]].first)
                     {
                                       w[0]++;
                                       for(int i=0;i<2;i++)if(w[i]==w[i+1])w[i+1]++;
                                       continue;
                     } 
                     b=1;
                     for(int i=0;i<2;i++)for(int j=i+1;j<3;j++)
                             if(v[w[i]].second==v[w[j]].second)
                             {
                                    if(j==2)w[2]++;
                                    else 
                                    {
                                         w[1]++;
                                         if(w[1]==w[2])w[2]++;
                                    }
                                    b=0; i=2; break;
                             }
    }
    if(w[2]>=v.size()) printf("NIE\n");
    else for(int i=0;i<3;i++)printf("%d %d ",v[w[i]].second+1,v[w[i]].first);
    return 0;
}
