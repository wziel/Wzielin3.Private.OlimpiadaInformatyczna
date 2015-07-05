#include<stdio.h>
using namespace std;
int tab[1500000];
int main()
{
    int n,m,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&tab[i]);
    scanf("%d",&m);
    if(m>n)n=m;
    for(int i=0;i<m;i++)
    {
            scanf("%d",&a);
            if(a==1)tab[i]++;
    }
    if(tab[0]==2){tab[0]=0; tab[1]=1;}
    else if(tab[1]==2){tab[0]=1; tab[1]=0; tab[2]=1;}
    else if(tab[0]==1 && tab[1]==1){tab[0]=0; tab[1]=0; tab[2]++;}
    for(int i=1;i<=n;i++)
    {
            if(tab[i]>0 && tab[i+1]>0)
            {
                        if(tab[i+2]<2)
                        {
                                tab[i]--; tab[i+1]--; tab[i+2]++;
                                if(i+2>=n)n=i+2;
                        }
                        else
                        {
                                tab[i]=1; tab[i+1]=0; tab[i+2]=1; tab[i+3]=1;
                                if(i+3>=n)n=i+3;
                        }
            }
    }
    for(int i=n;i>2;i--)
    {
            if(tab[i]>1)
            {
                      tab[i] -= 2;
                      tab[i+1]=1;
                      if(tab[i-3]>0)
                      {
                                    tab[i-3]--; tab[i-1]=1;
                      }   
                      else tab[i-2]++;
            }
    }
    if(tab[2]>1){tab[0]++; tab[3]++; tab[2] -=2;}
    if(tab[1]>1){tab[0]++; tab[2]++; tab[1] -=2;}
    for(int i=1;i<=n;i++)
    {
            if(tab[i]>0 && tab[i+1]>0)
            {
                        if(tab[i+2]<2)
                        {
                                tab[i]--; tab[i+1]--; tab[i+2]++;
                                if(i+2>=n)n=i+2;
                        }
                        else
                        {
                                tab[i]=1; tab[i+2]=1; tab[i+3]=1;
                                if(i+3>=n)n=i+3;
                        }
            }
    }
    printf("%d ",n+1);
    for(int i=0;i<=n;i++)printf("%d ",tab[i]);
    return 0;
}
