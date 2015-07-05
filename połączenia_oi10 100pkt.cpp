#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
int n,m,a,b,c,q,maxk;
vector<pair<int,int> > sasiad[101];
priority_queue <pair<int,int> > kolejka;
vector<int> odleglosc[101][101];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
            scanf("%d%d%d",&a,&b,&c); a--; b--;
            sasiad[a].push_back(make_pair(-c,b));//pierwsze dajemy -odleglosc bo potem bedziemy wrzucac na priorqueue
    }
    scanf("%d",&q);
    int pytania[q][3];
    for(int i=0;i<q;i++)//pobieramy zapytania i szukamy maxk zeby oszczedzic sobie obliczen
    { 
            scanf("%d%d%d",&pytania[i][0],&pytania[i][1],&pytania[i][2]); pytania[i][0]--; pytania[i][1]--;
            if(maxk<pytania[i][2])maxk=pytania[i][2];  
    }
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<sasiad[i].size();j++) kolejka.push( sasiad[i][j] );
            while(!kolejka.empty())
            {
                                   pair<int,int>k=kolejka.top(); kolejka.pop();
                                   if(odleglosc[i][k.second].size()>maxk)continue;
                                   odleglosc[i][k.second].push_back(-k.first);
                                   for(int h=0;h<sasiad[k.second].size();h++)
                                   {
                                           pair<int,int> j=sasiad[k.second][h];
                                           if(odleglosc[i][j.second].size()>maxk)continue;
                                           kolejka.push( make_pair(k.first+j.first, j.second) );
                                   }
            }
    }
    for(int i=0;i<q;i++)
    {
            a=pytania[i][0]; b=pytania[i][1]; c=pytania[i][2];
            if(odleglosc[a][b].size()<c){ printf("-1\n"); continue; }
            printf("%d\n",odleglosc[a][b][c-1]);
    }
    return 0;
}
