#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
short int wys[10005];
int ograniczenie=10002;
vector<int>uzyte,uzyskane;
int main()
{
    int n,h;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            scanf("%d",&h);
            wys[h]=1;
    }
    for(int i=1;i<ograniczenie;i++)
    {
            if(wys[i]==0 || wys[i]==2)continue;
            uzyte.push_back(i); 
            uzyskane.push_back(i); wys[i]=2;
            for(int j=0;j<uzyskane.size();j++)
            {
                    if(uzyskane[j]+i>=ograniczenie)continue;
                    if(wys[uzyskane[j]+i]==0) 
                    { 
                           ograniczenie=uzyskane[j]+i;
                    }      
                    else if(wys[uzyskane[j]+i]==1)
                    {
                            wys[uzyskane[j]+i]=2;
                            uzyskane.push_back(uzyskane[j]+i);
                    }    
            }
    }
    while(wys[ograniczenie]==0)ograniczenie--;
    printf("%d\n",ograniczenie);
    for(int i=0;i<uzyte.size();i++)printf("%d\n",uzyte[i]);
    return 0;
}
