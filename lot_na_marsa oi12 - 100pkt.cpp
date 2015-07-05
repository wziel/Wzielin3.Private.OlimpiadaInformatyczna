//Wojciech Zieliñski
#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#define MAX 1000010
using namespace std;
int a,n;
bool NotPossible[MAX][2];
vector<int>east,west,input;
struct Element
{
       int origin,resource;
       Element(int org,int res)
       {
                   origin = org;
                   resource = res;
       }
};
int Assign(int i,int number)
{
    if(number==0 || i==0)return i;
    else return n-i;
}
void Solve(vector<int>v,int number)
{
     stack<Element>s;
     int i=0;
     while(i<n)
     {
               while(!s.empty() && s.top().resource + v[i] < 0)
               {
                             NotPossible[ Assign(s.top().origin,number) ][number] = true;
                             Element el(s.top());
                             s.pop();
                             if(!s.empty())s.top().resource += el.resource - v[el.origin];
               }
               if(!s.empty())s.top().resource += v[i];
               if(v[i]>=0)s.push(Element(i,v[i]));
               else NotPossible[ Assign(i,number) ][number] = true;
               i++;
     }
     i=0;
     while(!s.empty() && i<n)
     {
               while(!s.empty() && s.top().resource + v[i] < 0)
               {
                             NotPossible[ Assign(s.top().origin,number) ][number] = true;
                             Element el(s.top());
                             s.pop();
                             if(!s.empty())s.top().resource += el.resource - v[el.origin];
               }
               if(!s.empty())s.top().resource += v[i];
               i++;
     }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)for(int i=0;i<2;i++){scanf("%d",&a);input.push_back(a);}
    
    for(int i=0;i<input.size();i+=2)west.push_back(input[i]-input[i+1]);
    east.push_back(input[0]-input[input.size()-1]);
    for(int i=input.size()-2;i>0;i-=2)east.push_back(input[i]-input[i-1]);
    
    Solve(west,0);
    Solve(east,1);
    for(int i=0;i<n;i++)
    {
            if(NotPossible[i][0] && NotPossible[i][1])printf("NIE\n");
            else printf("TAK\n");
    }
    return 0;
}
