#include<iostream>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    int a=3;
    int i=5;
    int tab[13]={2,3,2,5,7,2,3,11,13,2,17,19,23};
    long long int q=1;
    while(q<n)
    {
              for(int i=0;i<13;i++)
              {
                      q=q*tab[i];
                      if(q>n && i>0)
                      {
                             q=q/tab[i];
                             break;
                      }
              }
              if(q==n)
              {
                      cout<<q;
                      return 0;
              }
              
    }
    q=q/2;
    cout<<q;
    return 0;
}
