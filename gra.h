#ifndef GRA_H
#define GRA_H

#include "tura.h"

class Gra
{

    /*
     * Zmienna przechowuje wartość stanu gry.
     *
     */
    bool _czyStart;

    /*
     *
     */
    bool _czyKoniec;


    bool _ktoWygral;

    const int _KOLKO    = 1;
    const int _KRZYZYK  = 2;
    const int _PUSTE    = 0;

    int _plansza[3][3];

    Tura _tura;


public:
    Gra();

    void RozpocznijGre();

    void ZakonczGre();

    bool ZwrocWynik();

    bool Wypelnij(int const );
};

#endif // GRA_H
