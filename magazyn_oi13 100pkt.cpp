#include<iostream>
#include<stdio.h>
using namespace std;
long long int n,x,y, suma;
struct punkt
{
       int long long x,y,ile;
};
punkt pkt[100000];
bool sortx(punkt a, punkt b)
{
    return a.x<b.x;
}
bool sorty(punkt a, punkt b)
{
    return a.y<b.y;
}
long long int bez(long long int x)
{
    if(x<0)x=-x;
    return x;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
            scanf("%d %d %d",&pkt[i].x,&pkt[i].y,&pkt[i].ile);
            suma+=pkt[i].ile;
            pkt[i].x-=pkt[i].y;                               //
            pkt[i].y+=pkt[i].y+pkt[i].x;                      //obrot o 45 stopni i mnozenie raz 2 (tak wychodzi)
    }
    ////////////////////////////////////////////////////////////szukamy mediany wzgledem x
    sort(&pkt[0],&pkt[n],sortx);
    long long int L=0,R=suma-pkt[0].ile,i=0,M=pkt[0].ile,min[3]={100000000000LL,0,0};
    while(R>L+M)
    {
              i++;
              R-=pkt[i].ile;
              if(pkt[i].x!=pkt[i-1].x) { L+=M;  M=0; }
              M+=pkt[i].ile;                
    }x=pkt[i].x;
    while(i+1<n && x==pkt[i+1].x)  { i++; R-=pkt[i].ile; M+=pkt[i].ile; }
    if(R+M<min[0]){min[0]=R+M; min[1]=0; min[2]=1;}//taki myk. w razie jakby sie okazalo ze nasz punkt nie bedzie na skrzyzowaniu(x.5000)
    if(L+M<min[0]){min[0]=L+M; min[1]=1; min[2]=0;}//to obliczamy na ktorym pobliskim najlepiej bedzie go usadowic
    ///////////////////////////////////////////////////////////////szukamy mediany wzgledem y
    sort(&pkt[0],&pkt[n],sorty);
    L=0,R=suma-pkt[0].ile,i=0,M=pkt[0].ile;
    while(R>L+M)
    {
              i++;
              R-=pkt[i].ile;
              if(pkt[i].y!=pkt[i-1].y) { L+=M;  M=0; }
              M+=pkt[i].ile;
    }y=pkt[i].y;
    while(i+1<n && y==pkt[i+1].y)  { i++; R-=pkt[i].ile; M+=pkt[i].ile;}
    if(L+M<min[0]) {min[0]=L+M; min[1]=1; min[2]=1;}//taki sam myk jak powyzej
    if(R+M<min[0]) {min[0]=R+M; min[1]=0; min[2]=0;}//
    ///////////////////////////////////////////////////////////////rekonwertujemy o 45 stopni ten punkt (musimy jeszcze podzielic przez dwa 
    x+=y;       //
    y+=y-x;     //
    if(x!=(int(x/2))*2)//jezeli punkt nie jest na skrzyzowaniu to robimy myk ktory obliczylismy wczesniej
    {
        x=x/2; y=y/2;
        x+=min[1]; y+=min[2];
        x=x*2; y=y*2;
    }
    printf("%lld %lld",x/2,y/2);
    return 0;
}
