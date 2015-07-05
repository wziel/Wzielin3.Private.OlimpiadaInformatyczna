#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
    int n,a,max=0,min=0,k;
    scanf("%d",&n);
    int tab[n][3]; for(int i=0;i<n;i++){tab[i][1]=0; tab[i][2]=0;}
    for(int i=0;i<n;i++)
    {
            scanf("%d",&a); a--;
            tab[i][0]=a;
            tab[a][1]++;
            tab[a][2]++;
    }
    queue<int>q;
    for(int i=0;i<n;i++)
    {
            if(tab[i][1]==0)
            {
                            q.push(i);
                            tab[i][1]=-1;
                            a=tab[i][0];
                            while(tab[a][1]!=-1)
                            {
                                       max++;
                                       tab[a][1]=-1;
                                       a=tab[a][0];
                            }
            }
    }
    for(int i=0;i<n;i++)
    {
            if(tab[i][1]==1)
            {
                            tab[i][1]=-1;
                            max++;
                            a=tab[i][0]; tab[a][1]=-1; a=tab[a][0];
                            while(tab[a][1]!=-1)
                            {
                                       max++;
                                       tab[a][1]=-1;
                                       a=tab[a][0];
                            }
            }
    }
    while(!q.empty())
    {
                    tab[q.front()][2]=-1;
                    a=tab[q.front()][0]; q.pop();
                    if(tab[a][2]>=0)
                    {
                                     min++;
                                     tab[a][2]=-1;
                                     a=tab[a][0];
                                     tab[a][2]--;
                                     if(tab[a][2]==0)q.push(a);
                    }
    }

    for(int i=0;i<n;i++)
    {
            if(tab[i][2]==1)
            {
                            tab[i][2]=-1;
                            k=1;
                            a=tab[i][0];
                            while(tab[a][2]>=0)
                            {
                                       k++;
                                       tab[a][2]=-1;
                                       a=tab[a][0];
                            }
                            if(k%2==1)k++;
                            min=min+(k/2);
            }
    }
    printf("%d %d",min,max);
    return 0;
}
