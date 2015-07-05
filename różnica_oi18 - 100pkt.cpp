//Wojciech Zieliñski
#include<stdio.h>
#include<vector>
using namespace std;
vector<int>v[26];
int main()
{
    int n,wynik=0;
    char a;
    scanf("%d",&n); getchar();
    for(int i=0;i<n;i++)
    {
            scanf("%c",&a);
            v[int(a)-97].push_back(i);
    }
    for(int i=0;i<25;i++)
    {
            if(v[i].size()==0)continue;
            for(int j=i+1;j<26;j++)
            {
                    if(v[j].size()==0)continue;
                    int maxa=0,maxb=0,wyna=0,wynb=0,apoz=0,bpoz=0;
                    bool a=0, b=0;
                    while(true)
                    {
                               if(apoz==v[i].size())
                               {
                                                    if(b==0)wyna--;
                                                    if(wyna>maxa)maxa=wyna;
                                                    while(bpoz<v[j].size())
                                                    {
                                                                bpoz++; wynb++;           
                                                    }
                                                    if(a==0)wynb--;
                                                    if(wynb>maxb)maxb=wynb;
                                                    if(b==0)wyna--;
                                                    if(wyna>maxa)maxa=wyna;
                                                    break;
                               }
                               else if(bpoz==v[j].size())
                               {                            
                                                   if(a==0)wynb--;
                                                   if(wynb>maxb)maxb=wynb;
                                                   while(apoz<v[i].size())
                                                   {
                                                                apoz++; wyna++;
                                                   }
                                                   if(b==0)wyna--;  
                                                   if(wyna>maxa)maxa=wyna;
                                                   break;
                               }
                               if(v[i][apoz]<v[j][bpoz])
                               {
                                                   apoz++;
                                                   wyna++;
                                                   if(a==0 && wynb>0)
                                                   {
                                                           wynb--;
                                                           if(wynb>maxb)maxb=wynb;
                                                           a=1;
                                                   }
                                                   else 
                                                   {
                                                        if(wynb==0)a=0;
                                                        else 
                                                        {
                                                             if(wynb>maxb)maxb=wynb;
                                                             wynb--; 
                                                        }
                                                   }
                               }
                               else
                               {
                                                   bpoz++;
                                                   wynb++;
                                                   if(b==0 && wyna>0)
                                                   {
                                                           wyna--;
                                                           if(wyna>maxa)maxa=wyna;
                                                           b=1;
                                                   }
                                                   else 
                                                   {
                                                          if(wyna==0)b=0;
                                                          else 
                                                          {
                                                               if(wyna>maxa)maxa=wyna;
                                                               wyna--; 
                                                          }
                                                   }
                               }
                    }
                    if(maxa>wynik)wynik=maxa;
                    if(maxb>wynik)wynik=maxb;
            }
    }
    printf("%d",wynik);
    return 0;
}
