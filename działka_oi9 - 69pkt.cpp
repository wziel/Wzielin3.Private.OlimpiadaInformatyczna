//Wojciech Zieliñski 2AL
#include<stdio.h>
#include<stack>
using namespace std;
bool boo[2001][2001];
int ile[2001][2001];
int k,n;
stack<int>wys,kol;
int main()
{
    int max=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&boo[i][j]);
		}
	}
	for(int j=0;j<n;j++)
	{
		k=1;
		for(int i=0;i<n;i++)
		{
			if(boo[i][j]==0)
			{
				ile[i][j]=k; k++;
			}
			else
			{
				ile[i][j]=0; k=1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(kol.empty())
			{
				if(boo[i][j]==0)
				{
					wys.push(ile[i][j]);
					kol.push(j);
				}
			}
			else
			{
                while(!wys.empty() && ile[i][j]<wys.top())
                {
                                          k=kol.top(); 
                                          if(wys.top()*(j-k)>max) max=wys.top()*(j-k);
                                          kol.pop(); wys.pop();
                }
                if(!wys.empty() && ile[i][j]>wys.top())
                {
                                          wys.push(ile[i][j]);
                                          kol.push(j);
                }
                else if(wys.empty() && boo[i][j]==0)
                {
                                          wys.push(ile[i][j]);
                                          kol.push(k);
                }
            }
		}
	    while(!wys.empty())
	    {
                   if(wys.top()*(n-kol.top()) > max)    max=wys.top()*(n-kol.top());
                   wys.pop(); kol.pop();
        }
	}
    printf("%d",max);
    return 0;
}
