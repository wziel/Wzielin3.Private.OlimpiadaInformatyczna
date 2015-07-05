#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;
bool czy[50000];
queue<int>ruchy;
stack<int>s,temp;
int main()
{
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n*2;i++)
    {
            scanf("%d",&a);a--;
            if(czy[a]==0)
            {
                  czy[a]=1;
                  s.push(a);
            }
            else
            {
                  while(s.top()!=a)
                  {
                         ruchy.push(s.size());
                         temp.push(s.top());
                         s.pop();
                  }
                  s.pop();
                  while(!temp.empty())
                  {
                                      s.push(temp.top());
                                      temp.pop();
                  }
            }
    }
    printf("%d\n",ruchy.size());
    while(!ruchy.empty())
    {
                     printf("%d\n",ruchy.front());
                     ruchy.pop();
    }
    return 0;
}
