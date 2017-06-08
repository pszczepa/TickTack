#ifndef GRA_H
#define GRA_H

#include "tura.h"
#include "przyciski.h"


/* przerobić na dziedziczenie */

class Gra
{

    bool _czyStart;

    bool _czyKoniec;

    bool _ktoWygral;

    bool _czyPvC;

    int _poziomTrudnosci;

    const int _KOLKO    = 1;
    const int _KRZYZYK  = -1;
    const int _PUSTE    = 0;

    int _plansza[3][3];





public:

    Gra();

    void UstawPoziomTrudnosci(int const);

    void RozpocznijGre(bool);

    void ZakonczGre();

    bool ZwrocWynik();

    bool Wypelnij(int const , int const);

    int ReturnPoziom();

    bool SprawdzCzyWygrana();

    Przyciski _przyciski;

    Tura _tura;

};

#endif // GRA_H
