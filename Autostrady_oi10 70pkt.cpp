#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<int> gora,dol;
priority_queue<pair <pair<int,int>,int> >porzadek;
queue <int> goratemp,doltemp;       
char strona[20000];
int n,k,a,b,aktualne;
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;i++)
    {
            scanf("%d %d",&a,&b);
            porzadek.push(make_pair(make_pair(-a,-b),i));
    }
    aktualne=-porzadek.top().first.first;
    for(int i=0;i<k;i++)
    {
            a=-porzadek.top().first.first;
            b=-porzadek.top().first.second;
            
            if(a!=aktualne)
            {
                           while(!goratemp.empty())
                           {
                                                   gora.push(goratemp.front());
                                                   goratemp.pop();
                           }
                           while(!doltemp.empty())
                           {
                                                   dol.push(doltemp.front());
                                                   doltemp.pop();
                           }
                           aktualne=a;
            }
            
            while(!gora.empty() && -gora.top() <= a) gora.pop();
            while(!dol.empty() && -dol.top() <= a) dol.pop();
            if(gora.empty() || -gora.top() >= b)
            {
                             goratemp.push(-b);
                             strona[porzadek.top().second]='N';
            }
            else if(dol.empty() || -dol.top() >= b)
            {
                             doltemp.push(-b);
                             strona[porzadek.top().second]='S';   
            }
            else 
            {
                 printf("NIE");
                 return 0;
            }
            porzadek.pop();
    }
    for(int i=0;i<k;i++)printf("%c\n",strona[i]);
    return 0;
}
