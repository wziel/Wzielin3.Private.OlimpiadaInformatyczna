#include<stdio.h>
using namespace std;
bool isLegal(int a, int b, int c)
{
            if(((a>0&&b>0&&c>0) && ((a<3&&b<3&&c<3)||(a%2==0&&b%2==0&&c%2==0)) ) || (a>2&&b>2&&c>2) || (a%2==1&&b%2==1&&c%2==1))return 0;
            return 1;
}
int wynik(int a1,int a2,int b1,int b2,int prev,int last)
{
    if(a1+a2+b1+b2<=1)return 1;
    int m=0;
    if(a1>0 && isLegal(prev,last,1))m += wynik(a1-1,a2,b1,b2,last,1);
    if(a2>0 && isLegal(prev,last,2))m += wynik(a1,a2-1,b1,b2,last,2);
    if(b1>0 && isLegal(prev,last,3))m += wynik(a1,a2,b1-1,b2,last,3);
    if(b2>0 && isLegal(prev,last,4))m += wynik(a1,a2,b1,b2-1,last,4);
    return m;
}
int main()
{
    int a1,a2,b1,b2;
    scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
    printf("%d",wynik(a1,a2,b1,b2,0,0));
    return 0;
}
