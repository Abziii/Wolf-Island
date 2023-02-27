#include "Animal.h"
#include<iostream>
using namespace std;
Animal::Animal(int _maxKlatek)
{
    maxKlatek=_maxKlatek;
             klatka=0;
         sekunda=0;
    //ctor
}
Animal::Animal()
{

    //ctor
}
void  Animal::aktAnim(float deltaTime)
{

        if(sekunda>0.16)
        {
                    klatka++;
        klatka=klatka%maxKlatek;
        sekunda=0;
        }
        else
        {
            sekunda+=deltaTime;
        }
}
    int Animal::getFlipX()
    {
        return FlipX;
    }
Animal::~Animal()
{
    //dtor
}
