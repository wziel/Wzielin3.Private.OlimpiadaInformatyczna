#include<iostream>
#include<stdio.h>
using namespace std;
int malew[132000],duzew[132000];
int znajdzM(int a)
{
    int k=1;
    while(k<a)k=k*2;
    return k;
}
int main()
{
    int n,wolne,z,p,k,c,p1,k1,wp,wk;
    scanf("%d%d%d",&n,&wolne,&z);
    int M=znajdzM(n);
    while(z>0)
    {
              z--;
              scanf("%d %d %d",&p,&k,&c);p--; k -= 2;
              p1=M+p; k1=M+k; 
              wp=0; wk=0;
              if(p1==k1)wp=malew[p1];
              while(p1/2!=k1/2)
              {
                         wp+=malew[p1];
                         if(p1%2==0)wp=max(wp,duzew[p1+1]);
                         p1=p1/2;
                         
                         wk+=malew[k1];
                         if(k1%2==1)wk=max(wk,duzew[k1-1]);
                         k1=k1/2;
              }
              if(p1!=k1)
              {
                        wp+=malew[p1];
                        wk+=malew[k1];
              }
              if(wk>wp)wp=wk; 
              p1=p1/2;
              while(p1!=1)
              {
                          wp+=malew[p1];
                          p1=p1/2;
              }
              if(wp+c>wolne){printf("N\n");continue;}
              printf("T\n");
              p1=M+p; k1=M+k;
              if(p==k){malew[p1]+=c; duzew[p1]+=c;}
              else
              {
                      malew[p1]+=c; malew[k1]+=c; duzew[p1]+=c; duzew[k1]+=c;
                      while(p1/2!=k1/2)
                      {
                                   if(p1%2==0){malew[p1+1]+=c; duzew[p1+1]+=c;}
                                   p1=p1/2;
                                   duzew[p1]=malew[p1]+max(duzew[p1*2],duzew[p1*2+1]);
                                   
                                   if(k1%2==1){malew[k1-1]+=c; duzew[k1-1]+=c;}
                                   k1=k1/2;
                                   duzew[k1]=malew[k1]+max(duzew[k1*2],duzew[k1*2+1]);
                      }
              }
              while(p1!=1)
              {
                          p1=p1/2; duzew[p1]=malew[p1]+max(duzew[p1*2],duzew[p1*2+1]); 
              }
    }
    return 0;
}
