//nie uzywac % za nic bo w cholere opóŸnia
#include<iostream>
#include<stdio.h>
using namespace std;
short int n,m,vert[1200][2];//x,y
int a,b,c,x,y,zysk;
long long int suma;
int f[600][600],fprim[600][600];
int skret(int x1,int y1,int x2,int y2)
{                           //>0 w lewo
    return x1*y2-x2*y1;     //<0 w prawo
}                           //na prostej
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){ scanf("%d %d",&vert[i][0],&vert[i][1]); vert[i+n][0]=vert[i][0]; vert[i+n][1]=vert[i][1]; }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    { 
            scanf("%d %d %d",&x,&y,&zysk); 
            suma+=zysk; 
            for(int j=0;j<n;j++)//dla wszystkich j wyznaczamy w jakim fprim[j][*] znajduje sie dana fabryka
            {
                  if(skret(vert[j+n-1][0]-vert[j][0],vert[j+n-1][1]-vert[j][1],x-vert[j][0],y-vert[j][1])==0)
                  {fprim[j][j]+=zysk;continue;}
                  a=j+n-1; b=j+1; 
                  if(b<j)b+=n; 
                  c=(a+b)/2;
                  while(c!=b)
                  {
                              
                              if(c==a || c==b){ b=a; break;}
                              if(skret(vert[c][0]-vert[j][0],vert[c][1]-vert[j][1],x-vert[j][0],y-vert[j][1])>0)
                                               {a=c;}
                                          else {b=c;}
                                                c=(a+b)/2;
                  }
                  if(a>=n)a-=n;
                  fprim[j][a]+=zysk;
            }
    }
    for(int i=0;i<n;i++) for(int j=i+2;j<n+i;j++) 
    {
            a=j; b=j-1;
            if(a>=n)a-=n; if(b>=n)b-=n;
            f[i][a]=fprim[i][a]+f[i][b];
    }
    long long int max=0,temp;
    for(int i=0;i<n;i++) for(int j=i+1;j<n+i-1;j++) for(int k=j+1;k<n+i;k++)
    {
            a=j; b=k;
            if(a>=n)a-=n; if(b>=n)b-=n;
            temp=suma-f[i][a]-f[a][b]-f[b][i];
            if(temp>max)max=temp;
    }
    printf("%d",max);
    return 0;
    
}
