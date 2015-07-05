//super wlasnosc - jak q nie jest szablonem to wszystkie p<2*q nie sa szablonami -logarytm!
#include<iostream>
#include<stdio.h>
#include<list>
using namespace std;
list<int>lista;
char slowo[500000];
int length,presu[500000],presu2[500000];
bool check[500000]; 
int main()
{
    memset(slowo,'*',sizeof slowo);
    scanf("%s",slowo);
    while(slowo[length]!='*')length++; length--;
    //obliczanie tablicy prefiksowo sufiksowej w celu znalezienie wszystkich pref-sufiksow slowa
    presu[0]=0;
    for(int i=1;i<length;i++)
    {
            int k=i-1;
            while(k>0)
            {
                       if(slowo[i]==slowo[presu[k]])
                       { presu[i]=presu[k]+1; break; }
                       k=presu[k]-1;
            }
            if(k==0 && slowo[i]==slowo[0])   presu[i]=1;
            else if(k==0)                    presu[i]=0;
    }
    ///wrzucamy wszystkie prefikso-sufiksy na liste zeby je potem przejrzec
    int k=presu[length-1];
    while(k>0)
    {
              lista.push_front(k);
              k=presu[k-1];
    }
    //korzystamy z super zalozenia i wyrzucamy od razu niepotrzebne prefikso sufiksy
    list<int>::iterator it=lista.begin();      k=*it;               it++;
    while(it!=lista.end())
    {
                          if(*it<2*k)it=lista.erase(it);
                          else       { k=*it;    it++; }
    }
    //na koniec sprawdzamy czy jakis prefsuf jest szablonem - jak znajdziemy - konczymy
    it=lista.begin();
    while(it!=lista.end())
    {
                for(int i=0;i<*it;i++)presu2[i]=presu[i]; //check to tez taki presu tylko do sprawdzania
                memset(check,0,sizeof check);
                check[*it-1]=1; //wyrozniamy jakos element ostatni zeby bylo fajnie (zeby potem wiedziec ze znalezlismy slowo)
                int ttl=*it;   //time to live (jak znajde wystapienie slowa to bede przywracal mu wartosc *it)
                for(int i=*it;i<length;i++)
                {
                        if(ttl==0)break;                                            //
                        ttl--;                                                      //
                        int k=i-1;                                                  //
                        while(k>0)                                                  //
                        {                                                           //
                                  if(slowo[i]==slowo[presu2[k]])                     //
                                  {                                                 //
                                            presu2[i]=presu2[k]+1;                  //
                                            if(check[presu2[k]]==1)                 //
                                            {                                       //
                                                                 ttl=*it;           //Dla kazdego prefikso sufiksu robimy zmodyfikowany KMP
                                                                 check[i]=1;        //zeby sprawdzic czy jest szablonem
                                            }break;                                 //
                                  }                                                 //
                                  k=presu2[k]-1;                                    //
                        }                                                           //
                        if(k==0)                                                    //
                        {                                                           //
                                if(slowo[i]==slowo[0])                              //
                                {                                                   //
                                               presu2[i]=1;                         //
                                               ttl=*it;   //w tym wypadku zawsze 1 ale co tam dajmy *it  
                                               if(check[0]==1)check[i]=1;           //          
                                }                                                   //
                                else ttl=0;                                       //         
                        }                                                       //
                }                                                          
                if(ttl==0){it++; continue;}
                printf("%d",*it);return 0;
                
    }
    printf("%d",length);
    return 0;
}
