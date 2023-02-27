#include "Texturki.h"
#include<iostream>
using namespace std;
Texturki::Texturki()
{
    //ctor
}
Texturki::Texturki(std::string sciezka)
{
  //  cout<<  (this->mapa.loadFromFile(sciezka+"trawa.png")?"udalo sie wczytac teksture!":"nope")<<endl;
    this->mapa.loadFromFile(sciezka+"trawa.png");
    this->krolik.loadFromFile(sciezka+"krolik.png");
    this->wilk.loadFromFile(sciezka+"wilk.png");
    this->wilczyca.loadFromFile(sciezka+"wilczyca.png");
    this->poleKursora.loadFromFile(sciezka+"pole.png");
    this->krzaki.loadFromFile(sciezka+"Krzaki.png");
    this->korona.loadFromFile(sciezka+"korona.png");
    this->bunnyHead.loadFromFile(sciezka+"bunny head.png");
    this->wolfManHead.loadFromFile(sciezka+"wolf man head.png");
    this->wolfWomanHead.loadFromFile(sciezka+"wolf woman head.png");
    this->adventureFont.loadFromFile(sciezka+"Adventurer.ttf");
    this->play.loadFromFile(sciezka+"Play.png");
    this->pause.loadFromFile(sciezka+"Stop.png");
    this->ramka.loadFromFile(sciezka+"ramka.png");
}

Texturki::~Texturki()
{
    //dtor
}
