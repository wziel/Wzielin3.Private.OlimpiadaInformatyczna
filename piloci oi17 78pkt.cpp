#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
int n,t,a,wynik;
priority_queue <int> maxi,mini,deletemax,deletemin;
queue<int>wys;
int main()
{
    scanf("%d %d",&t,&n);
    while(--n>=0)
    {
                 scanf("%d",&a);
                 wys.push(a); maxi.push(a); mini.push(-a);
                 while(-mini.top()+t<maxi.top())
                 {
                                deletemax.push(wys.front());
                                deletemin.push(-wys.front());
                                wys.pop();
                                while(!deletemax.empty() && deletemax.top()==maxi.top()){deletemax.pop(); maxi.pop();}
                                while(!deletemin.empty() && deletemin.top()==mini.top()){deletemin.pop(); mini.pop();}
                 }
                 if(wys.size()>wynik)wynik=wys.size();
    }
    printf("%d",wynik);
    return 0;
}
