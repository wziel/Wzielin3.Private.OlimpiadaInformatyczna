#include<stdio.h>
#include<algorithm>
using namespace std;
int tab[1000000],n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&tab[i]);
    sort(tab,tab+n);
    for(int i=1;i<n;i++) if(tab[i]-tab[0]>tab[0])tab[0]=tab[i]-tab[0];
    printf("%d",tab[0]);
    return 0;
}
