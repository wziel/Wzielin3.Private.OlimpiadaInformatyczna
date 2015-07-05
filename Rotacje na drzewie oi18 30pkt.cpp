#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#define MAX 40001
#define SVA seq[vert[a].ref]
#define SVB seq[vert[b].ref]
#define SVX seq[vert[x].ref]
using namespace std;
struct Vert
{
       bool vis;
       int left,right,father,ref;//ref to odwolanie do odpowiedniego wektora seq (oszczednosc pamieci)
}vert[MAX];
int n,a,b,x,num,i,j,freeSeq;
long long inversions,tempInversions,relationNumber;
stack<int>s;
vector<int>seq[MAX],q;
int main()
{
    scanf("%d %d",&n,&x);
    freeSeq=n+1;
    s.push(1); 
    num=2;
    while(!s.empty())
    {
                     a=s.top();
                          if (vert[a].left==0) vert[a].left=num;
                     else if (vert[a].right==0)vert[a].right=num;
                     else {s.pop(); continue;}
                     scanf("%d",&x);
                     vert[num].father=a;
                     if(x>0)
                     {
                            vert[num].ref=x;
                            seq[x].push_back(x);
                            q.push_back(num);
                     }
                     else s.push(num);
                     num++;
    }
    while(!q.empty())
    {
                     x=q[q.size()-1]; q.pop_back();
                     if(vert[x].left!=0)
                     {
                                a=vert[x].left; b=vert[x].right;
                                vert[x].ref = freeSeq;
                                tempInversions=0;
                                relationNumber = SVA.size() * SVB.size();//SV to wektory przechowujace posortowane liscie
                                i=0; j=0;
                                while(i<SVA.size() && j< SVB.size())
                                {
                                         if(SVA[i] < SVB[j])
                                         {
                                                       SVX.push_back(SVA[i]); 
                                                       i++;
                                         }
                                         else
                                         {
                                                       SVX.push_back(SVB[j]);
                                                       j++; 
                                                       tempInversions += (SVA.size()-i);   
                                         }
                                }
                                inversions+=min(tempInversions, relationNumber-tempInversions);
                                while(i < SVA.size()){SVX.push_back(SVA[i]); i++;}
                                while(j < SVB.size()){SVX.push_back(SVB[j]); j++;}
                                while(!SVA.empty())SVA.pop_back();
                                while(!SVB.empty())SVB.pop_back();
                                freeSeq=vert[a].ref;
                     }
                     if(vert[vert[x].father].vis)q.push_back(vert[x].father);
                     else vert[vert[x].father].vis=true;
    }
    printf("%lld",inversions);
    return 0;
}
