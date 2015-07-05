#include<iostream>
#include<stdio.h>
#include<queue>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
queue<int>q;
vector<int>win,przegraz[100000],temp;
list<int>los;
int n,k,a,j;
bool wygral[100000];
int szukajbin(int a,int x,int p,int k)
{
           if(k==p)return 0;
           if(k-p==1)if(przegraz[a][p]==x)return 1;
           else return 0;
           if(przegraz[a][(p+k)]>x)return szukajbin(a,x,p,(p+k)/2);
           else return szukajbin(a,x,(p+k)/2,k);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            scanf("%d",&k);
            while(k>0)
            {
                      k--; 
                      scanf("%d",&a); a--; przegraz[i].push_back(a);
            }
    }
    for(int i=0;i<n;i++)sort(przegraz[i].begin(),przegraz[i].end());
    //przeprowadzamy raz turniej zeby wylonic jednego zwyciezce
    a=0;
    for(int i=1;i<n;i++)
    {
            if(szukajbin(a,i,0,przegraz[a].size())==0)a=i;
    }
    win.push_back(a); wygral[a]=1;  
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int tt[4]={0,a+1,a,n};    k=0;
    for(int b=0;b<2;b++)for(int i=tt[0+b];i<tt[2+b];i++)//wrzucamy wszystkie poza a - albo na Los albo na Q
    {
            if(k<przegraz[a].size() && przegraz[a][k]==i)
            {
                                 temp.push_back(i);
                                 k++;
            }
            else { q.push(i); wygral[i]=1; }
    }
    sort(temp.begin(),temp.end());
    for(int i=0;i<temp.size();i++)los.push_back(temp[i]);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //przechodzimy do iteracji
    while(!q.empty())
    {
                     a=q.front(); q.pop();
                     win.push_back(a);
                     list<int>::iterator it=los.begin();
                     k=0;
                     while(it!=los.end() && k<przegraz[a].size())
                     {
                         if(*it>przegraz[a][k])     {if(wygral[przegraz[a][k]]==0)q.push(przegraz[a][k]); wygral[przegraz[a][k]]=1;      k++;}
                         else if(*it<przegraz[a][k]){                             q.push(*it);            wygral[*it]=1;    it=los.erase(it);}
                         else                       {                                                                              it++; k++;}
                     }
                     while(k<przegraz[a].size())    {if(wygral[przegraz[a][k]]==0)q.push(przegraz[a][k]); wygral[przegraz[a][k]]=1;      k++;}
                     while(it!=los.end())           {                             q.push(*it);            wygral[*it]=1;    it=los.erase(it);}
    }
    printf("%d ",win.size());
    sort(win.begin(),win.end());
    for(int i=0;i<win.size();i++)printf("%d ",win[i]+1);
    return 0;
}
