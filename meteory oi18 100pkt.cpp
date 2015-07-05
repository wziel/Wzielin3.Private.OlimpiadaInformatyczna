//Wojciech Zieliñski
#include<iostream>
#include<stdio.h>
#include<vector>
#define MAX 300002
using namespace std;
int n,m,k,a,checked,M;
long long int tree[4*MAX],sum;
vector<int>v[MAX];
struct Rain
{
       int left,right,value;
}rain[MAX];
struct Country
{
       int a,b,need;
       vector<int>sector;
}country[MAX];
int FindM()//znajduje minimalny rozmiar potrzebnego drzewa przedzialowego
{
    int x=1;
    while(x<m)x*=2;
    return x;
}
void PutIntervalOnTree(int left,int right,int value)//wrzuca przedzial na drzewo przedzialowe
{
    left+=M; right+=M;
    tree[left]+=value;
    if(right!= left)tree[right]+=value;
    while(left/2 != right/2)
    {
                 if(left%2==0)tree[left+1]+=value;
                 if(right%2==1)tree[right-1]+=value;
                 left/=2;
                 right/=2;
    }
}
long long int Value(int x)//zwraca wartosc punktu w drzewie przedzialowym
{
    x+=M;
    long long int out=0;
    while(x>1){out+=tree[x]; x/=2;}
    return out;
}
int main()
{
    scanf("%d %d\n",&n,&m);
    for(int i=0;i<m;i++){scanf("%d",&a); country[--a].sector.push_back(i);}
    for(int i=0;i<n;i++)scanf("%d",&country[i].need);
    scanf("%d",&k);
    for(int i=0;i<n;i++){country[i].b=k+1; v[(k+1)/2].push_back(i);}
    for(int i=1;i<=k;i++){scanf("%d%d%d",&rain[i].left,&rain[i].right,&rain[i].value); rain[i].left--; rain[i].right--;}
    M=FindM();
    while(checked < n)//tak dlugo az wszystkich nie okreslimy
    {
              for(int i=1;i<=k;i++)//symulujemy calosc
              {
                      if(rain[i].left<=rain[i].right)PutIntervalOnTree(rain[i].left,rain[i].right,rain[i].value);
                      else                         {PutIntervalOnTree(rain[i].left,m-1          ,rain[i].value);
                                                    PutIntervalOnTree(0           ,rain[i].right,rain[i].value);}
                      while(!v[i].empty())//dla kazdego kraju ktorego wartosc w miejscu 'i' chcemy sprawdzic
                      {
                              a=v[i][v[i].size()-1];
                              v[i].pop_back();
                              sum=0; 
                              for(int h=0;h<country[a].sector.size() && sum<country[a].need;h++)sum+=Value(country[a].sector[h]); 
                              if(sum>=country[a].need)country[a].b=(country[a].a+country[a].b)/2;
                              else                    country[a].a=(country[a].a+country[a].b)/2;
                              if(country[a].a +1 >= country[a].b) checked++;//znalezlismy wartosc
                              else v[(country[a].a+country[a].b)/2].push_back(a);//binarnie nastepna wartosc do znalezienia
                      }
              }
              for(int i=0;i<2*M;i++)tree[i]=0;//reset
    }
    for(int i=0;i<n;i++)
    {
            if(country[i].b<=k)printf("%d\n",country[i].b);
            else printf("NIE\n");
    }
    return 0;
}
