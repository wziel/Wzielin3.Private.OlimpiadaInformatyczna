#include<iostream>
#include<stdio.h>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
set<int>s;
vector<int>v[100002];
vector<pair<int,int> >answer;
int n,q;
long long int wynik;
struct punkt
{
       int x,y,p;
};
bool cmp(punkt a,punkt b)
{
     return a.x < b.x || (a.x == b.x && a.y > b.y);
}
punkt pkt[100002];
int pkt2[50001][2];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)  { scanf("%d %d",&pkt[i].x,&pkt[i].y); pkt[i].p=i; }
    for(int i=n;i<n*2;i++){ scanf("%d %d",&pkt[i].x,&pkt[i].y); pkt[i].p=i; }
    for(int i=0;i<n;i++)  { pkt2[i][0]=pkt[i].x; pkt2[i][1]=pkt[i].y; }
    sort(&pkt[0],&pkt[n*2],cmp);
    
    for(int i=0;i<n*2;i++)
    {
            if(pkt[i].p<n)
            {
                          s.insert(pkt[i].y);
                          v[pkt[i].y].push_back(pkt[i].p);
                          continue;
            }
            q=*s.upper_bound(pkt[i].y-1); 
            answer.push_back(make_pair(v[q].back()+1,pkt[i].p-n+1));
            wynik+=pkt[i].x-pkt2[v[q].back()][0]+pkt2[v[q].back()][1]-pkt[i].y;
            v[q].pop_back();
            if(v[q].empty())s.erase(q);
    }
    printf("%lld\n",wynik);
    for(int i=0;i<n;i++)printf("%d %d\n",answer[i].first,answer[i].second);
    return 0;
}
