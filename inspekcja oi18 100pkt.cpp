//Wojciech Zieliñski
#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#define length second
#define vert first
#define visited stopien
#define para make_pair
#define QF Q.front() 
using namespace std;
int n,father[1000002],a,b,sons[1000002],stopien[1000002],licz=1,theFurthestLength;
long long int wynik[2][2];
vector<int>v[1000002];
queue<int>q;
queue<pair< int,int> >Q;
bool Hura;
void DoQ2(int x)
{
     Q.push( para(x,1) );
     while(!Q.empty())
     {
                      theFurthestLength=QF.length;
                      visited[QF.vert]=licz;
                      for(int k=0;k<v[QF.vert].size();k++)
                      if(visited[v[QF.vert][k]]!=licz)Q.push( para(v[QF.vert][k], QF.length+1) );
                      if(father[QF.vert] >0 && visited[father[QF.vert]]!=licz)
                      Q.push( para(father[QF.vert], QF.length+1) );
                      Q.pop();
     }
}
int main()
{
    scanf("%d",&n);
    if(n==1){printf("0"); return 0;}
    for(int i=1;i<n;i++){scanf("%d%d",&a,&b); v[a].push_back(b); v[b].push_back(a);}
    father[1]=0;
    q.push(1);
    while(!q.empty())//tworzenie tablicy synow i ojcow
    {
                     a=q.front(); q.pop();
                     for(int i=0;i<v[a].size();i++)
                     {
                             if(v[a][i]==father[a])
                             {
                                                   swap(v[a][i],v[a][v[a].size()-1]);
                                                   v[a].pop_back();
                                                   i--;
                                                   continue;
                             }
                             father[v[a][i]]=a;
                             q.push(v[a][i]);
                     }
    }
    for(int i=2;i<=n;i++)if(v[i].empty())q.push(i);//szukanie lisci
    while(!q.empty())//sumowanie dla kazdego wierzcholka liczby jego dzieci
    {
                     a=q.front(); q.pop();
                     sons[a]++;
                     if(a==1)continue;
                     sons[father[a]]+=sons[a];
                     stopien[father[a]]++;
                     if(stopien[father[a]]==v[father[a]].size())q.push(father[a]);
    }
    for(int i=1;i<=n && licz<3;i++)
    {
            Hura=true;
            for(int j=0;j<v[i].size();j++)if(sons[v[i][j]]>n/2){Hura=false; break;}//jezeli moc jakiejs odnogi > n/2 to sie nie da
            if(n-sons[i]>n/2)Hura=false;                                           //  j.w.
            if(Hura)
            {
                    wynik[licz-1][0]=i;
                    Q.push( para(i,0) );
                    visited[i]=-licz;
                    while(!Q.empty())//szukamy sumy dlugosci do wszystkich wierzcholkow, i dlugosci najwiekszej
                    {
                                     theFurthestLength = QF.length;
                                     visited[QF.vert]=-licz;
                                     for(int j=0;j<v[QF.vert].size();j++)if(visited[v[QF.vert][j]]!=-licz)
                                     {
                                             wynik[licz-1][1]+=QF.length+1;
                                             Q.push( para(v[QF.vert][j], QF.length+1) );
                                     }
                                     if(father[QF.vert] > 0 && visited[father[QF.vert]]!=-licz)
                                     {
                                             wynik[licz-1][1]+=QF.length+1;   
                                             Q.push( para(father[QF.vert], QF.length+1) );  
                                     }
                                     Q.pop();
                    }
                    
                    visited[i]=licz;//jezeli jakas odnoga == n/2 to tam musimy zaczac i skonczyc. szukamy najwiekszej dlugosci z tej odnogi
                    for(int j=0;j<v[i].size();j++)if(sons[v[i][j]]==n/2)DoQ2(v[i][j]);
                    if(n-sons[i]==n/2)DoQ2(father[i]);
                    
                    wynik[licz-1][1]*=2;//obliczanie wyniku
                    wynik[licz-1][1]-=theFurthestLength;
                    licz++;
            }
    }
    licz=0;
    for(int i=1;i<=n;i++)//wypisujemy "-1" chyba ze cos jest jednym z max dwoch otrzymanych wynikow
    {
            if(i==wynik[licz][0])
            {
                              printf("%lld\n",wynik[licz][1]);
                              licz++;
            }
            else printf("-1\n");
    }//system("PAUSE");
    return 0;
}
