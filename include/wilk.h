#ifndef WILK_H
#define WILK_H
#include"krolik.h"
#include<SFML/Graphics.hpp>
class wilk:public Animal
{
    public:


    double fat;//poziom tluszczu
    bool facet;//by rozpoznac czy to samica czy samiec

    int kills;//jak duzo zjadl wilk

     Texturki *texturka;

    wilk(int _x,int _y,char _mapa[][25] ,Texturki * texturki,double _fat,bool _facet,int _maxKlatek);

    void ruch(char _mapa[][25],wilk ** wolfW,krolik **rabits,int * totalnaIloscKrolikow,int * totalnaIloscWilkow,char nextTurnMap[][25]);
        virtual ~wilk();


    protected:
        bool checkWolnePole(char _mapa[][25],int * totalnaIloscWilkow);
        bool checkIfPathfIsBlocked(char _mapa[][25]);
         void zjadanieKrolika(krolik **rabits,int * totalnaIloscKrolikow,char nextTurnMap[][25]);
           void umieranie(wilk ** wolfW,int * totalnaIloscWilkow);

    private:

        void rozmnoz(char _mapa[][25],wilk ** wolfW,int * totalnaIloscWilkow);

};

#endif // WILK_H
