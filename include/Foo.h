#ifndef FOO_H
#define FOO_H
#include "Animal.h"

class Foo : public  Animal
{
    public:
        Foo();
        void  ruch();
        virtual ~Foo();

    protected:

    private:
};

#endif // FOO_H
