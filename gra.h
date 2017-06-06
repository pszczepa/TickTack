#ifndef GRA_H
#define GRA_H

#include "tura.h"

class Gra
{

    bool _czyStart;

    bool _czyKoniec;

    bool _ktoWygral;

    bool _czyPvC;

    int _poziomTrudnosci;

    const int _KOLKO    = 1;
    const int _KRZYZYK  = 2;
    const int _PUSTE    = 0;

    int _plansza[3][3];

    Tura _tura;


public:
    Gra();

    void UstawPoziomTrudnosci(int const);

    void RozpocznijGre(bool);

    void ZakonczGre();

    bool ZwrocWynik();

    bool Wypelnij(int const , int const);

    int ReturnPoziom();

};

#endif // GRA_H
