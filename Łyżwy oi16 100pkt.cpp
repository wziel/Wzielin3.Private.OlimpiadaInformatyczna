#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,k,d,N,r,a;
struct Vert
{
       long long int maxSum,maxPref,maxSuf,sum;
}tree[550000];
void InitializeTree()
{
     for(int i=N;i<N*2;i++)
     {
             tree[i].maxSum = tree[i].maxPref = tree[i].maxSuf = 0;
             tree[i].sum = -k;
     }
     for(int i=N-1;i>0;i--)
     {
             tree[i].maxSum = tree[i].maxPref = tree[i].maxSuf = 0;
             tree[i].sum = tree[i*2].sum + tree[i*2+1].sum;
     }
}
void Update(int i)
{
     tree[i].maxSum = max(tree[i*2].maxSuf + tree[i*2+1].maxPref, max(tree[i*2].maxSum, tree[i*2+1].maxSum) );
     tree[i].maxPref= max(tree[i*2].maxPref, tree[i*2].sum + tree[i*2+1].maxPref);
     tree[i].maxSuf = max(tree[i*2+1].maxSuf, tree[i*2+1].sum + tree[i*2].maxSuf);
     tree[i].sum = tree[i*2].sum + tree[i*2+1].sum;
}
void Add(int i,int x)
{
     i += N;
     tree[i].sum += x;
     tree[i].maxSum = tree[i].maxPref = tree[i].maxSuf = max(tree[i].sum, 0LL);
     for(i/=2; i > 0; i/=2)Update(i);
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&d);
    for(N=1;N<=n-d;N*=2);
    InitializeTree();
    while(--m>=0)
    {
                 scanf("%d%d",&r,&a);
                 Add(r-1,a);
                 if(tree[1].maxSum > (long long int)d*k)printf("NIE\n");
                 else printf("TAK\n");
    }
    return 0;
}
