#ifndef MAPA_H
#define MAPA_H
#include <SFML/Graphics.hpp>
#include"krolik.h"
#include"wilk.h"
#include"Texturki.h"
class mapa
{
    public:
        char mapaTekstowa[25][25];

        char mapaTekstowaNextTurn[25][25];
        mapa(Texturki * textura_mapy,int _maxIloscWilkow,int _maxIloscKrolkow);
        virtual ~mapa();
        void drawMap(sf::RenderWindow * window,float odl,bool akt,float fps);

        void setRabit(int x,int y,Texturki * textura_mapy);
        void setWolf(int x,int y,Texturki * textura_mapy,double _fat,bool _facet=false);
        //do krolikow
        int totalnaIloscKrolikow;
        krolik ** rabits;//wzkaznik do wzkaznikow krolikow
        //do wilkow
        int totalnaIloscWilkow;
        wilk ** wolfs;

        // do ui
        void changeSelect(int newSelect);
        void setObject();
        Animal koronka=Animal(5);//po to by by³a animacja
    protected:

    private:

        Texturki *texturki;
         sf::Sprite sprite;
         sf::Sprite spriteKrolik;
         sf::Sprite spriteWilk;
         sf::Sprite spriteWilczyca;
         sf::Sprite spritePoleKursora;
         sf::Sprite spriteKrzaki;
         sf::Sprite spriteKoronki;
         sf::Sprite spriteBunnyHead;
         sf::Sprite spriteWolfManHead;
         sf::Sprite spriteWolfWomanHead;

         sf::Sprite spritePlay;
         sf::Sprite spritePause;

         sf::Sprite spriteRamka;
         sf::RectangleShape legenda;
         sf::Text textLegendy;
        int maxIloscWilkow;
        int maxIloscKrolkow;
        int iloscWilczyc;
         // do ui
         int select;
         //myszka w ukladzie mapy(tablicowej)
         int mouseX;
         int mouseY;
};

#endif // MAPA_H
