#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
long long int m,d,a,mini;
int n;
priority_queue<long long int>taksowki;
bool znaleziono_mini=0;
int main()
{
    scanf("%lld %lld %d",&m,&d,&n);
    for(int i=0;i<n;i++)
    {
            scanf("%lld",&a);
            if(a>=m-d && (a<mini || mini==0))mini=a;
            taksowki.push(a);
    } a=0;
    if(mini>0) while(a<m && !taksowki.empty())
    {
              if(taksowki.top() == mini && znaleziono_mini == 0)
              {
                                taksowki.pop();
                                znaleziono_mini=1;
                                continue;
              }
              if(mini >= m + d - 2*a) 
              {
                               a=m; 
                               if(znaleziono_mini == 0)taksowki.pop();
                               break;
              }
              if(d-a >= taksowki.top())break;
              a += taksowki.top() - d + a;
              if(a < m || znaleziono_mini == 0)taksowki.pop();
    }
    if     (mini >= m + d - 2*a ) printf("%d",n-taksowki.size());
    else                          printf("0"); 
    return 0;
}
