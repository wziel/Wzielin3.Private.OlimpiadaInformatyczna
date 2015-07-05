#include<iostream>
#include<stdio.h>
#include<list>
using namespace std;
double EPS = 0.00000000001;
struct point
{ double x,y; };
point vert[1001],punkt[6];
int sgndet(point a,point b,point c)
{
    double q = a.x*b.y + a.y*c.x + b.x*c.y - a.x*c.y - a.y*b.x - b.y*c.x;//polozenie c wzgledem wektora a->b
    if(q >  EPS)return  1;//lewa
    if(q < -EPS)return -1;//prawa
    else        return  0;//na prostej
}
bool Comparedoubles(double a,double b){ return ( (a-b) < EPS && (b-a) < EPS ); }
bool IntersectionPoint(point a1,point a2,point b1,point b2)//szukanie punktu przeciecia
{
    if( Comparedoubles(  (a1.x-a2.x)*(b1.y-b2.y), (a1.y-a2.y)*(b1.x-b2.x) )   )return 0;
    //sprawdzanie równoleg³oœci wektorowo
    if( Comparedoubles( b1.x, b2.x ) ){swap(a1,b1); swap(a2,b2);}
    if( Comparedoubles( a1.x, a2.x ) )
    {
            punkt[0].x = a1.x;
            if( Comparedoubles( b1.y, b2.y ) )punkt[0].y = b1.y;
            else                              punkt[0].y = (b2.y - b1.y)*(a1.x - b1.x)/(b2.x - b1.x) + b1.y;
            return 1;
    }
    if( Comparedoubles( b1.y, b2.y ) ){swap(a1,b1); swap(a2,b2); }
    if( Comparedoubles( a1.y, a2.y ) )
    {
            punkt[0].y = a1.y;
            if( Comparedoubles( b1.x, b2.x ) )punkt[0].x = b1.x;
            else                              punkt[0].x = (b2.x - b1.x)*(a1.y - b1.y)/(b2.y - b1.y) + b1.x;
            return 1;
    }
    double AP,BP;
    AP=(a2.y - a1.y)/(a2.x - a1.x);
    BP=(b2.y - b1.y)/(b2.x - b1.x);
    punkt[0].x=(AP*a1.x - a1.y - BP*b1.x + b1.y)/(AP-BP);
    punkt[0].y= AP*punkt[0].x - AP*a1.x + a1.y;
    return 1;
} 
bool CheckLine(point a1,point a2,point b)//sprawdzenie czy punkt b nie lezy na odcinku a1a2
{
     
         if( b.x > max(a1.x,a2.x)+EPS || b.x < min(a1.x,a2.x)-EPS || 
             b.y > max(a1.y,a2.y)+EPS || b.y < min(a1.y,a2.y)-EPS) return 1;
         return 0;
}
int t,n,a,b,IntPointFound;
bool bol;
char IsBright[1001];
list< point >vertlist;
list< point >::iterator it,it2,itend;
int main()
{
    scanf("%d",&t);
    while(--t>=0)
    {
                 IntPointFound = 0;
                 while(!vertlist.empty())vertlist.pop_back();
                 scanf("%d",&n);
                 for(int i=0;i<n;i++)
                 {
                         scanf("%lf %lf",&vert[i].x,&vert[i].y);
                         vertlist.push_back(vert[i]);
                 }vert[n]=vert[0];
                 for(int i=0;i<n;i++)
                 {
                         getchar();
                         scanf("%c",&IsBright[i]); 
                 }
                 ///sprawdzanie czy œciany nieoœwietlone przecinaj¹ sie w jednym punkcie
                 for(int i=n-1; i>=0; i--)if(IsBright[i]=='C')
                 {
                         IsBright[i]='Z'; //szukamy ciagu czarnych
                         a=(i-1); b=(i+1)%n;
                         while(b != a && IsBright[b]=='C')
                         {
                                    IsBright[b]='Z';
                                    b++;
                         }
                         if(b == a){ IntPointFound = -1; break; }
                         while(a>=0 && IsBright[a]=='C')
                         {
                                    IsBright[a]='Z';
                                    a--;
                         }a++; 
                         bol=0;//patrzymy czy nie ma wypuklosci w ciagu czarnych
                         if( sgndet(vert[a],vert[b],vert[(a+1)%n]) == 1 )bol=1;
                         if((a+1)%n != b)
                         {
                                    for(int j=a+2; j%n!=b; j++)
                                    {
                                            if( sgndet(vert[a],vert[b],vert[j%n])== 1 )bol=1;
                                            if(IntersectionPoint(vert[a],vert[b],vert[(j-1)%n],vert[j%n]) == 0)continue;
                                            if(CheckLine(vert[a],vert[b],punkt[0]) == 0 && CheckLine(vert[(j-1)%n],vert[j%n],punkt[0]) == 0)
                                            { bol=0; break; }
                                    }
                                    if(bol ==0){ IntPointFound = -1; break;}//wszystkie po prawej, albo jest przeciecie 
                         }
                         if(IntPointFound == 0)//jesli znalezlismy pierwsza prosta to zapisujemy ja 
                         {
                                  punkt[4]=vert[a];
                                  punkt[5]=vert[b];
                                  IntPointFound = 1;
                         }
                         else if(IntPointFound == 1)//znalezlismy druga prosta to znajdujemy punkt przeciecia punkt[2]
                         {
                                  if(IntersectionPoint(punkt[4],punkt[5],vert[a],vert[b]) == 0){IntPointFound = -1; break;}
                                  if(CheckLine(vert[a],vert[b],punkt[0]) == 0 || CheckLine(punkt[4],punkt[5],punkt[0]) == 0)
                                                                                               {IntPointFound = -1; break;}
                                  punkt[2]=punkt[0];
                                  IntPointFound = 2;
                         }
                         else if(IntPointFound == 2)//sprawdzamy czy nastepna prosta przecina sie w tym samymm punkcie
                         {
                                  if(IntersectionPoint(punkt[4],punkt[5],vert[a],vert[b]) == 0){IntPointFound = -1; break;}
                                  if(!Comparedoubles(punkt[0].x,punkt[2].x) || !Comparedoubles(punkt[0].y,punkt[2].y) || 
                                  CheckLine(vert[a],vert[b],punkt[2]) == 0)                    {IntPointFound = -1; break;}
                         }
                         else break;
                 }
                 if(IntPointFound == -1){printf("NIE\n"); continue;}
                 if(IntPointFound ==  2)
                 {
                                bol = 0;  
                                for(int i=0;i<n;i++)if(IsBright[i]=='S' && sgndet(vert[i],vert[i+1],punkt[2]) >= 0 )
                                            {printf("NIE\n"); bol = 1; break;}
                                if(bol == 0) printf("TAK\n");
                                continue;
                 }
                 it=vertlist.begin(); int ii=0;
                 while(it!=vertlist.end())//usuwamy posrednie wierzcholki czarne ktore nie sa do niczego potrzebne
                 {
                                if(IsBright[ii]=='Z')
                                {
                                                     ii++; it++;
                                                     while(it != vertlist.end() && IsBright[ii]=='Z')
                                                     {
                                                             it=vertlist.erase(it);   
                                                             ii++;  
                                                     }
                                }      
                                else {ii++; it++;}    
                 }
                 if(!vertlist.empty() && IsBright[n-1] == 'Z' && IsBright[0] == 'Z')vertlist.erase(vertlist.begin());
                 if(vertlist.size() < 3){printf("NIE\n"); continue; }
                 punkt[0]=*vertlist.begin(); vertlist.push_back(punkt[0]);
                 ///sprawdzanie czy mo¿na oœwietliæ œciany oœwietlone
                 for(int i=0;i<n;i++)if(IsBright[i]=='S')
                 {
                         it=vertlist.begin(); it2=vertlist.begin(); it2++; itend=vertlist.end(); itend--; 
                         while(it!=itend)
                         {
                                     punkt[0]=*it; punkt[1]=*it2;
                                     if(Comparedoubles(punkt[0].x,punkt[1].x) && Comparedoubles(punkt[0].y,punkt[1].y))
                                     {
                                                         it=vertlist.erase(it);
                                                         it2=it; it2++;
                                                         continue;
                                     }
                                     if( sgndet(vert[i],vert[i+1],*it) == 1 )//it po lewej
                                     {
                                         if(sgndet(vert[i],vert[i+1],*it2) >= 0)//it2 nie po prawej
                                         {
                                                           it=vertlist.erase(it);
                                                           it2=it; it2++;       
                                                           if(it==itend)  
                                                           {
                                                                        vertlist.erase(it);
                                                                        break;
                                                           }      
                                         }
                                         else//it2 po prawej
                                         {
                                                           IntersectionPoint(vert[i],vert[i+1],*it,*it2);
                                                           *it=punkt[0];
                                                           it++; it2++;
                                         }
                                     }
                                     else if(sgndet(vert[i],vert[i+1],*it) == 0)//it na prostej
                                     {
                                          if(sgndet(vert[i],vert[i+1],*it2) == 1 && it2==itend) {vertlist.erase(it2); break;}
                                          it++; it2=it; it2++;
                                     }
                                     else//it po prawej
                                     {
                                         if(sgndet(vert[i],vert[i+1],*it2) == 1)//it2 po lewej
                                         {
                                                           IntersectionPoint(vert[i],vert[i+1],*it,*it2);
                                                           if(it2 == itend)
                                                           {
                                                                  *it2=punkt[0];
                                                                  break;
                                                           }
                                                           else 
                                                           {
                                                                vertlist.insert(it2,punkt[0]);
                                                                it=it2;
                                                                it2++;
                                                           }
                                         
                                         }
                                         else{it++; it2++;}//it2 nie po lewej}
                                     }
                                     itend=vertlist.end(); itend--;
                         }  
                         it=vertlist.end(); it--;//powtorzenie pierwszego elementu na koniec
                         punkt[0]=*vertlist.begin(); punkt[1]=*it;
                         if(!Comparedoubles(punkt[0].x,punkt[1].x) || !Comparedoubles(punkt[0].y,punkt[1].y))vertlist.push_back(punkt[0]);
                         if(vertlist.size() < 4){IntPointFound = -1; break;}
                 }          
                 if(IntPointFound ==-1){printf("NIE\n"); continue;}
                 if(IntPointFound == 0){printf("TAK\n"); continue;}
                 ///sprawdzanie czy punkt œciany ciemnej znajduje sie w figurze ograniczonej przez œciany jasne
                 if(IntPointFound == 1)
                 {
                                  IntPointFound = 0;
                                  it=vertlist.begin();
                                  while(it!=vertlist.end())
                                  {
                                             a=sgndet(punkt[4],punkt[5],*it);
                                             if(a == 0){it++; continue;}
                                             if(a == -IntPointFound)//szukanie dwoch punktow po roznych stronach prostej
                                             {    
                                                  printf("TAK\n");
                                                  IntPointFound = 2;
                                                  break;
                                             }     
                                             IntPointFound = a; 
                                             it++;   
                                  }
                                  if(IntPointFound < 2) printf("NIE\n");
                 }
    }
    return 0;
}
