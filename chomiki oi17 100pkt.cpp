#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
int n,m,kmptab[100000];
string s[200];
long long int KIJ[30][200][200],wynik[2][200][200];
int KMP(string slowo,string nakladka)
{
    string s=nakladka+'#'+slowo+'*';
    kmptab[0]=0;
    int i,a;
    for(i=1; s[i]!='*'; i++)
    {
            a=kmptab[i-1];
            while(s[i]!=s[a] && a>0) a=kmptab[a-1];
            if(s[i]==s[a]) kmptab[i]=a+1;
            else kmptab[i]=0;
    }
    a=0;
    while(s[a]!='#')a++;
    if(a==kmptab[i-1])return a;
    return a-kmptab[i-1];
}
int main()
{
    ios_base::sync_with_stdio(0); 
    cin>>n>>m; m--;
    stack<int>st;                                  //
    long long int a=1073741824;                    //
    while(m<a)a=a/2;                               //
    while(a>0)                                     //licze binarnie m
    {                                              //zeby wiedziec potem
              if(a>m) st.push(0);                  //jakie tablice dodawac
              else  { st.push(1); m-=a; }          //
              a=a/2;                               //
    }                                              //
    
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)KIJ[0][i][j]=KMP(s[i],s[j]);
    for(int r=1;r<st.size();r++)
    {
            for(int i=0;i<n;i++)for(int j=0;j<n;j++)KIJ[r][i][j]=KIJ[r-1][i][i]+KIJ[r-1][i][j]; //wypelniam zeby nie bylo puste i rowne 0
            for(int k=0;k<n;k++)
            {
                    for(int i=0;i<n;i++)
                    {
                            for(int j=0;j<n;j++)
                            {
                                    KIJ[r][i][j]=min(KIJ[r][i][j],KIJ[r-1][i][k]+KIJ[r-1][k][j]);
                            }
                    }
            }
    }
    int nr=0;
    for(int p=0; !st.empty(); p++)
    {
            a=st.top(); st.pop();
            if(a==0)continue;
            nr++;
            for(int i=0;i<n;i++)for(int j=0;j<n;j++)wynik[nr%2][i][j]=KIJ[p][i][i]+wynik[(nr+1)%2][i][j];
            for(int k=0;k<n;k++)
            {
                    for(int i=0;i<n;i++)
                    {
                            for(int j=0;j<n;j++)
                            {
                                    wynik[nr%2][i][j]=min(wynik[nr%2][i][j],KIJ[p][i][k]+wynik[(nr+1)%2][k][j]);
                            }
                    }
            }
    }
    nr=nr%2;
    long long int minimum=KIJ[0][0][0]+wynik[nr][0][0];
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
            {
                    minimum=min(minimum,KIJ[0][i][i]+wynik[nr][i][j]);
            }
    }
    cout<<minimum;
    return 0;
}
