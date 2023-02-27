#include <SFML/Graphics.hpp>
#include<iostream>
#include"Texturki.h"
#include"mapa.h"
using namespace std;

int main()
{
    float odl=32;
    //deltaTime------------------------------------
    float deltaTime=60;
    sf::Clock clock=sf::Clock();

    //---------------------------------------------
    sf::RenderWindow window(sf::VideoMode(800, 840), "Wyspa wilkowooooo");
    window.setFramerateLimit(60);//raczej nie musi byc
    Texturki texture("grafika//");
    mapa mapaGry(&texture,3000,1000);//pointer do texturki,max ilosc wilkow,max ilosc krolikow
    bool aktMap=false;
    while (window.isOpen())
    {
        bool oneTurn=false;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::Escape))
            {
                 window.close();
                 return 0;
            }

            if (event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::Space)
            {
                 aktMap=!aktMap;
            }
            if (event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::V)//przy v jest jedna tura
            {
                 oneTurn=true;
            }
            if(event.type==sf::Event::KeyPressed)
            {
                if(event.key.code==sf::Keyboard::Num1)//kroliki
                {
                    mapaGry.changeSelect(1);
                }

                if(event.key.code==sf::Keyboard::Num2)//wilk samiec
                {
                    mapaGry.changeSelect(2);
                }

                if(event.key.code==sf::Keyboard::Num3)//wilk samica
                {
                    mapaGry.changeSelect(3);
                }
                if(event.key.code==sf::Keyboard::Num4)//krzaki(obszar zakazany)
                {
                    mapaGry.changeSelect(4);
                }
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
             //   cout<<"proba postawienia"<<endl;
                mapaGry.setObject();

            }

        }

        window.clear();
      mapaGry.drawMap(&window,odl,(aktMap || oneTurn),deltaTime);
        window.display();
      //liczenie deltaTime----------------------------------------

        deltaTime =clock.restart().asSeconds();

     //   cout<<deltaTime<<" deltaTime "<<endl;
    }

    return 0;
}
















/*
#include <SFML/Graphics.hpp>
#include<iostream>
#include"Texturki.h"
using namespace std;
int main()
{
cout<<"b"<<endl;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Wyspa wilkowooooo");
   // Texturki texture("grafika//");
    sf::Sprite mapa;
    //mapa.setScale(800/(20*24),800/(20*24));
   // mapa.setTexture(texture.mapa);

    while (window.isOpen())
    {
        cout<<"a"<<endl;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code==sf::Keyboard::Escape)
                window.close();
        }

        window.clear();
        mapa.setPosition(0,0);
        for(int i=0;i<20;i++)
        {
            mapa.setPosition(0,i*24);
            for(int j=0;j<20;j++)
            {

           // window.draw(mapa);
            mapa.move(24,0);
            }
        }

        window.display();
    }

    return 0;
}
*/
