#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
    int n,m,a,mnozn=1,mnozm=1,wynik=0;
    scanf("%d %d",&n,&m);
    priority_queue<int>qn,qm;
    qn.push(0); qm.push(0);
    for(int i=0;i<n-1;i++){ scanf("%d",&a); qn.push(a);}
    for(int i=0;i<m-1;i++){ scanf("%d",&a); qm.push(a);}
    while(qn.top()!=0 || qm.top()!=0)
    {
                      if(qn.top() > qm.top() )
                      {
                                       wynik+=qn.top()*mnozn;
                                       qn.pop();
                                       mnozm++;
                                       continue;
                      }
           
                                       wynik+=qm.top()*mnozm;
                                       qm.pop();
                                       mnozn++;
    }
    printf("%d",wynik);
    return 0;
}
