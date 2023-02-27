#ifndef TEXTURKI_H
#define TEXTURKI_H
#include<SFML/Graphics.hpp>
#include<string>
class Texturki
{
    public:
        sf::Texture wilk;
        sf::Texture wilczyca;
        sf::Texture krolik;
        sf::Texture mapa;
        sf::Texture poleKursora;
        sf::Texture krzaki;
        sf::Texture korona;
        sf::Texture bunnyHead;
        sf::Texture wolfManHead;
        sf::Texture wolfWomanHead;
        sf::Font adventureFont;

        sf::Texture pause;
        sf::Texture play;
        sf::Texture ramka;

        Texturki();

        Texturki(std::string sciezka);
        virtual ~Texturki();

    protected:

    private:
};

#endif // TEXTURKI_H
