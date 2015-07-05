//Roziwazanie polega na tym ¿e na poczatku sztucznie ustawiamy wszystkie statusy na 0 (potem 1) i stabilizujemy ustawienie
//takim sposobem dostaniemy dwa skrajne poprawne uklady. te statusy ktore sie zgadzaja w obu ustawieniach musza byc zdeterminowane
#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<math.h>
using namespace std;
vector<int>wejscia[200000],wyjscia[200000];
int n,a,k,ile[2][2][200000],status[2][200000];
set<int>s;
int state(int x,int p)
{
    if(ile[p][0][x]>ile[p][1][x])return 0;
    if(ile[p][0][x]<ile[p][1][x])return 1;
    return 2;
}
int main()
{
    scanf("%d",&n);
    status[0][0]=0; status[0][1]=0; status[1][0]=1; status[1][1]=1; //[x][] - system, [][x] - jaki element
    ile[0][0][0]=1; ile[0][0][1]=0; ile[0][1][0]=0; ile[0][1][1]=1;//[x][][] x - system
    ile[1][0][0]=1; ile[1][0][1]=0; ile[1][1][0]=0; ile[1][1][1]=1;//[][x][] ile ma xów, [][x] jaki element
    for(int i=2;i<n;i++)
    {
            scanf("%d",&k);
            while(k>0)
            {
                      scanf("%d",&a);
                      wyjscia[a].push_back(i);
                      wejscia[i].push_back(a);
                      ile[0][0][i]++; ile[1][1][i]++;
                      k--;
            }
            status[0][i]=0; status[1][i]=1;
    }
    //robimy zera
    s.insert(1);
    while(!s.empty())
    {
                     a=*s.begin(); s.erase(*s.begin());
                     if(status[0][a]==state(a,0))continue;
                     
                     if(status[0][a]!=2) for(int i=0;i<wyjscia[a].size();i++) ile[0][status[0][a]][wyjscia[a][i]]--;
                     if(state(a,0)!=2) for(int i=0;i<wyjscia[a].size();i++) ile[0][state(a,0)][wyjscia[a][i]]++;
                     
                     for(int i=0;i<wyjscia[a].size();i++) if(status[0][wyjscia[a][i]]!=state(wyjscia[a][i],0))
                     s.insert(wyjscia[a][i]);
                     
                     status[0][a]=state(a,0);
    }
    //robimy jedynki
    s.insert(0);
    while(!s.empty())
    {
                     a=*s.begin(); s.erase(*s.begin());
                     if(status[1][a]==state(a,1))continue;
                     
                     if(status[1][a]!=2) for(int i=0;i<wyjscia[a].size();i++) ile[1][status[1][a]][wyjscia[a][i]]--;
                     if(state(a,1)!=2) for(int i=0;i<wyjscia[a].size();i++) ile[1][state(a,1)][wyjscia[a][i]]++;
                     
                     for(int i=0;i<wyjscia[a].size();i++) if(status[1][wyjscia[a][i]]!=state(wyjscia[a][i],1))
                     s.insert(wyjscia[a][i]);
                     
                     status[1][a]=state(a,1);
    }
    for(int i=0;i<n;i++)
    {
            if(status[1][i]==status[0][i])
            {
                              if(status[1][i]==2)printf("1/2\n");
                              else printf("%d\n",status[1][i]);
            }
            else printf("?\n");
    }
    return 0;
}

