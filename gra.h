#ifndef GRA_H
#define GRA_H

#include <iostream>

#include "tura.h"
#include "przyciski.h"


class Gra : public Tura, public Przyciski
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

    bool ReturnPvC();

    void DrukujPlansze();

    int ReturnPlansza(int, int);

    void UstawPvC(bool);

};

#endif // GRA_H
