#include "wilk.h"
#include<random>
#include<iostream>
using namespace std;
wilk::wilk(int _x,int _y,char _mapa[][25],Texturki * texturki,double _fat,bool _facet,int _maxKlatek)
{
        x=_x;//ctor
        y=_y;
        next_x=x;
        next_y=y;
        symbol=_facet?'x':'w';
        fat=_fat;
        facet=_facet;
          if(_mapa[x][y]!='B')_mapa[x][y]=symbol;
         sprite.setTexture(_facet?texturki->wilk:texturki->wilczyca);
         textura=_facet?texturki->wilk:texturki->wilczyca;
         texturka=texturki;
         maxKlatek=_maxKlatek;
         klatka=0;
         sekunda=0;
         FlipX=rand()%2?1:-1;
         kills=0;
}
 void wilk::ruch(char _mapa[][25],wilk ** wolfW,krolik **rabits,int * totalnaIloscKrolikow,int * totalnaIloscWilkow,char nextTurnMap[][25])
 {
     if(_mapa[x][y]=='k' && fat>0){  cout<<"fat:"<<fat<<endl;fat++;_mapa[x][y]=symbol;zjadanieKrolika(rabits,totalnaIloscKrolikow,nextTurnMap);return;}//krolik na tym samym polu
        if(_mapa[x][y]=='w' && facet){cout<<"mnoze wilki"<<endl;rozmnoz(_mapa,wolfW,totalnaIloscWilkow);}
          if(_mapa[x][y]!='B')_mapa[x][y]=' ';
        x=next_x;
        y=next_y;
         if(_mapa[x][y]!='B') _mapa[x][y]=symbol;

        fat-=0.1;
        if(fat<0){  if(_mapa[x][y]!='B')_mapa[x][y]=' ';umieranie(wolfW,totalnaIloscWilkow);return;}

        int losX=x;
        int losY=y;

        if(checkWolnePole(_mapa,totalnaIloscKrolikow)){return;}//tu sprawdza czy jest krolik albo wilczyca cout<<"fuck this"<<endl;
        if(checkIfPathfIsBlocked(_mapa)){return;}
                while((losX==x && losY==y)|| losX>=25 || losY>=25 || losX<0 || losY<0 || _mapa[losX][losY]=='B')//jak nie to idz tam gdzie wolne(losowo)
        {

        losX=x+(rand()%3)-1;
         losY=y+(rand()%3)-1;
        }
      //
        next_x=losX;
        next_y=losY;
        FlipX=next_y<y?1:-1;


 }
   bool wilk::checkWolnePole(char _mapa[][25],int * totalnaIloscWilkow)
   {
                   bool gonWilczyce=false;//by gonil wilczyce jezeli jest to facet i krolika nie ma
                    for(int i=-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
            {
                if(x+i>=25 || y+j>=25 || x+i<0 || y+j<0 )//by nie wyszlo poza zakres
                {

                    continue;
                }
                if(_mapa[x+i][y+j]=='k' && (fat<15 && *totalnaIloscWilkow>10))
                {
                    int losX=x;
                    int losY=y;

                    while( losX>=25 || losY>=25 || losX<0 || losY<0 || _mapa[losX][losY]!='k')//jak nie to idz tam gdzie wolne(losowo)
                    {
                    losX=x+(rand()%3)-1;
                    losY=y+(rand()%3)-1;
                    }

                     next_x=losX;
                     next_y=losY;
                     FlipX=next_y<y?1:-1;

                    return true;
                }
                else if(facet && _mapa[x+i][y+j]=='w')
                {

                    // _mapa[x][y]=' ';
                     next_x=x+i;
                     next_y=y+j;
                     gonWilczyce=true;

                     FlipX=next_y<y?1:-1;
                }
            }
        }
        return gonWilczyce;
   }

    void wilk::zjadanieKrolika(krolik **rabits,int * totalnaIloscKrolikow,char nextTurnMap[][25])
    {
            for(int i=0;i<(*totalnaIloscKrolikow);i++)
            {
                if(rabits[i]->x==x && rabits[i]->y==y)
                {
                    kills++;
                    nextTurnMap[rabits[i]->next_x][rabits[i]->next_y]=' ';
                   delete rabits[i];

                   for(int j=i;j<(*totalnaIloscKrolikow);j++)
                   {
                       rabits[j]=rabits[j+1];//przesuwanie adresu krolikow
                   }
                    rabits[(*totalnaIloscKrolikow)]=NULL;
                   (*totalnaIloscKrolikow)--;

                }
            }
    }
    void wilk::umieranie(wilk ** wolfW,int * totalnaIloscWilkow)
    {
                        for(int i=0;i<(*totalnaIloscWilkow);i++)
            {
                if(wolfW[i]->fat<=0)
                {

                  delete wolfW[i];
                  wolfW[i]=NULL;

                   for(int j=i;j<(*totalnaIloscWilkow);j++)
                   {
                       wolfW[j]=wolfW[j+1];//przesuwanie adresu krolikow
                   }
                    wolfW[(*totalnaIloscWilkow)]=NULL;
                  (*totalnaIloscWilkow)--;
                }
            }
    }
    void wilk::rozmnoz(char _mapa[][25],wilk ** wolfW,int * totalnaIloscWilkow)
    {
        int losX=x;
        int losY=y;
        if(!checkWolnePole(_mapa,totalnaIloscWilkow)){return;}//jezeli nie ma pola wolnego to nie rozmnaza
        while(((losX==x && losY==y)|| losX>=25 || losY>=25 || losX<0 || losY<0 ) || _mapa[losX][losY]=='B')//by wilk nie wylosowal ze robi w miejsce
        {
        losX=x+(rand()%3)-1;
         losY=y+(rand()%3)-1;
        }
        (*totalnaIloscWilkow)++;
        bool _facet=rand()%2;//jezeli 1 to facet
        wolfW[(*totalnaIloscWilkow)-1]=new wilk(losX,losY,_mapa,texturka,1,_facet==1,maxKlatek);//zrobic klase co zarzadza wskaznikami? (cos psuedolista)
    }
bool wilk::checkIfPathfIsBlocked(char _mapa[][25])
{
    bool blocked=true;
                        for(int i=-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
            {
                if(x+i>=25 || y+j>=25 || x+i<0 || y+j<0 || (i==0 &&j==0))//by nie wyszlo poza zakres
                {
                    continue;
                }
                if(_mapa[x+i][y+j]!='B')
                {
                    blocked=false;
                }
            }
        }
    return blocked;

}

wilk::~wilk()
{
    //dtor
}
