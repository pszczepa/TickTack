#include "przyciski.h"

Przyciski::Przyciski()
{
   _x_stan = _X.load("x.jpg");
   _o_stan = _O.load("o.jpg");
}

Przyciski::Przyciski(bool inne)
{
   if(inne)
     {

     }
   else
     {
       Przyciski();
     }

}

QImage Przyciski::xReturn()
{
    return _X;
}

QImage Przyciski::oReturn()
{
    return _O;
}
