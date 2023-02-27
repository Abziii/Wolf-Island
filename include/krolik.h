#ifndef KROLIK_H
#define KROLIK_H
#include <SFML/Graphics.hpp>
#include"Texturki.h"
#include"Animal.h"
class krolik:public Animal
{
    public:


        krolik();
        krolik(int _x,int _y,char _symbol,char _mapa[][25] ,Texturki * texturki,int _maxKlatek);
        krolik(int _x,int _y,char _symbol,char _mapa[][25] ,sf::Texture texturaKrolika,int _maxKlatek);/**jakas mape rozwiazac ale moze to pozniej**/
        void ruch(char _mapa[][25],krolik ** rabits,int * totalnaIloscKrolikow,char nextTurnMap[][25],int maxIloscKrolkow);
        virtual ~krolik();


    protected:
        bool checkWolnePole(char _mapa[][25],char nextTurnMap[][25]);
    private:
        int tura;
        void rozmnoz(char _mapa[][25],krolik ** rabits,int * totalnaIloscKrolikow,char nextTurnMap[][25],int maxIloscKrolkow);

        //flip w zaleznosci gdzie krolk idzie
};

#endif // KROLIK_H
