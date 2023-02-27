#include "mapa.h"
#include <SFML/Graphics.hpp>
#include<iostream>
#include"Animal.h"
using namespace std;
mapa::mapa(Texturki * _texturki,int _maxIloscWilkow,int _maxIloscKrolkow)
{
      texturki=(_texturki);
    sprite.setTexture(texturki->mapa);
    sprite.setScale(1,1);//poprawic pozniej
    spriteKrolik.setScale(1,1);
    spriteWilk.setScale(0.5,0.5);
    spriteWilczyca.setScale(0.5,0.5);
    spriteKoronki.setScale(0.5,0.5);
    spritePoleKursora.setScale(1,1);
    for(int i=0;i<25;i++)
{
    for(int j=0;j<25;j++)
    {
        mapaTekstowa[i][j]=' ';
        mapaTekstowaNextTurn[i][j]=' ';
    }
}
    rabits=new krolik* [_maxIloscKrolkow];
    wolfs=new wilk*[_maxIloscWilkow];
    koronka=Animal(5);
    maxIloscWilkow=_maxIloscWilkow;
    maxIloscKrolkow=_maxIloscKrolkow;

    totalnaIloscKrolikow=0;
    totalnaIloscWilkow=0;
    select=0;
    iloscWilczyc=0;

    spriteKrolik.setTexture(_texturki->krolik);
    spriteWilk.setTexture(_texturki->wilk);
    spriteWilczyca.setTexture(_texturki->wilczyca);
    spritePoleKursora.setTexture(_texturki->poleKursora);
    spriteKrzaki.setTexture(_texturki->krzaki);
    spriteKoronki.setTexture(_texturki->korona);
    spriteBunnyHead.setTexture(_texturki->bunnyHead);
    spriteWolfManHead.setTexture(_texturki->wolfManHead);
    spriteWolfWomanHead.setTexture(_texturki->wolfWomanHead);
    textLegendy.setFont(_texturki->adventureFont);

    spritePlay.setTexture(_texturki->play);
    spritePause.setTexture(_texturki->pause);

    textLegendy.setFillColor(sf::Color::White);
    textLegendy.setCharacterSize(32);


    spriteWolfManHead.scale(1.5,1.5);
    spriteWolfManHead.setPosition(630,800-32);




    spriteWolfWomanHead.scale(1.5,1.5);
    spriteWolfWomanHead.setPosition(530,800-32);


    spriteBunnyHead.scale(1.5,1.5);
    spriteBunnyHead.setPosition(420,800-32);

    spritePlay.setPosition(400,800);
    spritePause.setPosition(400,800);

    spriteRamka.setTexture(_texturki->ramka);
    spriteRamka.setPosition(12,800);

    legenda.setSize(sf::Vector2f(800,40));
    legenda.setFillColor(sf::Color(170,75,0));//ustawia kolor legendy na braz
    legenda.setPosition(0,800);
    spriteRamka.scale(1.1,1.1);
    //ctor
}
void mapa::drawMap(sf::RenderWindow * window,float odl,bool akt,float fps)//poprawic by bylo bez odl
{


            sprite.setPosition(0,0);
        for(int i=0;i<25;i++)
        {
            sprite.setPosition(0,i*odl);
            for(int j=0;j<25;j++)
            {

            window->draw(sprite);
            sprite.move(odl,0);
            }
        }

          for(int i=0;i<totalnaIloscKrolikow;i++)
          {
           //   cout<<"poz:"<<rabits[i]->x<<rabits[i]->y<<endl;
              spriteKrolik.setPosition(rabits[i]->y*odl,rabits[i]->x*odl);
               spriteKrolik.setTextureRect(sf::IntRect(rabits[i]->getFlipX()==1?0:32,rabits[i]->klatka*32,32*rabits[i]->getFlipX(),32));
               window->draw(spriteKrolik);
               rabits[i]->aktAnim(fps);

          }
          int wolfKills=0;
          int indBestWolf=-1;
          iloscWilczyc=0;
                    for(int i=0;i<totalnaIloscWilkow;i++)
          {

              if(wolfs[i]->kills>wolfKills){wolfKills=wolfs[i]->kills;indBestWolf=i;}
              spriteWilk.setPosition(wolfs[i]->y*odl,wolfs[i]->x*odl);
              spriteWilczyca.setPosition(wolfs[i]->y*odl,wolfs[i]->x*odl);
             if(wolfs[i]->facet){ spriteWilk.setTextureRect(sf::IntRect(wolfs[i]->getFlipX()==1?0:64,wolfs[i]->klatka*64,64*wolfs[i]->getFlipX(),64));window->draw(spriteWilk);wolfs[i]->aktAnim(fps);}
             else{iloscWilczyc++;spriteWilczyca.setTextureRect(sf::IntRect(wolfs[i]->getFlipX()==1?0:64,wolfs[i]->klatka*64,64*wolfs[i]->getFlipX(),64));window->draw(spriteWilczyca);wolfs[i]->aktAnim(fps);}
          }
            if(indBestWolf!=-1)
            {
                spriteKoronki.setPosition(wolfs[indBestWolf]->y*odl,wolfs[indBestWolf]->x*odl);
                spriteKoronki.setTextureRect(sf::IntRect(wolfs[indBestWolf]->getFlipX()==1?0:64,wolfs[indBestWolf]->klatka*64,64*wolfs[indBestWolf]->getFlipX(),64));window->draw(spriteKoronki);koronka.aktAnim(fps);

            }
          for(int i=0;i<25;i++)
          {
              for(int j=0;j<25;j++)
              {
                  if(mapaTekstowa[i][j]=='B')
                  {
                      spriteKrzaki.setPosition(j*odl,i*odl);
                      window->draw(spriteKrzaki);

                  }
              }
          }
          //myszka
           sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
           int iodl=odl;
           spritePoleKursora.setPosition((localPosition.x/iodl)*iodl,(localPosition.y/iodl)*iodl);
           mouseX=localPosition.x/iodl;
           mouseY=localPosition.y/iodl;

           window->draw(spritePoleKursora);
                    //legenda-----------------------------------------------------------------------------
                    window->draw(legenda);


                    textLegendy.setString(to_string(totalnaIloscWilkow-iloscWilczyc));
                    textLegendy.setPosition(700,800);
                    window->draw(spriteWolfManHead);
                    window->draw(textLegendy);

                    textLegendy.setString(to_string(iloscWilczyc));
                    textLegendy.setPosition(600,800);
                    window->draw(spriteWolfWomanHead);
                    window->draw(textLegendy);

                    textLegendy.setString(to_string(totalnaIloscKrolikow));
                    textLegendy.setPosition(500,800);
                    window->draw(spriteBunnyHead);
                    window->draw(textLegendy);
                    //rysowanie ui do wyboru tworzenia obiektu ------------------------------------------------------------------------------
                    spriteKrolik.setPosition(16,800);
                    window->draw(spriteKrolik);
                    textLegendy.setCharacterSize(16);
                    textLegendy.setString(to_string(1));
                    textLegendy.setPosition(32,816);
                    window->draw(textLegendy);

                    spriteWilk.setPosition(64,800);
                    window->draw(spriteWilk);
                    textLegendy.setString(to_string(2));
                    textLegendy.setPosition(64+16,816);
                    window->draw(textLegendy);

                    spriteWilczyca.setPosition(96+16,800);
                    window->draw(spriteWilczyca);
                    textLegendy.setString(to_string(3));
                    textLegendy.setPosition(128,816);
                    window->draw(textLegendy);

                    spriteKrzaki.setPosition(96+64,800);
                    window->draw(spriteKrzaki);
                    textLegendy.setString(to_string(4));
                    textLegendy.setPosition(128+40,816);
                    window->draw(textLegendy);
                    textLegendy.setCharacterSize(32);
            window->draw(spriteRamka);
            if(!akt){window->draw(spritePlay);return;}

            window->draw(spritePause);

//jezeli spacja byla nacisnieta ---------------------------------------------------------------------------------------------------------
           for(int i=0;i<totalnaIloscKrolikow;i++)
          {
           rabits[i]->ruch(mapaTekstowa,rabits,&totalnaIloscKrolikow,mapaTekstowaNextTurn,maxIloscKrolkow);

          }
            for(int i=0;i<totalnaIloscWilkow;i++)
          {
       if(!wolfs[i]->facet)   wolfs[i]->ruch(mapaTekstowa,wolfs,rabits,&totalnaIloscKrolikow,&totalnaIloscWilkow,mapaTekstowaNextTurn);

          }
                    for(int i=0;i<totalnaIloscWilkow;i++)
          {
       if(wolfs[i]->facet)   wolfs[i]->ruch(mapaTekstowa,wolfs,rabits,&totalnaIloscKrolikow,&totalnaIloscWilkow,mapaTekstowaNextTurn);

          }



        //tekst by sprawdzac na biezaco
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {

              cout<<mapaTekstowa [i][j];

            }
            cout<<endl;
        }

        int pole[25][25];

        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++){pole[i][j]=0;}
        }
        for(int i=0;i<totalnaIloscKrolikow;i++)
        {
            pole[rabits[i]->x][rabits[i]->y]++;
        }

        cout<<"ilosc krolikow:"<<totalnaIloscKrolikow<<endl;
         cout<<"ilosc wilkow:"<<totalnaIloscWilkow<<endl;
}
void mapa::setRabit(int x,int y,Texturki * texturki)
{
    if(x<25 && x>=0 && y<25 && y>=0 && totalnaIloscKrolikow<maxIloscKrolkow)
    {

    rabits[totalnaIloscKrolikow]=new krolik(x,y,'k',mapaTekstowa,texturki,5);
      totalnaIloscKrolikow++;

    }
    else if(x<25 && x>=0 && y<25 && y>=0)
    {
         cout<<"przekracza maksymalna ilosc!"<<endl;
    }
    else
    {
        cout<<"poza mape wspolrzedne"<<endl;
    }
}
void mapa::setWolf(int x,int y,Texturki * texturki,double _fat,bool _facet)
{
    if(x<25 && x>=0 && y<25 && y>=0 && totalnaIloscWilkow<maxIloscWilkow)
    {

    wolfs[totalnaIloscWilkow]=new wilk(x,y,mapaTekstowa,texturki,_fat,_facet,5);
      totalnaIloscWilkow++;

    }
        else if(x<25 && x>=0 && y<25 && y>=0)
    {
         cout<<"przekracza maksymalna ilosc!"<<endl;
    }
    else
    {
        cout<<"poza mape wspolrzedne"<<endl;
    }
}

void mapa::changeSelect(int newSelect)
{
    select=newSelect;
         spriteRamka.setPosition(12+48*(newSelect-1),800);

}
void mapa::setObject()
{

    if(select==1)//kroliki
    {
        setRabit(mouseY,mouseX,texturki);

    }
    if(select==2)//wilk samiec
    {
        setWolf(mouseY,mouseX,texturki,2,true);

    }
    if(select==3)//wilk samica
    {

        setWolf(mouseY,mouseX,texturki,2,false);

    }
    if(select==4)//krzaki(obszar zakazany)
    {
        mapaTekstowa[mouseY][mouseX]='B';//krzaki (bush)

    }
}

mapa::~mapa()
{
    for(int i=0;i<totalnaIloscKrolikow;i++)
    {
        delete rabits[i];
    }
    delete [] rabits;
        for(int i=0;i<totalnaIloscWilkow;i++)
    {
        delete wolfs[i];
    }
    delete [] wolfs;

}
