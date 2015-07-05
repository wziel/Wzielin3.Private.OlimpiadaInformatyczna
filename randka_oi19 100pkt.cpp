#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
    int tab[500000][6];
    queue<int>QQ[2];
    queue<int>MINUS;
    stack<int>s;
    int DC[500000];
    int n,k,x,y,XL=0,YL=0,L=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
            cin>>tab[i][0];
            tab[i][0]--;
            tab[tab[i][0]][1]++;
    }
    for(int i=0;i<n;i++)if(tab[i][1]==0)QQ[0].push(i);
    while(!QQ[L%2].empty())
    {
                     int i=0;
                     while(!QQ[L%2].empty())
                     {
                                            tab[QQ[L%2].front()][2]=L;
                                            tab[QQ[L%2].front()][3]=i;
                                            tab[QQ[L%2].front()][4]=tab[QQ[L%2].front()][0];
                                            tab[QQ[L%2].front()][5]=1;
                                            if(tab[tab[QQ[L%2].front()][0]][1]==1)
                                            {
                                                tab[tab[QQ[L%2].front()][0]][1]=0;
                                                s.push(QQ[L%2].front());
                                                s.push(tab[QQ[L%2].front()][0]);
                                                while(tab[tab[s.top()][0]][1]==1)
                                                {
                                                                    s.push(tab[s.top()][0]);
                                                                    tab[s.top()][1]=0;
                                                }
                                                if(tab[tab[s.top()][0]][1]==-1)
                                                {
                                                    tab[tab[s.top()][0]][1]=0;
                                                    QQ[(L+1)%2].push(tab[s.top()][0]);
                                                }
                                                else
                                                {
                                                    if(tab[tab[s.top()][0]][1]<-1)tab[tab[s.top()][0]][1]++;
                                                    else
                                                    {
                                                         MINUS.push(tab[s.top()][0]);
                                                         tab[tab[s.top()][0]][1]=(-1)*tab[tab[s.top()][0]][1]+1;
                                                    }
                                                }
                                                int j=1,k=tab[s.top()][0];
                                                while(!s.empty())
                                                {
                                                                tab[s.top()][2]=L;
                                                                tab[s.top()][3]=i;
                                                                tab[s.top()][4]=k;
                                                                tab[s.top()][5]=j;
                                                                j++;
                                                                s.pop();
                                                }

                                            }
                                            else
                                            {
                                                if(tab[tab[QQ[L%2].front()][0]][1]==-1)
                                                {
                                                    tab[tab[QQ[L%2].front()][0]][1]=0;
                                                    QQ[(L+1)%2].push(tab[QQ[L%2].front()][0]);
                                                }
                                                else
                                                {
                                                    if(tab[tab[QQ[L%2].front()][0]][1]<-1)tab[tab[QQ[L%2].front()][0]][1]++;
                                                    else
                                                    {
                                                         MINUS.push(tab[QQ[L%2].front()][0]);
                                                         tab[tab[QQ[L%2].front()][0]][1]=(-1)*tab[tab[QQ[L%2].front()][0]][1]+1;
                                                    }
                                                }
                                            }
                                            QQ[L%2].pop();
                                            i++;
                     }
                     while(!MINUS.empty())
                     {
                                          tab[MINUS.front()][1]=(-1)*tab[MINUS.front()][1];
                                          MINUS.pop();
                     }
                     L++;
    }
    for(int i=0;i<n;i++)
    {
            if(tab[i][1]==1)
            {
                            tab[i][1]=0;
                            tab[i][2]=50;
                            tab[i][3]=i;
                            tab[i][4]=i;
                            tab[i][5]=0;
                            int j=tab[i][0],licz=1;
                            while(j!=i)
                            {
                                       tab[j][1]=0;
                                       tab[j][2]=50;
                                       tab[j][3]=i;
                                       tab[j][4]=i;
                                       licz++;
                                       j=tab[j][0];
                            }
                            DC[i]=licz;
                            j=tab[i][0],licz=1;
                            while(j!=i)
                            {
                                       tab[j][5]=DC[i]-licz;
                                       j=tab[j][0];
                                       licz++;
                            }
            }
    }
    for(int i=0;i<k;i++)
    {
            cin>>x>>y;
            x--; y--;
            XL=0; YL=0;
            while(1)
            {
                    if(tab[x][2]<tab[y][2])
                    {
                                           XL=XL+tab[x][5];
                                           x=tab[x][4];
                    }
                    else if(tab[x][2]>tab[y][2])
                    {
                                          YL=YL+tab[y][5];
                                          y=tab[y][4];
                    }
                    if(tab[x][2]==tab[y][2])
                    {
                                          if(tab[x][3]==tab[y][3])
                                          {
                                                    if(tab[x][2]!=50)
                                                    {
                                                                if(tab[x][5]>tab[y][5]) XL=XL+tab[x][5]-tab[y][5];
                                                                else YL=YL+tab[y][5]-tab[x][5];
                                                    }
                                                    else if(x!=y)
                                                    {
                                                                int xc,yc;
                                                                if(tab[x][5]>tab[y][5])
                                                                {
                                                                                       xc=tab[x][5]-tab[y][5];
                                                                                       yc=DC[tab[y][3]]-xc; 
                                                                }
                                                                else
                                                                {
                                                                                        yc=tab[y][5]-tab[x][5];
                                                                                        xc=DC[tab[x][3]]-yc;
                                                                }
                                                                if(YL+yc<XL+xc)YL=YL+yc;
                                                                else if(XL+xc<YL+yc)XL=XL+xc;
                                                                else if(XL<YL)YL=YL+yc;
                                                                else XL=XL+xc;
                                                    }  
                                                    break;     
                                          }
                                          else
                                          {
                                                     if(tab[x][2]==50)
                                                     {
                                                                 XL=-1; YL=-1; 
                                                                 break;
                                                     }
                                                     else
                                                     {
                                                                 XL=XL+tab[x][5];
                                                                 x=tab[x][4];
                                                                 YL=YL+tab[y][5];
                                                                 y=tab[y][4];
                                                     }
                                         }
                    }
            } 
         cout<<XL<<" "<<YL<<"\n";
    }
    return 0;
}
