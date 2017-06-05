#ifndef GRA_H
#define GRA_H


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
    const int _KRZYRZYK = 2;
    const int _PUSTE    = 0;

    int _plansza[3][3];


public:
    Gra();

    void RozpocznijGre();

    void ZakonczGre();

    bool ZwrocWynik();
};

#endif // GRA_H
