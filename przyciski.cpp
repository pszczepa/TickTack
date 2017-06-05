#include "przyciski.h"

Przyciski::Przyciski()
{
    _krzyzyk.load("x.jpg", nullptr);
    _kolko.load("o.jpg", nullptr);
}

QPicture Przyciski::xReturn()
{
    return _krzyzyk;
}

QPicture Przyciski::oReturn()
{
    return _kolko;
}
