#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
bool wywalone[1000001];
int main()
{
    int n,max=0,a,b,p=0;
    scanf("%d",&n);
    priority_queue<pair<int,int> >min;
    queue<pair<int,int> >q;
    for(int i=0;i<n;i++)
    {
            scanf("%d%d",&a,&b);
            while(min.size()>0 && wywalone[min.top().second]==1)min.pop();
            while(min.size()>0 && min.top().first>b)
            {
                               while(q.front().second!=min.top().second)
                               {
                                        wywalone[q.front().second]=1;
                                        q.pop();
                               }
                               q.pop(); min.pop();
                               while(min.size()>0 && wywalone[min.top().second]==1)min.pop();
            }
            q.push(make_pair(a,i));
            min.push(make_pair(a,i));
            if(q.size()>max)max=q.size();
            printf("%d",q.end());
    }
    printf("%d",max);
    return 0;
}
