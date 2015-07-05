#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;
priority_queue< pair<long long int, int> >q;
int n,m;
long long int a;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
            scanf("%lld",&a);
            q.push(  make_pair(-a,i)  );
    }
    while(--m>=0 && n>0)
    {
            scanf("%lld",&a);
            n--;
            while(-q.top().first < a)
            {
                             if(q.top().second < n) n=q.top().second;
                             q.pop();    
            }
    }
    printf("%d",n);
    return 0;
}
