#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int help[12]={0,0,97,1,1,97,0,1,98,1,0,99};
    vector<bool>v;
int main()
{
    int n;
    scanf("%d",&n);
    switch(n)
    {
             case 1: {printf("1\na");   return 0;}
             case 2: {printf("2\nab");  return 0;}
             case 3: {printf("2\naba"); return 0;}
    }
    printf("3\n");
    v.push_back(0); v.push_back(1);
    while(v.size()<=n)
    {
                      int len=v.size();
                      for(int i=0;i<len;i++)
                      {
                              if(v[i]==0)v.push_back(1);
                              else       v.push_back(0);
                      }
    }
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<12;j+=3)if(v[i]==help[j] && v[i+1]==help[j+1])
            {
                    printf("%c",char(help[j+2]));
                    break;
            }
    }
    return 0;
}
