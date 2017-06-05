#ifndef PRZYCISKI_H
#define PRZYCISKI_H

#include <QMainWindow>
#include <QPicture>

class Przyciski
{
    QPicture _krzyzyk;
    QPicture _kolko;


public:
    Przyciski();
    QPicture xReturn();
    QPicture oReturn();
};

#endif // PRZYCISKI_H
