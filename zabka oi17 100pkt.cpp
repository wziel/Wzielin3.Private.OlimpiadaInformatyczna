#include<iostream>
#include<stdio.h>
using namespace std;
int n,k,a,b,father[1000000],wynik[1000000],temp[1000000];//uzywamy tablic do skladania funkcji poprzez szybkie
long long int m,tab[1000000];                                                                      //potegowanie. magia jakich malo
void zloz_funkcje(int f[],int g[])                                                    //jak nie wiesz o co chodzi to jest tak jakby obliczanie
{                                                                                     //trasy o dlugosci n, poprzez skladanie tablic tras
     for(int i=0;i<n;i++)temp[i]=f[g[i]];                                             //o dlugosci k i n-k. tak jak w chomikach
     for(int i=0;i<n;i++)f[i]=temp[i]; //przepisujemy to co wyliczylismy do f dlatego wazna kolejnosc w jakiej podajemy funkcje
}
int main()
{
    scanf("%d %d %lld",&n,&k,&m);
    for(int i=0;i<n;i++)scanf("%lld",&tab[i]);
    father[0]=k; a=0; 
    for(int i=1;i<n;i++)                          //obliczanie bezposredniego ojca
    {
                while(a+k+1<n && tab[i]-tab[a]>tab[a+k+1]-tab[i])a++;
                if(tab[i]-tab[a]<tab[a+k]-tab[i])father[i]=a+k;
                else                             father[i]=a;
    }
    for(int i=0;i<n;i++) wynik[i]=i; //na poczatek funkcja identycznosciowa. father na poczatek ma trasy dlugosci 2^0
    while(m>0)
    {
              if(m%2==1)zloz_funkcje(wynik,father); //w father mamy trasy dlugosci 2^a, a w wynik syme dotychczasowych
              m=m/2;
              zloz_funkcje(father,father); //obliczamy trasy o dlugosci nastepnej potegi poprzez zlozenie 2 razy poprzedniej
    }
    for(int i=0;i<n;i++)printf("%d ",wynik[i]+1); 
    return 0;
}
