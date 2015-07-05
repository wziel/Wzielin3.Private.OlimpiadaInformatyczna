#include<iostream>
using namespace std;
int tab1[26],tab2[26];
int main()
{
    ios_base::sync_with_stdio(0);
    int n,g;
    long long int w=0;
    string s;
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)
    {
            char a;
            cin>>a;
            g=tab2[int(a)-65];
            while(s[tab1[int(a)-65]]!=a)
            {
                                        if(s[tab1[int(a)-65]]!='@')g++;  
                                        tab1[int(a)-65]++;     
            }
            tab2[int(a)-65]=g;
            w=w+g;
            for(int i=0;i<int(a)-65;i++) if(tab2[i]>g)tab2[i]--;
            for(int i=int(a)-65+1;i<26;i++)  if(tab2[i]>g)tab2[i]--;
            s[tab1[int(a)-65]]='@';
            tab1[int(a)-65]++;
    }
    cout<<w;
    return 0;
}
