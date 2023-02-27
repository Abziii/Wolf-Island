#ifndef ANIMAL_H
#define ANIMAL_H
#include <SFML/Graphics.hpp>

class Animal
{
    public:
          int x;int y;//aktualna pozycja
              int next_x;int next_y;//planowany ruch (pozycja) (zrobic strukture vector 2?)
                  char symbol;
     sf::Sprite sprite;
     sf::Texture textura;
        Animal(int _maxKlatek);
        Animal();
         int klatka;
        void aktAnim(float deltaTime);
        virtual ~Animal();
            int getFlipX();

    protected:
        int maxKlatek;
        float sekunda;
        int FlipX;
    private:
};

#endif // ANIMAL_H
