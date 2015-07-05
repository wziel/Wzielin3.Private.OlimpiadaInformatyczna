#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<list>
#include<algorithm>
using namespace std;
int a,b,n;
vector<int>postOrder;
struct Vertex
{
       int father,length;
       vector<int>son;
}v[10001];
bool Check(int len)
{
     list<int>lengths;
     list<int>::iterator beg,end;
     for(int i=0;i<n;i++)
     {
             n = postOrder[i]; //aktualny wierzcholek
             for(int j=0;j<v[n].son.size();j++) lengths.push_back( v[ v[n].son[j] ].length+1 );
             lengths.sort();
             beg = lengths.begin(); beg++;
             end = lengths.end(); end--;
             while(lengths.size()>2)
             {
                        while(*beg + *end > len)
                        {
                                     if(beg == lengths.begin()) return false;
                                     beg--;
                        }
                        end = lengths.erase(end); end--;
                        beg = lengths.erase(beg);
             }
                  if(lengths.size() == 0)            v[n].length = 0;
             else if(lengths.size() == 1)            v[n].length = *lengths.begin();
             else if(*lengths.begin() + *end <= len) v[n].length = 0;
             else                                    v[n].length = *lengths.begin();
             while(!lengths.empty())lengths.erase( lengths.begin() );
             if(v[n].length > len)return false;
     }
     return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
            scanf("%d%d",&a,&b);
            v[a].son.push_back(b);
            v[b].son.push_back(a);
    }
    
    for(a=1;a<=n;a++)if(v[a].son.size()==1) break;
    queue<int>q; q.push(a);
    
    while(!q.empty())
    {
                     a=q.front(); q.pop();
                     for(int i=0;i<v[a].son.size();i++)
                     {
                             if(v[a].son[i] == v[a].father)
                             {
                                    swap(v[a].son[i], v[a].son[v[a].son.size()-1]);
                                    v[a].son.pop_back();
                                    i--;
                             }
                             else
                             {
                                    b=v[a].son[i];
                                    v[b].father = a;
                                    q.push(b); 
                             }
                     }
    }
    
    a=1;//ile nieparzystych stopni (wliczony korzen)
    for(int i=1;i<=n;i++)
    {
            if(v[i].son.size() %2 == 0)a++;
            if(v[i].son.size() == 0)postOrder.push_back(i);
    }
    printf("%d ",a/2);
    for(int i=0;i<postOrder.size();i++)
    {
            a=v[postOrder[i]].father; // tutaj length jako ilosc przejrzanych dzieci
            if(++v[a].length == v[a].son.size())postOrder.push_back(a);
    }
    a=0; b=n;//binarka
    while(a<b-1)
    {
                if( Check((a+b)/2) ) b=(a+b)/2;
                else                 a=(a+b)/2;
    }
    printf("%d",b);
    return 0;
}
