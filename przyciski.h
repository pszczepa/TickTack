#ifndef PRZYCISKI_H
#define PRZYCISKI_H

#include <QMainWindow>
#include <QPicture>

class Przyciski
{
    QImage _X;
    QImage _O;

    bool  _x_stan;
    bool  _o_stan;


public:
    Przyciski();
    Przyciski(bool);

    QImage xReturn();
    QImage oReturn();
};

#endif // PRZYCISKI_H
