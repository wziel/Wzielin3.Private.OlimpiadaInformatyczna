#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
priority_queue<int> uzyte;
int n,m,a;
struct kontener
{
       int poj,wolne;
};
vector<pair<int,int> >odw;
kontener kont[100001];
bool cmp(kontener a,kontener b){return a.poj > b.poj;}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){ scanf("%d",&kont[i].poj); kont[i].wolne=kont[i].poj; }
    sort(&kont[0],&kont[n],cmp);
    for(int i=0;i<m;i++)
    {
            scanf("%d",&a);
            int j=0;
            while(j<odw.size() && odw[j].first>a)j++;
            if(j==odw.size())odw.push_back(make_pair(a,1));
            else if(a!=odw[j].first)odw.insert(odw.begin()+j,make_pair(a,1));
            else odw[j].second++;
    }
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<odw.size();j++)
            {
                    a=kont[i].wolne/odw[j].first;
                    if(a>=odw[j].second)
                    {
                                       kont[i].wolne-=odw[j].first*odw[j].second; 
                                       while(--odw[j].second>=0){uzyte.push(odw[j].first);}
                                       odw.erase(odw.begin()+j); j--;
                                       continue;
                    }
                    kont[i].wolne-=odw[j].first*a;
                    odw[j].second-=a;
                    while(--a>=0){uzyte.push(odw[j].first);}
                    
            }
    }
    for(int i=0;i<uzyte.size();i++)
    {
            int x=uzyte.top();
            while(!odw.empty() && odw[0].first>=x)odw.erase(odw.begin());
            if(odw.empty())break;
            uzyte.pop();
            for(int j=0;j<odw.size();j++)
            {
                    a=x/odw[j].first;
                    if(a>odw[j].second)a=odw[j].second;
                    x-=a*odw[j].first;
                    odw[j].second-=a;
                    while(--a>=0)uzyte.push(odw[j].first);
                    if(odw[j].second==0){ odw.erase(odw.begin()+j); j--;}
            }
    }
    printf("%d",uzyte.size());
    return 0;
}
