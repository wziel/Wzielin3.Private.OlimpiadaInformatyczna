#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;
int tab[100001];
int main()
{
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            scanf("%d",&a); v.push_back(a);
    }
    sort(&v[0],&v[n]);
    tab[0]=v[0]; tab[1]=v[1]; tab[2]=v[0]+v[1]+v[2];
    for(int i=3;i<n;i++)
    {
            tab[i]=min(tab[i-1]+v[0]+v[i], tab[i-2]+v[0]+v[i]+2*v[1]);
    }
    printf("%d",tab[n-1]);
    return 0;
}
