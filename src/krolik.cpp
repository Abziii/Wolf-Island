#include "krolik.h"
#include<random>
#include <SFML/Graphics.hpp>
#include<iostream>

using namespace std;
krolik::krolik(int _x,int _y,char _symbol,char _mapa[][25],Texturki * texturki,int _maxKlatek)
{
       x=_x;
        y=_y;
        symbol=_symbol;
        tura=0;
        next_x=x;
        next_y=y;
        if(_mapa[x][y]!='B')  _mapa[x][y]=symbol;
         //ctor
         sprite.setTexture(texturki->krolik);
         textura=texturki->krolik;
                  maxKlatek=_maxKlatek;
         klatka=0;
         sekunda=0;
         FlipX=rand()%2?1:-1;
}
krolik::krolik(int _x,int _y,char _symbol,char _mapa[][25],sf::Texture texturaKrolika,int _maxKlatek)
{
       x=_x;
        y=_y;
        symbol=_symbol;
        tura=0;
        next_x=x;
        next_y=y;
        if(_mapa[x][y]!='B')  _mapa[x][y]=symbol;
         //ctor
           textura=texturaKrolika;
         sprite.setTexture(textura);
              maxKlatek=_maxKlatek;
         klatka=0;
         sekunda=0;
         FlipX=rand()%2?1:-1;
}
void krolik::ruch(char _mapa[][25],krolik ** rabits,int * totalnaIloscKrolikow,char nextTurnMap[][25],int maxIloscKrolkow)
{
    //cout<<"a"<<endl;
     if(_mapa[x][y]!='B') _mapa[x][y]=' ';
     FlipX=next_y<y?1:-1;//flipX

        x=next_x;y=next_y;
       if(_mapa[x][y]!='B')_mapa[x][y]=symbol;
        if(tura==8){tura=0;return;}//stoi w miejscu
        // ruch gdy tura nie jest 8 (inaczej to krolik stoi w miejcsu)
        int losX=x;
        int losY=y;

     //   if(!(this->checkWolnePole(_mapa,nextTurnMap))){return;}//jezeli nie ma pola wolnego to krolik nic nie robi
        while((losX==x && losY==y)|| losX>=25 || losY>=25 || losX<0 || losY<0)//|| nextTurnMap[losX][losY]!=' ')//by krolik przypadkiem nie wylosowal ze stoi w miejscu
        {
//cout<<"fuck "<<endl;
        losX=x+(rand()%3)-1;
         losY=y+(rand()%3)-1;
        }
        nextTurnMap[next_x][next_y]=' ';
        next_x=losX;
        next_y=losY;

        nextTurnMap[next_x][next_y]='k';
        tura++;
        int szansaNaRozmnozenie=rand()%6+1;
        if(szansaNaRozmnozenie==5 )
        {

         // infoLog="rozmnazam,totalna ilosc krolkow teraz to: "+to_string(totalnaIloscKrolikow+1)+"\n";

            this->rozmnoz(_mapa,rabits,totalnaIloscKrolikow,nextTurnMap,maxIloscKrolkow);
        }
}
bool krolik::checkWolnePole(char _mapa[][25],char nextTurnMap[][25])
{
           bool wolne=false;
        for(int i=-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
            {
                if(x+i>=25 || y+j>=25 || x+i<0 || y+j<0)//by nie wyszlo poza zakres
                {
                    continue;
                }
                if(_mapa[x+i][y+j]==' ' ||  _mapa[x+i][y+j]=='B')//&& nextTurnMap[x+i][y+j]==' '
                {
                    wolne=true;
                }
            }
        }
        return wolne;//by dostac czy jest wolne pole ( inaczej by nas informowalo czy jest zajete pole)
}
void krolik::rozmnoz(char _mapa[][25],krolik ** rabits,int * totalnaIloscKrolikow,char nextTurnMap[][25],int maxIloscKrolkow)
{
        if((*totalnaIloscKrolikow)>=maxIloscKrolkow){return;}
        int losX=x;
        int losY=y;
        if(!checkWolnePole(_mapa,nextTurnMap)){return;}//jezeli nie ma pola wolnego to nie rozmnaza
        while((losX==x && losY==y)|| losX>=25 || losY>=25 || losX<0 || losY<0 )//|| nextTurnMap[losX][losY]=='k'//by krolik przypadkiem nie wylosowal ze robi krolika w tym samym miejscu w miejscu
        {
         losX=x+(rand()%3)-1;
         losY=y+(rand()%3)-1;//problem bo mnoza kroliki tam gdzie inne maja isc
        }
        nextTurnMap[losX][losY]='k';
       (*totalnaIloscKrolikow)++;
          //  cout<<"pffff"<<endl;


        rabits[(*totalnaIloscKrolikow)-1]=new krolik(losX,losY,symbol,_mapa,textura,maxKlatek);//zrobic klase co zarzadza wskaznikami? (cos psuedolista)
}



krolik::~krolik()
{
    //dtor
}
